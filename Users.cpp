#include "Users.hpp"

Users::Users() {}

Users::Users(std::string nname, std::string uname)
    : Nickname(nname), Username(uname) {}

Users::~Users() {}

const int &Users::getFd() const { return fd; }
const std::string &Users::getNickname() const { return Nickname; }
const std::string &Users::getUsername() const { return Username; }

void Users::setFd(const int &fdesc) { fd = fdesc; }
void Users::setNickname(const std::string &name) { Nickname = name; }
void Users::setUserName(const std::string &name) { Username = name; }

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