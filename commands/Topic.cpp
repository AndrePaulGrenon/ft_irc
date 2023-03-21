#include "../Servers.hpp"

int     Servers::Topic(Users &user, Parser &parser)
{
    switch (this->chanMap.size()){
		case 0:
			send(user.getFd(), parser.SendReply("461", parser.getCommand(), "Not enough parameters"), parser.getReply().size(), 0); 
			break;
		case 1:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end())
				if (this->chanMap.at(parser.getArgs().at(0)).getTopic().empty() == false)
					send(user.getFd(), parser.SendReply("332", this->chanMap.at(parser.getArgs().at(0)).getName(), this->chanMap.at(parser.getArgs().at(0)).getTopic()), parser.getReply().size(), 0);
				else
					send(user.getFd(), parser.SendReply("331", this->chanMap.at(parser.getArgs().at(0)).getName(), "No topic is set"), parser.getReply().size(), 0);
			else 
				send(user.getFd(), parser.SendReply("403", parser.getArgs().at(0), "No such channel"), parser.getReply().size(), 0);  
			break; 
		default:
			if (this->chanMap.find(parser.getArgs().at(0)) != this->chanMap.end()){
				if ((this->chanMap.at(parser.getArgs().at(0)).getFlag(3)) == 0){
					string topic = parser.getArgs().at(1);
					for (size_t i = 2; i < parser.getArgs().size(); i++)
						topic += parser.getArgs().at(i);	
					this->chanMap.at(parser.getArgs().at(0)).setTopic(topic);
					send(user.getFd(), parser.SendReply("482", user.getNickname() + " has set topic", parser.getArgs().at(1)), parser.getReply().size(), 0);
				}
				else
					if (this->chanMap.at(parser.getArgs().at(0)).getOp(user.getNickname()) == true){
						string topic = parser.getArgs().at(1);
						for (size_t i = 2; i < parser.getArgs().size(); i++)
						topic += parser.getArgs().at(i);	
						this->chanMap.at(parser.getArgs().at(0)).setTopic(topic);
						send(user.getFd(), parser.SendReply("482", user.getNickname() + " has set topic", parser.getArgs().at(1)), parser.getReply().size(), 0);
					}
					else
						send(user.getFd(), parser.SendReply("482", this->chanMap.at(parser.getArgs().at(0)).getName(), "You're not channel operator"), parser.getReply().size(), 0);
			}
			else 
				send(user.getFd(), parser.SendReply("403", parser.getArgs().at(0), "No such channel"), parser.getReply().size(), 0);
			break;

	}

    return (0);
}