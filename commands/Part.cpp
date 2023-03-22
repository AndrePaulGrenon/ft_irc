#include "../Servers.hpp"

bool	is_part_of_chan()
{

}

int	Servers::Part(Users &user, Parser &parser)
{
	std::vector<std::string> clist(parser.SplitComa(parser.getArgs()[0]));
	for (size_t i = 0; i < clist.size(); i++)
	{
		std::map<std::string, Channels>::iterator	it = Chans.find(clist[i]);
		if (it == Chans.end())
		{
			send(user.getFd(), parser.SendReply("403", parser.getArgs()[i], "Channel inexistant\n"), parser.getReply().size(), 0);
			//_close_connection = true;
			//return (1);
		}
		else if ((it->second.getFlag(4) == true &&  /*|| If moderate and banned*/)
		{
			send(user.getFd(), parser.SendReply("404", parser.getArgs()[0], "You don't have access to the channel\n"), parser.getReply().size(), 0);
			_close_connection = true;
			//return (1);
		}
		else
		{
			for (size_t j = 0; j < it->second.getUsers().size(); j++)
			{
				if (it->second.getUsers()[j].getAway() == true)
					send(user.getFd(), parser.SendReply("301", it->second.getUsers()[j].getNickname(), it->second.getUsers()[j].getAwayMsg()), parser.getReply().size(), 0);
				else
					send(it->second.getUsers()[j].getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
			}
		}
	}
	return (0);
}