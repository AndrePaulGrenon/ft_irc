#include "../Servers.hpp"

int	Servers::Names(Users &user, Parser &parser)
{
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
	

	(void) parser;
	return (0);
}