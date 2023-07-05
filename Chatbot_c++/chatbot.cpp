#include "chatbot.h"


void ChatBot::receive(Message* message)
{
  Intent intent = intentRecognizer.recognize(message);
  
  switch (intent)
  {
    case Intent::Greeting:
      std::cout <<"Hello what can I do for you ? \n";
      break;
    case Intent::Goodbye:
      std::cout << "Goodbye sir I hope I was useful !! \n";
      break;
    case Intent::AskWeather:
      std::cout << "It is sunny today !! \n";
      break;
    case Intent::AskTheTime:
    

  
  }
}
