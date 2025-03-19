#include <Servo.h>

#define ULTRASONIC_TRIGGER_PIN 7
#define ULTRASONIC_ECHO_PIN 8
const int SERVO_PIN = 9;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(SERVO_PIN, OUTPUT);
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
}

long measureDistance() {
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

  long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  return (duration * 0.034) / 2;
}

void openCan() {
  servo.write(90);
  delay(1000);

}

void closeCan() {
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  long distance = measureDistance();
  Serial.print("Distance is ");
  Serial.print(distance);
  Serial.println("cm");

  if(distance < 8) {
    openCan();
  }
  else closeCan();


}
