#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PUMP_CONTROLLER_PIN 12

const int PHOTORESISTOR_PIN  = A0;
const int THERMISTOR_PIN = A2;
const int SOIL_MOISTURE_SENSOR_PIN = A1;

LiquidCrystal_I2C lcd(0x27, 16,2);

// Constants for temperature calculation
const float beta = 3950.0;               // NTC thermistor's Beta value
const float seriesResistor = 10000;      // Series resistor value (ohms)
const float roomTempResistance = 10000;  // NTC resistance at 25°C
const float roomTemp = 25 + 273.15;      // Room temperature in Kelvin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

int* collectReadings() {
  int lightVal = analogRead(PHOTORESISTOR_PIN);

  int adcValue = analogRead(THERMISTOR_PIN);                     // Read thermistor value
  float resistance = (1023.0 / adcValue - 1) * seriesResistor;  // Calculate thermistor resistance
  // Calculate temperature in Kelvin using Beta parameter equation
  float tempK = 1 / (log(resistance / roomTempResistance) / beta + 1 / roomTemp);
  float tempC = tempK - 273.15;  // Convert to Celsius
  int temp = tempC;

  int soilMoisture = analogRead(SOIL_MOISTURE_SENSOR_PIN);

  Serial.print("Light value: ");
  Serial.println(lightVal);
  Serial.print("Temp value: ");
  Serial.println(temp);           //Display temperature in Celsius on Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);

  static int res[3]; // Static persists beyond function call
  res[0] = lightVal;
  res[1] = temp;
  res[2] = soilMoisture;

  return res;
}

void dispense() {
  digitalWrite(PUMP_CONTROLLER_PIN, HIGH);
  delay(500);
  digitalWrite(PUMP_CONTROLLER_PIN, LOW);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("MEASUREING!");
  delay(3000);
  lcd.clear();
  int* res = collectReadings();
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Light");
  lcd.print(res[0]);
  lcd.print(" Temp");
  lcd.print(res[1]);
  lcd.setCursor(0,1);
  float moisturePercent = map(res[2], 0, 1023, 100, 0);
  lcd.print("Moisture=");
  lcd.print(moisturePercent);
  lcd.print("%");
  delay(3000);
  lcd.clear();
  if(moisturePercent < 45) dispense();
  digitalWrite(PUMP_CONTROLLER_PIN, LOW);
  delay(1000);
}
