#ifndef MORSE_CODE_PRODUCER_H// preprocessor directives
#define MORSE_CODE_PRODUCER_H
class MorseCodeProducer {
private:
    /*static constexpr const char* dictTrans[26] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };*/
public:
    MorseCodeProducer();
    ~MorseCodeProducer();
    char* translationProtocol(char* s);
};
#endif