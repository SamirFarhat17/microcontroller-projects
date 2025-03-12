
const int MOTOR_1A_PIN = 10;
const int MOTOR_2A_PIN = 9;
const int BUTTON1 = 4;
const int BUTTON2 = 5;
const int BUTTON3 = 6;
const int BUTTON4 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_1A_PIN, OUTPUT);
  pinMode(MOTOR_2A_PIN, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(BUTTON1) == LOW) {         // Check if first button is pressed
    motorRotate(0);                          // Turn off the motor
  } else if (digitalRead(BUTTON2) == LOW) {  // Check if second button is pressed
    motorRotate(5);                        // Set speed for low
  } else if (digitalRead(BUTTON3) == LOW) {  // Check if third button is pressed
    motorRotate(200);                        // Set speed for medium
  } else if (digitalRead(BUTTON4) == LOW) {  // Check if fourth button is pressed
    motorRotate(250);   
  }
}

void motorRotate(int speed) {
  digitalWrite(MOTOR_1A_PIN, speed);
  digitalWrite(MOTOR_2A_PIN, LOW);
}
