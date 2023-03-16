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
			break; 
		case 2:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end())
			{
				if ((this->chanMap.at(parser.getArgs().at(0)).getFlag(T)) == 0)
					this->chanMap.at(parser.getArgs().at(0)).setTopic(parser.getArgs().at(1));
				else
					if (this->chanMap.at(parser.getArgs().at(0)).getOp(user) == true)
						this->chanMap.at(parser.getArgs().at(0)).setTopic(parser.getArgs().at(1));
					else
						std::cout << this->
			}
			break;

	}

    return (0);
}