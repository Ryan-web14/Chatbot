#ifndef __Chatbot__user__
#define __Chatbot__user__


#include <string>
#include <map>
#include <regex>

class User 
{
public:
User(const std::string username, const std::string firstname, const std::string lastname, const std::string email, int age );
std::string getUsername() const;
std::string getFirstname() const;
std::string getLastname() const;
std::string getEmail() const; 
int getAge() const;
std::string getPreference(std::string& key) const;      

void setUsername(std::string& username);
void setFirstname(std::string& firstname);
void setLastname(std::string& lastname);
void setEmail(std::string& email);
void setAge(int age);
void setPreference(const std::string& key, const std::string& value);

 private:
std::string _username;
std::string _firstname;
std::string _lastname;
std::string _email;
int _age;
std::map<std::string, std::string> _preferences;

static bool isEmailValid(const std::string& email);
};

#endif /* defined(__Chatbot__user__) */