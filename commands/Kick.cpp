#include "../Servers.hpp"

int	Servers::Kick(Users &user, Parser &parser)
{
	std::map<std::string, Channels>::iterator	it = Chans.find(parser.getArgs()[0]);
	if (parser.getArgs().size() < 2)
	{
		if (it == Chans.end())
			send(user.getFd(), parser.SendReply("461", parser.getCommand(), "No Channel was given"), parser.getReply().size(), 0);
		if (userPointer.find(parser.getArgs()[0]) == userPointer.end())
			send(user.getFd(), parser.SendReply("461", parser.getCommand(), "No user was given"), parser.getReply().size(), 0);
		return (1);
	}
	if (Chans.find(parser.getArgs()[0]) == Chans.end())
	{
		send(user.getFd(), parser.SendReply("403", parser.getArgs()[0], "Non-existant channel"), parser.getReply().size(), 0);
		return (1);
	}
	//Doit voir si le user to be kicked est sur le channel
	if (user.getChannels().find(it->second.getName()) == user.getChannels().end())
	{
		send(user.getFd(), parser.SendReply("442", "", "User already not on channel"), parser.getReply().size(), 0);
		return (1);
	}
	if (!it->second.getOp(user.getNickname()))
	{
		send(user.getFd(), parser.SendReply("482", parser.getArgs()[0], "You do not have the privileges to kick somebody out of the channel"), parser.getReply().size(), 0);
		return (1);
	}
	// Kick user of channel
	return (0);
}