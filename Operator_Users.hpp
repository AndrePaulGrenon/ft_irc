#ifndef OPERATOR_USERS_HPP
#define OPERATOR_USERS_HPP

#pragma once
#include <string>
#include "Users.hpp"

class Operator_Users: public Users
{
public:
    Operator_Users(std::string Pw, std::string Nn, std::string Un);
    ~Operator_Users();

private:
    std::string OpPassWord;
};

#endif