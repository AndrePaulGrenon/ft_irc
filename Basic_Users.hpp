#ifndef BASIC_USERS_HPP
#define BASIC_USERS_HPP

#pragma once
#include <string>

class Basic_Users
{
    public:
        Basic_Users(std::string Nn, std::string Un);
        ~Basic_Users();

    private:
        std::string Nickname;
        std::string Username;
};

#endif