#include "../Servers.hpp"

int	Servers::Pong(Users &user, Parser &parser)
{
	user.setActive(true);
	(void)parser;
	return (0);
}