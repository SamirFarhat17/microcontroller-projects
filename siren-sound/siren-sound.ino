const int buzzerPin = 9;  // Assigns the pin 9 to the constant for the buzzer

void setup() {
    // put your setup code here, to run once:
}

void loop() {
    // Gradually increase the pitch
    for (int freq = 100; freq <= 1000; freq += 10) {
        tone(buzzerPin, freq);  // Emit a tone
        delay(20);              // Wait before changing the frequency
    }

    // Gradually decrease the pitch
    for (int freq = 1000; freq >= 100; freq -= 10) {
        tone(buzzerPin, freq);  // Emit a tone
        delay(20);              // Wait before changing the frequency
    }
}