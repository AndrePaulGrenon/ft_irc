#include "../Servers.hpp"

int	Servers::Notice(Users &user, Parser &parser)
{
	if (parser.getArgs()[0][0] == '#' || parser.getArgs()[0][0] == '&')
	{
		std::map<std::string, Channels>::iterator it = Chans.find(parser.getArgs()[0]);
		for (size_t j = 0; j < it->second.getUsers().size(); j++)
				send(it->second.getUsers()[j].getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
	}
	else
			send(userPointer.find(parser.getArgs()[0])->second->getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
	send(user.getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
	return (0);
}