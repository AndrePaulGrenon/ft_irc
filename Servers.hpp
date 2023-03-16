#ifndef SERVERS_HPP
#define SERVERS_HPP

#pragma once
#include "Users.hpp"
#include "Channels.hpp"
#include "Parser.hpp"
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <poll.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

using std::string;

class Servers {
public:
  typedef Users &users_reference;
  typedef Parser &parser_reference;
  typedef int (Servers::*fct)(users_reference, parser_reference);

  Servers(size_t pt, std::string pw);
  ~Servers();

  // Operator functions reference: https://www.rfc-editor.org/rfc/rfc1459
  /*     void    Adchat(Users &user, Parser &parser);
      void    Admin(Users &user, Parser &parser);
      void    Chatops(Users &user, Parser &parser);
      void    Gline(Users &user, Parser &parser);
      void    Globops(Users &user, Parser &parser);
      void    Gzline(Users &user, Parser &parser)
      void    Invite(Users &user, Parser &parser);
      void    kill(Users &user, Parser &parser);
      void    Kline(Users &user, Parser &parser);
      void    Locops(Users &user, Parser &parser);
      void    Nachat(Users &user, Parser &parser);
      void    Shun(Users &user, Parser &parser);
      void    Wallops(Users &user, Parser &parser);
      void    Zline(Users &user, Parser &parser) */

  // int     Admin(Users &user, Parser &parser); // Returns information about
  // specified admin int     Away(Users &user, Parser &parser); // Provides the
  // server with a message to automatically send in reply to a PRIVMSG directed
  // at the user, but not to a channel they are on int     Cnotice(Users &user,
  // Parser &parser); int     Connect(Users &user, Parser &parser); // À revoir,
  // sert à connecter un server à un autre int     Cprivmsg(Users &user, Parser
  // &parser); //Sends a private message that bypasses food protection. User
  // must be in channel
  int Die(Users &user, Parser &parser); // Instruct the server to shut down
  int Encap(Users &user,
            Parser &parser); // This command is for use by servers to
                             // encapsulate commands so that they will propagate
                             // across hub servers not yet updated to support
                             // them, and indicates the subcommand and its
                             // parameters should be passed unaltered to the
                             // destination, where it will be unencapsulated and
                             // parsed. This facilitates implementation of new
                             // features without a need to restart all servers
                             // before they are usable across the network
  int Error(
      Users &user,
      Parser &parser); // use by servers to report errors to other servers. It
                       // is also used before terminating client connections.
  int Pass(Users &user, Parser &parser); // Set connection password
  int Nick(Users &user, Parser &parser); // Set or reset user's nickname
  int User(Users &user,
           Parser &parser); // Used at beginning of connection to sets usernam,
                            // hostname servanem and realname of new user

  // int     Server(Users &user, Parser &parser); // Pas sûr de celui-là
  // int     Oper(Users &user, Parser &parser);
  // int     Quit(Users &user, Parser &parser);
  // int     Squit(Users &user, Parser &parser);
  // int     Join(Users &user, Parser &parser);
  // int     Part(Users &user, Parser &parser);
  // int     Mode(Users &user, Parser &parser);//Revoir celui-là, pas clair
  // int     Mode(Users &user, Parser &parser);
  int Topic(Users &user, Parser &parser);
  // int     Names(Users &user, Parser &parser);
  // int     List(Users &user, Parser &parser);
  // int     Invite(Users &user, Parser &parser);
  // int     Kick(Users &user, Parser &parser);
  // int     Stats(Users &user, Parser &parser);
  // int     Links(Users &user, Parser &parser); // Paramètres à revoir
  // int     Time(Users &user, Parser &parser) //Par sûr des params

  // Méthodes
  void start();
  void ServerInit();

private:
  size_t Port;
  std::string Password;
  std::map<int, Users> usersMap;
  std::map<string, fct> commandMap;
  std::map<string, Channels> chanMap;
  //   std::map<std::string, *Channels>       Chans;
};

#endif
