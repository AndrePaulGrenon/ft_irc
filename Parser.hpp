#ifndef PARSER_HPP
#define PARSER_HPP

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "colours.hpp"

#define IRC "team_irc42"

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
    const std::string                 &getReply() const;
    const char                              *SendReply(const std::string code, const std::string args, const std::string message) ;
    
private:
    std::string                 _command;
    std::vector<std::string>    _my_args;
    std::string                 _prefix;
    std::string                 _message;
    std::string                 _server_name;
    std::string                 _reply;
};

#endif