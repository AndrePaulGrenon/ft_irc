#include "../Servers.hpp"

int	Servers::Part(Users &user, Parser &parser)
{
	if (parser.getArgs()[0].size() == 0)
	{
		send(user.getFd(), parser.SendReply("461", parser.getCommand(), "No Channels were given"), parser.getReply().size(), 0);
		return (1);
	}
	std::vector<std::string> clist(parser.SplitComa(parser.getArgs()[0]));
	for (size_t i = 0; i < clist.size(); i++)
	{
		std::map<std::string, Channels>::iterator	it = Chans.find(clist[i]);
		if (it == Chans.end())
		{
			send(user.getFd(), parser.SendReply("403", parser.getArgs()[i], "non-existant Channel"), parser.getReply().size(), 0);
			//_close_connection = true;
			//return (1);
		}
		else if ((it->second.getFlag(4) == true && user.getChannels().find(it->second.getName()) != user.getChannels().end())) /*|| If moderate and banned*/
		{
			send(user.getFd(), parser.SendReply("442", parser.getArgs()[0], "You don't have access to the channel"), parser.getReply().size(), 0);
			//_close_connection = true;
			//return (1);
		}
		else
		{
			user.removeChannel(it->second.getName());
			for (std::vector<Users>::iterator vec_it = it->second.getUsers().begin(); vec_it != it->second.getUsers().end(); vec_it++)
			{
				if (vec_it->getNickname() == user.getNickname())
				{
					it->second.getUsers().erase(vec_it);
				}
			}
		}
	}
	return (0);
}