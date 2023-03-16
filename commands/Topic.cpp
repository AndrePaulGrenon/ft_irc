#include "../Servers.hpp"

int     Servers::Topic(Users &user, Parser &parser) //dummy message for the moment will need to find the good ones
{
    switch (this->chanMap.size()){
		case 0:
			std::cout << "No channel exist" << std::endl;
			break;
		case 1:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end())
				std::cout << this->chanMap.at(parser.getArgs().at(0)).getTopic() << std::endl; //juste print le topic pour le moment
			else 
				std::cout << "error channel doesnt exist" << std::endl;
			break; 
		default:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end()){
				if ((this->chanMap.at(parser.getArgs().at(0)).getFlag(T)) == 0){
					string topic = parser.getArgs().at(1);
					for (size_t i = 2; i < parser.getArgs().size(); i++)
						topic += parser.getArgs().at(i);	
					this->chanMap.at(parser.getArgs().at(0)).setTopic(topic);
				}
				else
					if (this->chanMap.at(parser.getArgs().at(0)).getOp(user) == true){
						string topic = parser.getArgs().at(1);
						for (size_t i = 2; i < parser.getArgs().size(); i++)
						topic += parser.getArgs().at(i);	
					this->chanMap.at(parser.getArgs().at(0)).setTopic(topic);
					}
					else
						send(user.getFd(), parser.SendReply("482", this->chanMap.at(parser.getArgs().at(0)).getName(), "You're not channel operator"), , 0);
			}
			break;

	}

    return (0);
}