#include "../Servers.hpp"

/* bool	ft_is_empty_string(std::string msg)
{
	for (size_t i = 0; i < msg.size(); i++)
	{
		if (msg[i] != ' ' && msg[i] != '\r' && msg[i] != '\n' && msg[i] != ':')
			return false;
	}
	return true;
} */

int	Servers::Notice(Users &user, Parser &parser)
{
	/* if (ft_is_empty_string(parser.getMessage()))
	{
				send(user.getFd(), parser.SendReply("412", "", "No message to send!\n"), parser.getReply().size(), 0);
				//_close_connection = true;
				return (1);
	}
	if (parser.getArgs()[0].size() == 0)
	{
				send(user.getFd(), parser.SendReply("411", "", "No recipient has been given!\n"), parser.getReply().size(), 0);
				//_close_connection = true;
				return (1);
	} */
	if (parser.getArgs()[0][0] == '#')
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