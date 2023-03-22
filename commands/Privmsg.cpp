#include "../Servers.hpp"

bool	ft_is_empty_string(std::string msg)
{
	for (size_t i = 0; i < msg.size(); i++)
	{
		if (msg[i] != ' ' && msg[i] != '\r' && msg[i] != '\n' && msg[i] != ':')
			return false;
	}
	return true;
}

// If sender is on the channel, make sure he doesn't get the message twice
int	Servers::Privmsg(Users &user, Parser &parser)
{
	parser.PrintElements();
	if (ft_is_empty_string(parser.getMessage()))
	{
				send(user.getFd(), parser.SendReply("412", "", "No message to send!\n"), parser.getReply().size(), 0);
				//_close_connection = true;
				return (1);
	}
	if (parser.getArgs().size() == 0)
	{
				send(user.getFd(), parser.SendReply("411", "", "No recipient has been given!\n"), parser.getReply().size(), 0);
				//_close_connection = true;
				return (1);
	}
	if (parser.getArgs()[0][0] == '#')
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
			else if ((it->second.getFlag(4) == true /*&& not part of the channel*/)  /*|| If moderate and banned*/)
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
	}
	else
	{
		std::vector<std::string> ulist(parser.SplitComa(parser.getArgs()[0]));
		for (size_t i = 0; i < ulist.size(); i++)
		{
			if (userPointer.find(ulist[i]) == userPointer.end())
			{
				send(user.getFd(), parser.SendReply("401", parser.getArgs()[i], "User you try to communicate with doesn't exists\n"), parser.getReply().size(), 0);
				//_close_connection = true;
				//return (1);
			}
		}
		std::map<std::string, Users*>::iterator it;
		for (size_t j = 0; j < ulist.size(); j++)
		{
			it = userPointer.find(ulist[j]);
			if (it->second->getAway() == true)
				send(user.getFd(), parser.SendReply("301", it->second->getNickname(), it->second->getAwayMsg()), parser.getReply().size(), 0);
			else
				send(it->second->getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
		}
		send(user.getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
	}
	return (0);
}