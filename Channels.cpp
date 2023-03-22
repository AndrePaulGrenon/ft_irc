#include "Channels.hpp"

Channels::Channels(const string &name) :_limit(-1), _name(name){
  for (size_t i = 0; i < 6; i++)
    this->_flags[i] = false;
}

Channels::~Channels() { std::cout << "Goodbye world" << std::endl; }

void Channels::setTopic(const string &topic) { this->_topic = topic; }

void Channels::setPass(const string &pass) { this->_pass = pass; }

void Channels::setName(const string &name) { this->_name = name; }

void Channels::setFlag(const int &which, const bool &flag) {
  this->_flags[which] = flag;
}

void Channels::setLimit(const int &limit) { this->_limit = limit; }

void Channels::setOp(const string &user, const bool &op) {
  if (this->_operators.find(user) != this->_operators.end())
    this->_operators.at(user) = op;
}

const string &Channels::getTopic() const { return this->_topic; }

const string &Channels::getPass() const { return this->_pass; }

const string &Channels::getName() const { return this->_name; }

const bool &Channels::getFlag(const int &where) const {
  return this->_flags[where];
}

const int &Channels::getLimit() const { return this->_limit; }

bool Channels::getOp(const string &user) const {
  if (this->_ban.find(user) == this->_ban.end())
    return (false);
  return this->_operators.at(user);
}

std::vector<Users>  Channels::getUsers() const
{
    return _users;
}

bool Channels::getBan(const string user) const{
  if (this->_ban.find(user) == this->_ban.end())
    return (false);
  return this->_ban.at(user);
}

void  Channels::addUser(const Users &user, const std::string &pass, Parser &parser){
  std::vector<Users>::iterator it = this->_users.begin();
  while (it != this->_users.end())
  {
    if (user.getNickname() == (*it).getNickname())
      break;
     it++;
  }
  if (it == this->_users.end()){
    if (this->getFlag(I) == false)
      if (this->getBan(user.getNickname()) == false)
        if (this->getLimit() == -1 || (const int) this->getUsers().size() < this->getLimit())
          if (!this->getPass().empty())
            if (this->getPass() == pass)
              this->_users.push_back(user);
            else
              send(user.getFd(), parser.SendReply("475", parser.getArgs().at(0), "Cannot join channel (+k)"), parser.getReply().size(), 0);
          else
            this->_users.push_back(user);
        else
          send(user.getFd(), parser.SendReply("471", parser.getArgs().at(0), "Cannot join channel (+l)"), parser.getReply().size(), 0);
      else
        send(user.getFd(), parser.SendReply("474", parser.getArgs().at(0), "Cannot join channel (+b)"), parser.getReply().size(), 0);
    else
      send(user.getFd(), parser.SendReply("473", parser.getArgs().at(0), "Cannot join channel (+i)"), parser.getReply().size(), 0);
    }
}

