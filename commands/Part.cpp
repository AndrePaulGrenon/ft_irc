#include "../Servers.hpp"

int	Servers::Part(Users &user, Parser &parser)
{
	if (parser.getArgs().size() == 0)
	{
		send(user.getFd(), parser.SendReply("461", parser.getCommand(), "No Channels were given"), parser.getReply().size(), 0);
		return (1);
	}
	std::vector<std::string> clist(parser.SplitComa(parser.getArgs()[0]));
	for (size_t i = 0; i < clist.size(); i++)
	{
		std::map<std::string, Channels>::iterator	it = Chans.find(clist[i]);
		if (it == Chans.end())
			send(user.getFd(), parser.SendReply("403", parser.getArgs()[i], "non-existant Channel"), parser.getReply().size(), 0);
		else if ((it->second.getFlag(4) == true && user.getChannels().find(it->second.getName()) != user.getChannels().end())) /*|| If moderate and banned*/
			send(user.getFd(), parser.SendReply("442", parser.getArgs()[0], "You don't have access to the channel"), parser.getReply().size(), 0);
		else
		{
			user.removeChannel(it->second.getName());
			it->second.RemoveUser(user.getNickname());
			if (it->second.getUsers().size() == 0)
				Chans.erase(it);
		}
	}
	return (0);
}