#ifndef PARSER_HPP
#define PARSER_HPP

#pragma once

#include <vector>
#include <string>
#include <iostream>

class Parser
{
public:
    Parser(char *buff);
    ~Parser();

    std::vector<std::string> &getArgs();
private:
    std::vector<std::string>    my_args;
    std::string                 command;
    std::string                 prefix;
};

#endif