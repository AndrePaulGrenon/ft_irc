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
#include <arpa/inet.h>

#define MAX_SOCKET 248           // Maximum amount of open sockets in the server
#define COUNTDOWN  3 * 60 * 1000 //Waiting period to poll in milliseconds

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


private:

    // --------------------------
    //      [PRIVATE METHODS]
    // --------------------------

    void    ServerInit();
    void    CommandInit();
    void    DeleteUsers(Users &user);
    int     TrackingFd();
    void    AcceptConnection();
    void    ReceiveData(Users &user);
    void    ManageUserBuffer(Users &user);
    void    ExecuteCmd(Users &user, std::string &cmd_line);
    void    CloseSocket(int socket, int i);


    // -------------
    //     [DATA]
    // -------------
    struct ServerData
    {
        size_t                          Port;       //Port to connect to server
        std::string                     Password;   //Server password
        int                             server_fd;  //Server socket fd
        int                             nfds;       //Current amount of open sockets

        //SOCK ADDRESS: basic structure for all syscalls and functions that deal with internet addresses.
        struct sockaddr_in              address;
        // Sets the array of files descriptors that will be monitored for I/O events.
        struct pollfd                   poll_fd[MAX_SOCKET];
    };

    ServerData                      _server_data;       //Server Data

    std::map<std::string, fct>      _command_map;       //Stores all commands in a function pointer map

    //Users info
    std::map<int, Users>            usersMap;           //Store all Users
    std::map<std::string, Users*>   userPointer;        //Check with nickname
    std::set<std::string>           Username_list;      //Store Username

    //Server status 
    bool                            _close_connection;  //close specific socket that the server in currently workingon
    bool                            _end_server;        //Ends the servers
    bool                            _compression;       //Asks for compression
 //   std::map<std::string, *Channels>       Chans;
};

#endif
