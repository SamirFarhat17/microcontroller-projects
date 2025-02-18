int pot_val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_val = analogRead(A0);
  analogWrite(9, pot_val/4); // Apply brightness to LED on pin 9

}
