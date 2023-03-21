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
	/* if (parser.getArgs()[0][0] == '#')
	{
		if (user.getChans().find(parser.getArgs()[0]) == user.getChans().npos)
		{
			send(user.getFd(), parser.SendReply("404", parser.getArgs()[0], "You don't have access to the channel\n"), parser.getReply().size(), 0);
            _close_connection = true;
            return (1);
		}
		else if (Chans.find(parser.getArgs()[0]) == Chans.end())
		{
			send(user.getFd(), parser.SendReply("403", parser.getArgs()[0], "Channel inexistant\n"), parser.getReply().size(), 0);
            _close_connection = true;
            return (1);
		}
		else
		{
			// find user in channel and dispatch message
		}
	} */
	else
	{
		std::vector<std::string> ulist(parser.SplitComa(parser.getArgs()[0]));
		for (size_t i = 0; i < ulist.size(); i++)
		{
			if (userPointer.find(ulist[i]) == userPointer.end())
			{
				send(user.getFd(), parser.SendReply("401", parser.getArgs()[i], "User you try to communicate with doesn't exists\n"), parser.getReply().size(), 0);
				//_close_connection = true;
				return (1);
			}
		}
		for (size_t i = 0; i < ulist.size(); i++)
		{
			send(userPointer.find(ulist[i])->second->getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
		}
		send(user.getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
	}
	return (0);
}