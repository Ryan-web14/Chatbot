#ifndef __Chatbot__message__
#define __Chatbot__message__


#include <string>
#include "User.h"
#include <iomanip>
#include <ctime>
#include <sstream>


class Message
{
public:
Message (std::shared_ptr<User> user, std::string text);
Message();
std::string getText() const;
std::time_t getTimestamp() const;
std::shared_ptr<User> getUser() const;

void setText(std::string& text);
void setUser(std::shared_ptr<User> user);

//formatage de la chaine de texte
std::string FormatText();



private:
std::string _text; //content of the message 
std::time_t timestamp; //time of the message
std::shared_ptr<User> _user; // user who sent the message

};



#endif /* defined(__Chatbot__message__) */