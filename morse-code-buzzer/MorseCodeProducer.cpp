#include "MorseCodeProducer.h"
#include <string.h>
#include <Arduino.h>

constexpr const char* dictTrans[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

MorseCodeProducer::MorseCodeProducer() {};
MorseCodeProducer::~MorseCodeProducer() {delete dictTrans; }

char* MorseCodeProducer::translationProtocol(char* s) {
    // First, calculate the required size for the result
    int length = 0;
    char* temp = s;
    while (*temp) {
        if (*temp >= 'A' && *temp <= 'Z') {
            length += strlen(dictTrans[*temp - 'A']) + 1; // +1 for space
        }
        temp++;
    }

    // Allocate memory dynamically (+1 for null terminator)
    char* result = new char[length + 1];
    char* ptr = result; // Pointer to write into result

    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            const char* morse = dictTrans[*s - 'A'];
            while (*morse) {
                *ptr++ = *morse++; // Copy Morse code
            }
            *ptr++ = ' '; // Add space between Morse codes
        }
        s++;
    }

    *(ptr - 1) = '\0'; // Replace last space with null terminator

    return result;
}

