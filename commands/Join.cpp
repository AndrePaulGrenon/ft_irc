#include "../Servers.hpp"

int     Servers::Join(Users &user, Parser &parser){
	std::cout << "ok" << std::endl;
	if (this->Chans.empty())
	{
	std::cout << "ok" << std::endl;
		Channels test("test");
	std::cout << "ok" << std::endl;
		this->Chans.insert(std::pair<std::string, Channels>("test", test));
	std::cout << "ok" << std::endl;
		this->Chans.at("test").setOp(user.getNickname(), true);
	std::cout << "ok" << std::endl;
		this->Chans.at("test").addUser(user);
		std::cout << "channel created" << std::endl;
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
