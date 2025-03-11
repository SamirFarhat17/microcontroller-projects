#include <Servo.h>

Servo servo;
const int SERVO_PIN = 9;
const int LIGHT_PIN = A0;
                    
void setup() {                                                                                  
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(SERVO_PIN);                           
  servo.write(90);                                                                   
}                                                                                                                                                  
                                                                                                                                                                                                   
void loop() {
  // put your main code here, to run  repeatedly:                         
  int lightVal = analogRead(LIGHT_PIN);             
  Serial.println(lightVal);                                                                                                                                                                                                                                                                                
  if(lightVal > 200) {
    servo.write(20);
    delay(100);
  }
  else servo.write(90);
  /*servo.write(20);                                                                                                                       
  delay(100);
  servo.write(60);*/                      
}