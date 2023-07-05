#include "user.h"

//#include <string>

User::User(const std::string username, const std::string firstname, const std::string lastname, const std::string email, int age) :
  _username(username), _firstname(firstname), _lastname(lastname), _email(email), _age(age)
{
}

std::string User::getUsername() const
{
  return _username;
}

std::string User::getFirstname() const
{
  return _firstname;
}

std::string User::getLastname() const
{
  return _lastname;
}

int User::getAge() const
{
  return _age;
}

std::string User::getEmail() const
{
  return _email;
}

std::string User::getPreference(std::string& key) const
{
  auto it = std::find(std::begin(_preferences), std::end(_preferences), key);
  if (it != std::end(_preferences))
  {
    return it->second;
  }
  else
  {
    return "No preference";
  }
}

bool User::isEmailValid(const std::string& email)
{
  static const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  return std::regex_match(email, pattern);
}

void User::setFirstname(std::string& firstname)
{
  _firstname = firstname;
}

void User::setLastname(std::string& lastname)
{
  _lastname = lastname;
}

void User::setUsername(std::string& username)
{
  _username = username;
}

void User::setEmail(std::string& email)
{
  if (isEmailValid(email))
  {
    _email = email;
  }
  else
  {
    throw std::invalid_argument("Invalid email address");
  }
}

void User::setAge(int age)
{
  _age = age;
}

void User::setPreference(const std::string& key, const std::string& value)
{
  _preferences[key] = value;
}
