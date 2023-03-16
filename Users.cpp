#include "Users.hpp"

Users::Users(){}

Users::Users(const std::string nname, const std::string uname): Nickname(nname), Username(uname){}

Users::~Users(){}

int	Users::getFd()
{
	return fd;
}
const std::string	&Users::getNickname() const
{
	return Nickname;
}
const std::string	&Users::getUsername() const
{
	return Username;
}

void	Users::setFd(int fdesc)
{
	fd = fdesc;
}
void	Users::setNickname(const std::string &name)
{
	Nickname = name;
}
void	Users::setUserName(const std::string &name)
{
	Username = name;
}

/* void	Users::addChan(Channels &Chan)
{
	if (Chans.find(Chan.getname()) == Chans.end())
		Chans.insert(std::pair(Chan.getname(), Chan));
}

bool	Users::isInChan(std::string &Chan)
{
	if (Chans.find(Chan.getname()) == Chans.end())
		return false;
	return true;
} */