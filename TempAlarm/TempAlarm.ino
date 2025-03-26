// Pin configurations
const int tempSensorPin = A0;  // NTC thermistor analog input
const int redPin = 4;         // Red LED digital pin
const int greenPin = 3;       // Green LED digital pin
const int bluePin = 2;        // Blue LED digital pin

// Constants for temperature calculation
const float beta = 3950.0;               // NTC thermistor's Beta value
const float seriesResistor = 10000;      // Series resistor value (ohms)
const float roomTempResistance = 10000;  // NTC resistance at 25°C
const float roomTemp = 25 + 273.15;      // Room temperature in Kelvin

void setup() {
    // Initialize LED pins as outputs
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // Start serial communication at 9600 baud
    Serial.begin(9600);
}

void loop() {
    int adcValue = analogRead(tempSensorPin);                     // Read thermistor value
    float resistance = (1023.0 / adcValue - 1) * seriesResistor;  // Calculate thermistor resistance

    // Calculate temperature in Kelvin using Beta parameter equation
    float tempK = 1 / (log(resistance / roomTempResistance) / beta + 1 / roomTemp);

    float tempC = tempK - 273.15;  // Convert to Celsius
    Serial.println(tempC);           //Display temperature in Celsius on Serial Monitor

    // Adjust LED color based on temperature
    if (tempC < 10) {
        setColor(0, 0, 255);  // Cold: blue
    } else if (tempC >= 10 && tempC <= 27) {
        setColor(0, 255, 0);  // Comfortable: green
    } else if (tempC > 27) { 
        setColor(255, 0, 0);  // Hot: red
    }
    delay(1000);  // Delay 1 second before next reading
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
    // Write PWM value for red, green, and blue to the RGB LED
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}