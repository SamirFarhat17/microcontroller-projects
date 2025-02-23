const int XPIN = A0;
const int YPIN = A1;
const int SW_PIN = 2;

const int GREEN_PIN = 8;
const int YELLOW_PIN = 9;
const int BLUE_PIN = 10;
const int RED_PIN = 11;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  int xValue = analogRead(XPIN);
  int yValue = analogRead(YPIN);
  int swValue = digitalRead(SW_PIN);
  if(counter > 5000) {
    Serial.print(xValue);
    Serial.print(" | ");
    Serial.print(yValue);
    Serial.print(" | ");
    Serial.println(swValue);
    Serial.println("-------------");
    counter = 0;
  }
  if(xValue < 100) digitalWrite(RED_PIN, HIGH);
  else digitalWrite(RED_PIN, LOW);
  if(xValue > 900) digitalWrite(GREEN_PIN, HIGH);
  else digitalWrite(GREEN_PIN, LOW);

  if(yValue < 100) digitalWrite(BLUE_PIN, HIGH);
  else digitalWrite(BLUE_PIN, LOW);
  if(yValue > 900) digitalWrite(YELLOW_PIN, HIGH);
  else digitalWrite(YELLOW_PIN, LOW);


  counter++;
}
