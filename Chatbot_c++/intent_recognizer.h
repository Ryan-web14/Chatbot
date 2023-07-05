#ifndef __Intent__recognizer__
#define __Intent__recognizer__

#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include "message.h"
#include <regex>
enum class Intent
{
Greeting,
Goodbye,
AskWeather,
AskTheTime,
Unknown
};


class IntentRecognizer
{
public:
Intent recognize(Message* message);


 private:

 std::map<Intent, std::vector<std::string>> _intentKeywords = 
{
{Intent::Greeting, {"hello", "hi", "hey", "howdy", "sup", "what's up"}},
{Intent::Goodbye, {"goodbye", "bye", "see you", "later", "see you later"}}
};
};







#endif /* defined(__Intent__recognizer__) */