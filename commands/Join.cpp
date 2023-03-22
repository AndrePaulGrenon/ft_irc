#include "../Servers.hpp"

int     Servers::Join(Users &user, Parser &parser){
	/* if (this->Chans.empty())
	{
		Channels test("test");
		this->Chans.insert(std::pair<std::string, Channels>("test", test));
		this->Chans.at("test").setOp(user.getNickname(), true);
		this->Chans.at("test").addUser(user);
	}
	else{
		this->Chans.at("test").addUser(user);
	} */
	switch (parser.getArgs().size())
	{
	case 1: //only channel no password
	{
		std::vector<std::string> channels = parser.SplitComa(parser.getArgs().at(0));
		for (size_t i = 0; i < channels.size(); i++){
			std::map<std::string, Channels>::iterator it = this->Chans.find(channels.at(i));
			if (it != this->Chans.end()){
				it->second.addUser(user);
				it->second.setOp(user.getNickname(), false);
			}
			else{
				if (channels.at(i).size() <= 200 && channels.at(i).find(7, 0) == channels.at(i).npos && (channels.at(0).at(0) == '#' || channels.at(0).at(0) == '&')){
					Channels hold(channels.at(i));
					this->Chans.insert(std::pair<std::string, Channels>(channels.at(i), hold));
					this->Chans.at(channels.at(i)).addUser(user);
					this->Chans.at(channels.at(i)).setOp(user.getNickname(), true);
				}
				else
					std::cout << "The channel is not good" << std::endl; // va falloir mettre un message d'erreur
			}
		}
		break;
	}
	case 2: //check if passwords are used
	{
		
		break;
	}
	default:
		break;
	}
	return (0);
}
