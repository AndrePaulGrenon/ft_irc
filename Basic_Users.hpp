#ifndef BASIC_USERS_HPP
#define BASIC_USERS_HPP

#pragma once
#include <string>
#include "Users.hpp"

class Basic_Users: public Users
{
public:
    users(std::string Nn, std::string Un);
    ~users();

private:
    std::string Nickname;
    std::string Username;
};

#endif