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
    Parser(const Parser &other);

    Parser  &operator=(const Parser &other);
    ~Parser();

    void    PrintElements();

    const std::vector<std::string>    &getArgs() const;
    const std::string                 &getCommand() const;
    const std::string                 &getPrefix() const;
    const std::string                 &getMessage() const;
private:
    std::string                 _command;
    std::vector<std::string>    _my_args;
    std::string                 _prefix;
    std::string                 _message;
};

#endif