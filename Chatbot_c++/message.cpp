#include "message.h"



Message::Message(std::shared_ptr<User> user, std::string text) :
  _user(user), _text(text)
{
  timestamp = std::time(nullptr);
}

std::string Message::getText() const
{
  return _text;
}

std::time_t Message::getTimestamp() const
{
  return timestamp;
}

std::shared_ptr<User> Message::getUser() const
{
  return _user;
}

void Message::setText(std::string& text)
{
  _text = text;
}

void Message::setUser(std::shared_ptr<User> user)
{
  _user = user;
}
std::string Message::FormatText()
{
  std::stringstream ss;
  ss << "["<< std::put_time(std::localtime(&timestamp), " % Y - % m - % d % H: % M : % S")<<"]"
  <<(_user? _user->getUsername() : "Unknown") << _text;

 return ss.str();
}
