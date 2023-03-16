#ifndef USERS_HPP
#define USERS_HPP

#pragma once
#include <map>
#include <string>
// #include "Channels.hpp"

class Users {
public:
  Users();
  Users(std::string nname, std::string uname);
  ~Users();

  // Getters
  const int &getFd() const;
  const std::string &getNickname() const;
  const std::string &getUsername() const;
  const std::string &getChans() const;

  // Setters
  void setFd(const int &fdesc);
  void setNickname(const std::string &name);
  void setUserName(const std::string &name);

  /*         void    addChan(Channels &Chan);
          bool    isInChan(Channels &Chan); */
private:
  int fd;
  std::string Nickname;
  std::string Username;
  // std::map<std::string, Channels> Chans;
};

#endif