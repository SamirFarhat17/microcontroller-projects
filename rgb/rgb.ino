#include "rgb.h"
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
RGB rgb;
String msg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
    // Write PWM value for red, green, and blue to the RGB LED
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("RGB Loop...");
  if(Serial.available() > 0) {
    msg = Serial.readStringUntil('\n');
    msg.trim();
    Serial.println(msg);
  }

  char* tMsg = new char[msg.length() + 1];
  for(int i = 0; i < msg.length(); i++) {
    tMsg[i] = msg[i];
  }
  tMsg[msg.length()] = '\0';
  rgb.setColor(tMsg);

  delay(1000);
  analogWrite(RED_PIN, rgb.getRed());
  analogWrite(BLUE_PIN, rgb.getBlue());
  analogWrite(GREEN_PIN, rgb.getGreen());
  delay(1000);
  delete tMsg;

}

