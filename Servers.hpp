#ifndef SERVERS_HPP
#define SERVERS_HPP

#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Basic_Users.hpp"
#include "Channels.hpp"

class Basic_Users;
class Channels;
class Operator_Users;

class Servers
{
public:
    Servers(std::string pw, size_t p);
    ~Servers();

    // Operator functions reference: https://www.rfc-editor.org/rfc/rfc1459
/*     void    Adchat(std::string message);
    void    Admin();
    void    Chatops(std::string message);
    void    Gline(std::string nick, size_t time_to_ban, std::string reason);
    void    Globops(std::string message);
    void    Gzline(std::)
    void    Invite(std::string nick, std::string chan);
    void    kill(std::string nick, std::message);
    void    Kline(std::string nick, size_t time_to_ban);
    void    Locops(std::string message);
    void    Nachat(std::string message);
    void    Shun(std::string nick, size_t time_to_ban, std::string reason);
    void    Wallops(std::string message);
    void    Zline(std::string ip, size_t time_to_ban, std::string reason) */
    void    Pass(std::string pw);
    void    Nick(std::string nick);
    void    User(std::string username, std::string hostname, std::string serversname, std::string realname);
    void    Server(std::string servername, int hopcount, std::string info); // Pas sûr de celui-là
    void    Oper(std::string uname, std::string pw);
    void    Quit(std::string message);
    void    Squit(std::string serv, std::string comment);
    void    Join(std::string chan, std::string pw);
    void    Part(std::string chan);
    void    Mode(std::string chan, char options, );//Revoir celui-là, pas clair
    void    Mode(std::string uname, char options);
    void    Topic(std::string chan, std::string top);
    void    Names(std::string chan);
    void    List(std::string chan, std::string serv);
    void    Invite(std::string nickname, std::string chan);
    void    Kick(std::string chan, std::string user, std::string message);

private:
    std::string         Password;
    size_t              Port;
    std::map<std::string, Basic_Users>    BasicUsers;
    std::map<std::string, Operator_Users> OpUsers;
    std::map<std::string, Channels>       Chans;
};

#endif