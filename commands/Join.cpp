#include "../Servers.hpp"

int     Servers::Join(Users &user, Parser &parser){
	switch (parser.getArgs().size())
	{
	case 1: //only channel no password
		
		break;
	case 2: //check if passwords are used
		break;
	default:
		break;
	}
}
