#define PUMP_PIN 2
#define ECHO_PIN 8
#define TRIGGER_PIN 7


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

long computeDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration*0.034/2;
}

void dispense() {
  digitalWrite(PUMP_PIN, HIGH);
  delay(500);
  digitalWrite(PUMP_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  Serial.print("distance=");
  long distance = computeDistance();
  Serial.print(distance);
  Serial.println("cm");

  if(distance < 8) dispense();
}
