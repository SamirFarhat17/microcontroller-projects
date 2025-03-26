#include <IRremote.h>  // Include the IRremote library

const int receiverPin = 2;  // Define the pin number for the IR Sensor

// Define the pins of RBG LED
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  // Initialize RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);
  // Initialize the IR receiver on the specified pin with LED feedback enabled
  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {  // Check if the IR receiver has received a signal
    bool result = 0;
    String key = decodeKeyValue(IrReceiver.decodedIRData.command);
    if (key != "ERROR") {
      Serial.println(key);  // Print the readable command
      delay(100);
    }

    if (key == "1") {
      setColor(255, 0, 0);  // Red
    } else if (key == "2") {
      setColor(0, 255, 0);  // Green
    } else if (key == "3") {
      setColor(0, 0, 255);  // Blue
    } else if (key == "4") {
      setColor(255, 165, 0);  // Orange
      delay(100);
      setColor(0, 0, 0);  // Turn off RGB LED
      delay(100);
    } else {
      setColor(0, 0, 0);  // Turn off RGB LED for any other key
    }
  IrReceiver.resume();  // Prepare the IR receiver to receive the next signal
  }
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// Function to map received IR signals to corresponding keys
String decodeKeyValue(long result) {
  switch (result) {
    case 0x45: return "POWER";
    case 0x47: return "MUTE";
    case 0x46: return "MODE";
    case 0x44: return "PLAY/PAUSE";
    case 0x40: return "BACKWARD";
    case 0x43: return "FORWARD";
    case 0x7: return "EQ";
    case 0x15: return "-";
    case 0x9: return "+";
    case 0x19: return "CYCLE";
    case 0xD: return "U/SD";
    case 0x16: return "0";
    case 0xC: return "1";
    case 0x18: return "2";
    case 0x5E: return "3";
    case 0x8: return "4";
    case 0x1C: return "5";
    case 0x5A: return "6";
    case 0x42: return "7";
    case 0x52: return "8";
    case 0x4A: return "9";
    case 0x0: return "ERROR";
    default: return "ERROR";
  }
}