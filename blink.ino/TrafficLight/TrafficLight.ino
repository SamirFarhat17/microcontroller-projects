#include "TrafficLight.h"

const int RED_PIN = 3;
const int YELLOW_PIN = 4;
const int GREEN_PIN = 5;
TrafficLight light;  // Create an instance of TrafficLight (No new!)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initialize Serial Monitor
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
      delay(light.getDelay() * 5);  // Normal delay
  }

  Serial.println("Changing traffic light state...");
  light.printState();
  light.transition();  // Call the existing transition method
  
}
