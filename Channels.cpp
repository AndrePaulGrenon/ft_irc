#include "Channels.hpp"

Channels::Channels(const string &name)
    : _name(name), _limit(-1), _topic(NULL), _pass(NULL) {
  for (size_t i = 0; i < 6; i++)
    this->_flags[i] = false;
}

Channels::~Channels() { std::cout << "Goodbye world" << std::endl;}

void Channels::setTopic(const string &topic) { this->_topic = topic; }

void Channels::setPass(const string &pass) { this->_pass = pass; }

void Channels::setName(const string &name) { this->_name = name; }

void Channels::setFlag(const int &which, const bool &flag) {
  this->_flags[which] = flag;
}

void Channels::setLimit(const int &limit) { this->_limit = limit; }

const string &Channels::getTopic() const { return this->_topic; }

const string &Channels::getPass() const { return this->_pass; }

const string &Channels::getName() const { return this->_name; }

const bool &Channels::getFlag(const int &where) const {
  return this->_flags[where];
}

const int &Channels::getLimit() const { return this->_limit; }
