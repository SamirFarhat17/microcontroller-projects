
#include <SPI.h>                // Include the SPI library for SPI communication
#include <MFRC522.h>            // Include the library for the RFID module
#include <Wire.h>               // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include the library for the I2C LCD

#define RST_PIN 9  // Reset pin for the RFID module
#define SS_PIN 10  // Slave select pin for the RFID module

// Create an instance of the MFRC522 class to interface with the RFID module
MFRC522 mfrc522(SS_PIN, RST_PIN);
// Create an instance of the LiquidCrystal_I2C class for the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);                         // Start serial communication at 9600bps
  SPI.begin();                                // Initialize the SPI bus
  mfrc522.PCD_Init();                         // Initialize the RFID reader
  lcd.init();                                 // Initialize the LCD display
  lcd.backlight();                            // Turn on the backlight of the LCD
  Serial.println(F("Ready to read a card"));  // Print a message to start read
}

void loop() {
  // Check if a new RFID card is present and can be read
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;  // If no new card is present, exit the loop
  }

  displayCardUID();           // Function to display the UID of the card
  readAndDisplayBlock(4);     // Function to read and display block4 of the RFID card
  mfrc522.PICC_HaltA();       // Halt the RFID card to stop reading
  mfrc522.PCD_StopCrypto1();  // Stop encryption on the communication
  delay(5000);                // Delay for 5 seconds
  lcd.clear();                // Clear the LCD display
}

// Function to display the UID of the RFID card
void displayCardUID() {
  Serial.print(F("Card UID:"));                  // Print the text "Card UID:"
  lcd.clear();                                   // Clear the LCD display
  lcd.setCursor(0, 0);                           // Set the LCD cursor to the top-left
  lcd.print("UID:");                             // Print "UID:" on the LCD
  for (byte i = 0; i < mfrc522.uid.size; i++) {  // Loop through each byte of the UID
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);  // Print UID byte in hexadecimal
    lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    lcd.print(mfrc522.uid.uidByte[i], HEX);  // Print UID byte on the LCD in hexadecimal
  }
  Serial.println();  // Print a newline on the serial monitor
}

// Function to authenticate and read a block from the RFID card
bool authenticateBlock(byte block, byte *buffer, byte &size) {
  MFRC522::StatusCode status;  // Variable to hold the status of RFID operations
  MFRC522::MIFARE_Key key;     // Variable to hold the authentication key
  // Set the key to the default key known as FFFFFFFFFFFFh
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;  // Default key A for authentication

  // Authenticate the desired block with the key
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return false;  // If authentication failed, return false
  }

  // Read the block after successful authentication
  status = mfrc522.MIFARE_Read(block, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return false;  // If reading failed, return false
  }
  buffer[size - 1] = '\0';  // Ensure the string is null-terminated
  return true;              // Return true if reading is successful
}

// Function to read a block and display its contents
void readAndDisplayBlock(byte block) {
  byte buffer[18];                               // Buffer to store the data read from the RFID card
  byte size = sizeof(buffer);                    // Variable to store the size of the data read
  if (authenticateBlock(block, buffer, size)) {  // If authentication and reading are successful
    lcd.setCursor(0, 1);                         // Set the cursor to the second line of the LCD
    lcd.print("Name: ");                         // Print "Name:"
    // Print the name starting from the second character to skip the size byte
    lcd.print((char *)buffer + 1);
    Serial.print("Name: ");
    Serial.println((char *)buffer + 1);  // Print the name on the serial monitor
  }
}
 