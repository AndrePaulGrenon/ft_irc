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

    std::vector<std::string> &getArgs();
    std::string              &Command();
    std::string              &getPrefix();
private:
    std::vector<std::string>    _my_args;
    std::string                 _command;
    std::string                 _prefix;
};

#endif