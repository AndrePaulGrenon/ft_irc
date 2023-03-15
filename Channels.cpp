#include "Channels.hpp"

Channels::Channels(const string &nam)
    : name(nam), limit(-1), topic(NULL), pass(NULL) {
  for (size_t i = 0; i < 6; i++)
    this->flags[i] = false;
}

Channels::~Channels() {}

void Channels::setTopic(const string &topic) { this->topic = topic; }

void Channels::setPass(const string &pass) { this->pass = pass; }

void Channels::setName(const string &name) { this->name = name; }

void Channels::setFlag(const int &which, const bool &flag) {
  this->flags[which] = flag;
}

void Channels::setLimit(const int &limit) { this->limit = limit; }

const string &Channels::getTopic() const { return this->topic; }

const string &Channels::getPass() const { return this->pass; }

const string &Channels::getName() const { return this->name; }

const bool &Channels::getFlag(const int &where) const {
  return this->flags[where];
}

const int &Channels::getLimit() const { return this->limit; }
