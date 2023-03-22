#include "../Servers.hpp"

int	Servers::Ping(Users &user, Parser &parser)
{
	user.setActive(false);
	(void) parser;
	return (0);
}