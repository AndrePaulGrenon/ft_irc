#ifndef CHANNELS_HPP
#define CHANNELS_HPP

#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Users.hpp"

using std::string;

class Channels {
public:
  Channels(const string &nam);
  ~Channels();

  void setTopic(const string &topic);
  void setPass(const string &pass);
  void setName(const string &name);
  void setFlag(const int &which, const bool &flag);
  void setLimit(const int &limit);

  const string &getTopic() const;
  const string &getPass() const;
  const string &getName() const;
  const bool &getFlag(const int &where) const;
  const int &getLimit() const;

private:
  int _limit;
  string _pass;
  string _name;
  string _topic;
  bool _flags[6];
  std::map<Users, bool> _operators;

  static const _
};

#endif