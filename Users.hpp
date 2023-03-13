#ifndef USERS.HPP
#define USERS.HPP

#pragma once
#include <string>

class Users
{
public:
    Users(std::string Nn, std::string Un);
    ~Users();

private:
    std::string Nickname;
    std::string Username;
};

#endif