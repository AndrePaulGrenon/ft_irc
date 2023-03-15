#ifndef USERS_HPP
#define USERS_HPP

#pragma once
#include <string>
#include <map>
#include "Channels.hpp"

class Users
{
    public:
        Users();
        Users(std::string nname, std::string uname);
        ~Users();

        //Getters
        int         getFd();
        std::string &getNickname();
        std::string &getUsername();
        std::string &getChans();
        
        //Setters
        void    setFd(int fdesc);
        void    setNickname(std::string &name);
        void    setUserName(std::string &name);

/*         void    addChan(Channels &Chan);
        bool    isInChan(Channels &Chan); */
    private:
        int                             fd;
        std::string                     Nickname;
        std::string                     Username;
        //std::map<std::string, Channels> Chans;
};

#endif