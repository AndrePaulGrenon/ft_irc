#include "../Servers.hpp"


int	Servers::Away(Users &user, Parser &parser)
{
	if (parser.getArgs().size() == 0)
	{
		if (user.getAway() == true)
			user.setAway(false);
	}
	else
	{
		std::string msg;
		for (size_t i = 0; i < parser.getArgs().size(); i++)
		{
			msg.append(parser.getArgs()[i]);
			if (i != parser.getArgs().size() - 1)
			{
				msg.append(" ");
			}
		}
		if (user.getAway() == false)
			user.setAway(true);
		user.setAwayMsg(msg);
	}
	return (0);
}