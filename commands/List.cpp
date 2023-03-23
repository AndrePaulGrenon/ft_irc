#include "../Servers.hpp"

int	Servers::List(Users &user, Parser &parser)
{
	if (parser.getArgs().size() > 0)
	{
		ListDefine(user, parser);
		return 0;
	}
	std::map<std::string, Channels>::iterator it = Chans.begin();
	std::map<std::string, Channels>::iterator ite = Chans.end();

	for (; it != ite; it++)
	{
		if (UsersIsSubscribe(it->second.getName(), user) || !it->second.getFlag(S))
		{
			if (it->second.getFlag(P) && !UsersIsSubscribe(it->second.getName(), user))
				send(user.getFd(), parser.SendReply("353", it->second.getName(), 
					"You are not subscribed to this private channel "), parser.getReply().size(), 0);
			else
				send(user.getFd(), parser.SendReply("353", it->second.getName(), 
					"Topic : " + it->second.getTopic()), parser.getReply().size(), 0);
		}
	}
	return (0);
}

void	Servers::ListDefine(Users &user, Parser &parser)
{
	std::vector<std::string> comaChannels = parser.SplitComa(parser.getArgs()[0]);

	for (size_t i = 0; i < comaChannels.size(); i++)
	{
		if (UsersIsSubscribe(comaChannels[i], user) || Chans[comaChannels[i]].getFlag(S))
		{
			if (Chans[comaChannels[i]].getFlag(P) && !UsersIsSubscribe(comaChannels[i], user))
				send(user.getFd(), parser.SendReply("353", comaChannels[i], 
					"You are not subscribed to this private channel "), parser.getReply().size(), 0);
			else
				send(user.getFd(), parser.SendReply("353", comaChannels[i], 
					"Topic : " + Chans[comaChannels[i]].getTopic()), parser.getReply().size(), 0);
		}
	}
	return ;
}