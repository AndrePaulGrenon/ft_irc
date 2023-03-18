#include "../Servers.hpp"

int	Servers::Quit(Users &user, Parser &parser)
{
	_close_connection = true;
	send(user.getFd(), parser.SendReply("", parser.getArgs()[0], "Exited gracefully\n"), sizeof(parser.getReply()), 0);
	DeleteUsers(user);
	return (1);
}