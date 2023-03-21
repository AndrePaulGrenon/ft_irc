#include "../Servers.hpp"

int	Servers::Privmsg(Users &user, Parser &parser)
{
	if (parser.getMessage().size() == 0)
	{
				send(user.getFd(), parser.SendReply("412", "", "No message to send!\n"), parser.getReply().size(), 0);
				_close_connection = true;
				return (1);
	}
	if (parser.getArgs()[0].size() == 0)
	{
				send(user.getFd(), parser.SendReply("411", "", "No recipient has been given!\n"), parser.getReply().size(), 0);
				_close_connection = true;
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
		for (size_t i = 0; i < (parser.getArgs().size()); i++)
		{
			if (userPointer.find(parser.getArgs()[i]) == userPointer.end())
			{
				send(user.getFd(), parser.SendReply("401", parser.getArgs()[i], "User you try to communicate with doesn't exists\n"), parser.getReply().size(), 0);
				_close_connection = true;
				return (1);
			}
		}
		for (size_t i = 0; i < (parser.getArgs().size()); i++)
		{
			send(userPointer.find(parser.getArgs()[i])->second->getFd(), parser.SendReply("", user.getNickname(), parser.getMessage()), parser.getReply().size(), 0);
		}
	}
	return (0);
}