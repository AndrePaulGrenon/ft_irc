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
#include "Users.hpp"
#include "Channels.hpp"

class Users;
class Channels;

class Servers
{
public:
    Servers(size_t pt, std::string pw);
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
    //int     Admin(std::string target); // Returns information about specified admin
    //int     Away(std::string message); // Provides the server with a message to automatically send in reply to a PRIVMSG directed at the user, but not to a channel they are on
    //int     Cnotice(std::string nick, std::string chan, std::string message);
    //int     Connect(); // À revoir, sert à connecter un server à un autre
    //int     Cprivmsg(std::string nick, std::string chan, std::string message); //Sends a private message that bypasses food protection. User must be in channel 
    int     Pass(std::string pw); //Set connection password
    int     Nick(std::string nick); //Set or reset user's nickname
    int     User(std::string username, std::string hostname, std::string serversname, std::string realname); //Used at beginning of connection to sets usernam, hostname servanem and realname of new user
    //int     Server(std::string servername, int hopcount, std::string info); // Pas sûr de celui-là
    //int     Oper(std::string uname, std::string pw);
    //int     Quit(std::string message);
    //int     Squit(std::string serv, std::string comment);
    //int     Join(std::string chan, std::string pw);
    //int     Part(std::string chan);
    //int     Mode(std::string chan, char options, );//Revoir celui-là, pas clair
    //int     Mode(std::string uname, char options);
    //int     Topic(std::string chan, std::string top);
    //int     Names(std::string chan);
    //int     List(std::string chan, std::string serv);
    //int     Invite(std::string nickname, std::string chan);
    //int     Kick(std::string chan, std::string user, std::string message);
    //int     Stats(char c, std::string serv);
    //int     Links(); // Paramètres à revoir
    //int     Time(std::string server) //Par sûr des params
    
    // Méthodes
    void    start();
private:
    size_t                          Port;
    std::string                     Password;
    std::map<std::string, Users>    Users;
 //   std::map<std::string, Channels>       Chans;
};

#endif