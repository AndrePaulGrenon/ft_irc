#include "../Servers.hpp"

int	Servers::Names(Users &user, Parser &parser)
{
	if (parser.getArgs().size() > 0)
	{

		return ;
	}

	std::map<std::string, Channels>::iterator it = Chans.begin();
	std::map<std::string, Channels>::iterator ite = Chans.end();
	std::set<std::string> tempList;

	for (; it != ite; it++)
	{
		if (!it->second.getFlag(P) && !it->second.getFlag(S))
		{
			std::string message;
			std::vector<Users> list_users = it->second.getUsers();
			for (unsigned int i = 0; i < list_users.size(); i++)
			{
				if (i != 0)
					message += " ";
				message += list_users[i].getNickname();
				tempList.insert(list_users[i].getNickname());
			}
			while (message.size())
			{
				if (message.size() > 510)
				{
					send(user.getFd(), parser.SendReply("353", it->second.getName(), message.substr(0, 510)), parser.getReply().size(), 0);
					message = message.substr(0, 510);
				}
				else
				{
					send(user.getFd(), parser.SendReply("366", it->second.getName(), message), parser.getReply().size(), 0);
					break ; 
				}
			}
		}
	}
	std::map<int, Users>::iterator uit = usersMap.begin();
	std::map<int, Users>::iterator uite = usersMap.end();
	std::string other_users;
	bool oneuser = false;
	for (; uit != uite; uit++)
	{
		if (tempList.end() == tempList.find(uit->second.getNickname()))
		{
			if (other_users.size())
				other_users += " ";
			other_users += uit->second.getNickname();
			oneuser = true;
		}
	}
	if (oneuser)
	{
			while (other_users.size())
			{
				if (other_users.size() > 510)
				{
					send(user.getFd(), parser.SendReply("353", "*", other_users.substr(0, 510)), parser.getReply().size(), 0);
					other_users = other_users.substr(0, 510);
				}
				else
				{
					send(user.getFd(), parser.SendReply("366", "*", other_users), parser.getReply().size(), 0);
					break ; 
				}
			}
	}
	return (0);
}
