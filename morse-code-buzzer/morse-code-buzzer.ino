#include "MorseCodeProducer.h"

const int MORSE_CODE_PIN = 9;
const MorseCodeProducer morse;
String msg = "";

void setup() {
    Serial.begin(9600);  // Start serial communication at 9600 baud
    pinMode(MORSE_CODE_PIN, OUTPUT);
    Serial.println("Enter a message to convert to Morse Code:");
}

void loop() {
    //const char* s = "HELLOTHISISSAMIR";  // Ensure uppercase letters
    //char* res = morse.translationProtocol(s);  // Convert to Morse code
    if(Serial.available() > 0) {
      msg = Serial.readStringUntil('\n');
      msg.trim();
      if(msg.length() > 0) {      
        Serial.print("Converting: ");
        Serial.println(msg);

        char inputArray[msg.length() + 1];  // Create char array
        msg.toUpperCase();  // Convert to uppercase
        msg.toCharArray(inputArray, msg.length() + 1);

        char* res = morse.translationProtocol(inputArray);

        if (res) {  // Ensure res is not null
            char* temp = res;  // Save pointer for deletion

            while (*res) {
                Serial.print(*res);  // Print each character separately
                if (*res == '.') dot();
                else if (*res == '-') dash();
                res++;
            }

            Serial.println();  // Newline after Morse code output
            delete[] temp;  // Free allocated memory
        }
      }
    }
    delay(2000);  // Wait before next transmission
}

void dot() {
    digitalWrite(MORSE_CODE_PIN, HIGH);
    delay(100);
    digitalWrite(MORSE_CODE_PIN, LOW);
    delay(100);
}

void dash() {
    digitalWrite(MORSE_CODE_PIN, HIGH);
    delay(300);
    digitalWrite(MORSE_CODE_PIN, LOW);
    delay(100);
}
