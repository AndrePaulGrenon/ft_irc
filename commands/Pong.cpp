#include "../Servers.hpp"

int	Servers::Pong(Users &user, Parser &parser)
{

	send(user.getFd(), parser.SendReply("421", parser.getCommand(), 
			"This command doesn't exist"), parser.getReply().size(), 0);
	(void)user;
	(void)parser;
	return (0);
}