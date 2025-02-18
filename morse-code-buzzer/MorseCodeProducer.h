#ifndef MORSE_CODE_PRODUCER_H// preprocessor directives
#define MORSE_CODE_PRODUCER_H
#include <Arduino.h>
class MorseCodeProducer {
private:
    static const char* dictTrans[26];  // Declare here
public:
    MorseCodeProducer();
    ~MorseCodeProducer();
    char* translationProtocol(char* s);
};
#endif