#ifndef __Chatbot__
#define __Chatbot__

#include "message.h"
#include "intent_recognizer.h"
#include "user.h"
#include <iostream>


class ChatBot
{
public:
void receive(Message* message);

private:
IntentRecognizer intentRecognizer;
};






#endif /* defined(__Chatbot__) */