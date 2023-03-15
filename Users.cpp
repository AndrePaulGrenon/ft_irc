#include "Users.hpp"

Users::Users(){}

Users::~Users(){}

int	Users::getFd()
{
	return fd;
}
std::string	&Users::getNickname()
{
	return Nickname;
}
std::string	&Users::getUsername()
{
	return Username;
}

void	Users::setFd(int fdesc)
{
	fd = fdesc;
}
void	Users::setNickname(std::string &name)
{
	Nickname = name;
}
void	Users::setUserName(std::string &name)
{
	Username = name;
}

void	Users::addChan(Channels &Chan)
{
	if (Chans.find(Chan.getname()) == Chans.end())
		Chans.insert(std::pair(Chan.getname(), Chan));
}

bool	Users::isInChan(std::string &Chan)
{
	if (Chans.find(Chan.getname()) == Chans.end())
		return false;
	return true;
}