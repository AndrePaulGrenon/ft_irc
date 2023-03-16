#include "Users.hpp"

Users::Users(): Pass(false), Registration(false){}

Users::Users(const std::string nname, const std::string uname, const std::string realname, bool passw, bool reg): Nickname(nname), Username(uname), Realname(realname), Pass(passw), Registration(reg){}

Users::Users(const Users &other)
{
	*this = other;
}

Users::~Users(){}

const Users   &Users::operator=(const Users &other)
{
	fd = other.getFd();
	Nickname = other.getNickname();
	Username = other.getUsername();
	Realname = other.getRealname();
	Pass = other.getPass();
	Registration = other.getRegStat();
	return *this;
}

int	Users::getFd() const
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
const std::string	&Users::getRealname() const
{
	return Realname;
}

bool	Users::getPass() const
{
	return Pass;
}

bool	Users::getRegStat() const
{
	return Registration;
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
void	Users::setRealName(const std::string &name)
{
	Realname = name;
}
void	Users::setPass(bool passw)
{
	Pass = passw;
}
void	Users::setRegistration(bool reg)
{
	Registration = reg;
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