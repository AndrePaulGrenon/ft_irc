#include "../Servers.hpp"

int     Servers::Topic(Users &user, Parser &parser) //dummy message for the moment will need to find the good ones
{
    switch (this->chanMap.size())
	{
		case 0:
			std::cout << "No channel exist" << std::endl;
			break;
		case 1:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end())
				std::cout << this->chanMap.at(parser.getArgs().at(0)).getTopic() << std::endl; //juste print le topic pour le moment 
		case 2:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end())
				

	}

    return (0);
}