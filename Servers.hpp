#ifndef SERVERS_HPP
#define SERVERS_HPP

#pragma once
#include <poll.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Users.hpp"
#include "Channels.hpp"
#include "Parser.hpp"

class Servers
{
public:
    typedef Users &users_reference;
    typedef Parser &parser_reference;
    typedef int (Servers::*fct)(users_reference, parser_reference);

    Servers(size_t pt, std::string pw);
    ~Servers();

    int     Pass(Users &user, Parser &parser); //Set connection password
    int     Nick(Users &user, Parser &parser); //Set or reset user's nickname
    int     User(Users &user, Parser &parser); //Used at beginning of connection to sets usernam, hostname servanem and realname of new user
    int     Away(Users &user, Parser &parser); //
    int     Invite(Users &user, Parser &parser); //
    int     Join(Users &user, Parser &parser); //
    int     Kick(Users &user, Parser &parser); //
    int     List(Users &user, Parser &parser); //
    int     Mode(Users &user, Parser &parser); //
    int     Names(Users &user, Parser &parser); //
    int     Notice(Users &user, Parser &parser); //
    int     Part(Users &user, Parser &parser); //
    int     Ping(Users &user, Parser &parser); //
    int     Pong(Users &user, Parser &parser); //
    int     Privmsg(Users &user, Parser &parser); //
    int     Quit(Users &user, Parser &parser); //
    int     Shutdown(Users &user, Parser &parser); //
    int     Topic(Users &user, Parser &parser); //
    
    // Méthodes
    void    start();
    void    ServerInit();
    void    DeleteUsers(Users &user);

private:
    size_t                          Port;
    std::string                     Password;
    std::map<std::string, fct>      commandMap;

    //Users info
    std::map<int, Users>            usersMap;
    std::set<std::string>           Nickname_list;
    std::set<std::string>           Username_list;

    //Server status 
    bool                            close_connection;//close specific socket that the server in currently workingon
    bool                            end_server; //Ends the servers
 //   std::map<std::string, *Channels>       Chans;
};

#endif
