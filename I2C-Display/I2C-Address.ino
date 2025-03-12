#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  while(!Serial);
  Serial.println("I2C Scanner");
}

void loop() {
  // put your main code here, to run repeatedly:
  byte error, address;

  int no_devices = 0;
  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error == 0) {
      Serial.print("I2C device found at address 0x");
      if(address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);

      no_devices++;
    }
    else if(error == 4) {
      Serial.print("Unknown error at address 0x");
            if (address < 16) {
                Serial.print("0");
            }
            Serial.println(address, HEX);
    }
  }

  if(no_devices == 0) Serial.println("No I2C devices found\n");
  else Serial.println("done\n");

  delay(5000);
}
