#ifndef CHANNELS_HPP
#define CHANNELS_HPP

#pragma once
#include <string>

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
  bool flags[6];
  int limit;
  string topic;
  string pass;
  string name;

};

#endif