#include "../Servers.hpp"

int     Servers::Join(Users &user, Parser &parser){
	switch (parser.getArgs().size())
	{
	case 1: //only channel no password
	{
		std::vector<std::string> channels = parser.SplitComa(parser.getArgs().at(0));
		for (size_t i = 0; i < channels.size(); i++){
			std::map<std::string, Channels>::iterator it = this->Chans.find(channels.at(i));
			if (it != this->Chans.end()){
				user.addChannel(it->second.getName());
				it->second.addUser(user, NULL, parser);
				it->second.setOp(user.getNickname(), false);
				send(user.getFd(), parser.SendReply("332", parser.getArgs().at(0), this->Chans.at(channels.at(i)).getTopic()), parser.getReply().size(), 0);
			}
			else{
				if (channels.at(i).size() <= 200 && channels.at(i).find(7, 0) == channels.at(i).npos && (channels.at(0).at(0) == '#' || channels.at(0).at(0) == '&')){
					Channels hold(channels.at(i));
					user.addChannel(it->second.getName());
					this->Chans.insert(std::pair<std::string, Channels>(channels.at(i), hold));
					this->Chans.at(channels.at(i)).addUser(user, NULL, parser); // va calisser un try catch ici pour les erreur dans adduser
					this->Chans.at(channels.at(i)).setOp(user.getNickname(), true);
					send(user.getFd(), parser.SendReply("332", parser.getArgs().at(0), this->Chans.at(channels.at(i)).getTopic()), parser.getReply().size(), 0);
				}
				else
					send(user.getFd(), parser.SendReply("403", parser.getArgs().at(0), "No such channel"), parser.getReply().size(), 0);
			}
		}
		break;
	}
	case 2: //check if passwords are used
	{
		std::vector<std::string> channels = parser.SplitComa(parser.getArgs().at(0));
		std::vector<std::string> password = parser.SplitComa(parser.getArgs().at(1));
		for (size_t i = 0; i < channels.size(); i++){
			std::map<std::string, Channels>::iterator it = this->Chans.find(channels.at(i));
			if (it != this->Chans.end()){
				user.addChannel(it->second.getName());
				it->second.addUser(user, NULL, parser);
				it->second.setOp(user.getNickname(), false);
				send(user.getFd(), parser.SendReply("332", parser.getArgs().at(0), this->Chans.at(channels.at(i)).getTopic()), parser.getReply().size(), 0);
			}
			else{
				if (channels.at(i).size() <= 200 && channels.at(i).find(7, 0) == channels.at(i).npos && (channels.at(0).at(0) == '#' || channels.at(0).at(0) == '&')){
							Channels hold(channels.at(i));
							this->Chans.insert(std::pair<std::string, Channels>(channels.at(i), hold));
							user.addChannel(it->second.getName());
							if (password.size() > i)
								this->Chans.at(channels.at(i)).addUser(user, password.at(i), parser);
							else
								it->second.addUser(user, NULL, parser);
							this->Chans.at(channels.at(i)).setOp(user.getNickname(), true);
							send(user.getFd(), parser.SendReply("332", parser.getArgs().at(0), this->Chans.at(channels.at(i)).getTopic()), parser.getReply().size(), 0);
				}
				else
					send(user.getFd(), parser.SendReply("403", parser.getArgs().at(0), "No such channel"), parser.getReply().size(), 0);
			}
		}
		break;
	}
	default:
		break;
	}
	return (0);
}
