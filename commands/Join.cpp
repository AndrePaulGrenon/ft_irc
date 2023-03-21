#include "../Servers.hpp"

int     Servers::Join(Users &user, Parser &parser){
	if (this->Chans.empty())
	{
		Channels test("test");
		this->Chans.insert(std::pair<std::string, Channels>("test", test));
		this->Chans.at("test").setOp(user.getNickname(), true);
		this->Chans.at("test").addUser(user);
	}
	else{
		this->Chans.at("test").addUser(user);
	}
	/* switch (parser.getArgs().size())
	{
	case 1: //only channel no password
		this->Chans.at(this->Chans.find(parser.getArgs().at))
		break;
	case 2: //check if passwords are used
		break;
	default:
		break;
	} */
	(void) parser;
	return (0);
}
