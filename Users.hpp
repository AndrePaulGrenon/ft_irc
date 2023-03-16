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
        Users(std::string nname, std::string uname, std::string realname, bool passw, bool reg);
        Users(const Users &other);
        const Users   &operator=(const Users &other);
        ~Users();

        //Getters
        int                 getFd() const;
        const std::string   &getNickname() const;
        const std::string   &getUsername() const;
        const std::string   &getRealname() const;
        const std::string   &getChans() const;
        bool                getPass() const;
        bool                getRegStat() const;
        
        //Setters
        void    setFd(int fdesc);
        void    setNickname(const std::string &name);
        void    setUserName(const std::string &name);
        void    setRealName(const std::string &name);
        void    setPass(bool passw);
        void    setRegistration(bool reg);

/*         void    addChan(Channels &Chan);
        bool    isInChan(Channels &Chan); */
    private:
        int                             fd;
        std::string                     Nickname;
        std::string                     Username;
        std::string                     Realname;
        bool                            Pass;
        bool                            Registration;
        //std::map<std::string, Channels> Chans;
};

#endif