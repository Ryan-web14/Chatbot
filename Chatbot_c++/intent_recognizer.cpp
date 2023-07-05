#include "intent_recognizer.h"

Intent IntentRecognizer::recognize(Message* message)
{
  Message _message;
  _message = *message ;
  std::string text = _message.getText();
  std::transform(std::begin(text), std::end(text),std::begin(text), ::tolower);
  
  if (std::regex_search(text, std::regex("(hello|hi)")))
  {
   return Intent::Greeting;
  }
  else if (std::regex_search(text, std::regex("(bye|quit|goodbye)")))
  {
    return Intent::Goodbye;
  }
  else if (std::regex_search(text, std::regex("(weather|temperature|forecast)")))
  {
    return Intent::AskWeather;
  }
  else if (std::regex_search(text, std::regex("(time|clock|hour)"))) {
    return Intent::AskTheTime;
  }
  else 
  {
    return Intent::Unknown;
  }




  /*for (auto& pair : _intentKeywords)
  {
    for (auto& keyword : pair.second)
    {
      if (text.find(keyword) != std::string::npos)
      {
        return pair.first;
      }
    }
  }*/
  return Intent::Unknown;
}