#ifndef PARSER_HPP
#define PARSER_HPP

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "colours.hpp"

class Parser
{
public:
    Parser(char *buff);
    ~Parser();

    std::vector<std::string>    &getArgs();
    std::string                 &getCommand();
    std::string                 &getPrefix();
    std::string                 &getMessage();
private:
    std::string                 _command;
    std::vector<std::string>    _my_args;
    std::string                 _prefix;
    std::string                 _message;
};

#endif