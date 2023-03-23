#include "../Servers.hpp"

/*		   o - give/take channel operator privileges;
           p - private channel flag;
           s - secret channel flag;
           i - invite-only channel flag;
           t - topic settable by channel operator only flag;
           n - no messages to channel from clients on the outside;
           m - moderated channel;
           l - set the user limit to channel;
           b - set a ban mask to keep users out;
           v - give/take the ability to speak on a moderated channel;
           k - set a channel key (password). */

int	Servers::Mode(Users &user, Parser &parser)
{
	switch (le charactere dans la string) //pour plus
	{
		case 'o':
		break;
		case 'p':
		break;
		case 's':
		break;
		case 'i':
			this->Chans.at(parser.getArgs().at(0)).setFlag(I, true);
			break;
		case 't':
		break;
		case 'n':
		break;
		case 'm':
		break;
		case 'l':
		break;
		case 'b':
		break;
		case 'v':
		break;
		case 'k':
		break;
	default:
		send(user.getFd(),parser.SendReply("501", parser.getArgs().at(0), "Unknown MODE flag"), parser.getReply().size(), 0);
		break;
	}
	switch (le charactere dans la string) //pour moins
	{
		case 'o':
		break;
		case 'p':
		break;
		case 's':
		break;
		case 'i':
			this->Chans.at(parser.getArgs().at(0)).setFlag(I, false);
			break;
		case 't':
		break;
		case 'n':
		break;
		case 'm':
		break;
		case 'l':
		break;
		case 'b':
		break;
		case 'v':
		break;
		case 'k':
		break;
	default:
		send(user.getFd(),parser.SendReply("501", parser.getArgs().at(0), "Unknown MODE flag"), parser.getReply().size(), 0);
		break;
	}
	return (0);
}