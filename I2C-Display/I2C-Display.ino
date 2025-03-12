#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initializes LCD at address 0x27 for a 16x2 display.

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
}

void loop() {
  int count = 0;
  lcd.setCursor(0, 0);
  lcd.print("LETS COUNT!");
  delay(2000);
  lcd.clear();

  int rows = 2;
  int cols = 16;

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      lcd.setCursor(j, i);
      lcd.print(min(j,9));
      delay(500);
    }
  }
}
