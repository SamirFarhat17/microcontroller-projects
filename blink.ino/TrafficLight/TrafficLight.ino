#include "TrafficLight.h"

const int RED_PIN = 3;
const int YELLOW_PIN = 4;
const int GREEN_PIN = 5;
const int PEDESTRIAN_BUTTON = 11;

TrafficLight light;  // Create an instance of TrafficLight (No new!)
bool pedestrian = false;

void pedestrianPressed() {
    pedestrian = true;  // Update pedestrian flag when button is pressed
}

void setup() {
    Serial.begin(9600);  // Initialize Serial Monitor
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(PEDESTRIAN_BUTTON, INPUT_PULLUP);  // Enable internal pull-up resistor

    // Attach interrupt to the pedestrian button (falling edge when pressed)
    attachInterrupt(digitalPinToInterrupt(PEDESTRIAN_BUTTON), pedestrianPressed, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PEDESTRIAN_BUTTON)) pedestrian = true;
  digitalWrite(RED_PIN, light.getRed());
  digitalWrite(YELLOW_PIN, light.getYellow());
  digitalWrite(GREEN_PIN, light.getGreen());

  if (light.isFlashingG()) {
      for (int i = 0; i < 10; i++) {  // Flash 10 times
            digitalWrite(GREEN_PIN, HIGH);
            delay((light.getDelay()/10)*5);
            digitalWrite(GREEN_PIN, LOW);
            delay((light.getDelay()/10)*5);
        }
  } else {
      if(pedestrian && light.getRed()) {
        Serial.println("PEDESTRIASN CROSSING");
        delay(light.getDelay() * 10);
        pedestrian = ~pedestrian;
      }
      delay(light.getDelay() * 5);  // Normal delay
  }

  Serial.println("Changing traffic light state...");
  light.printState();
  light.transition();  // Call the existing transition method
  
}
