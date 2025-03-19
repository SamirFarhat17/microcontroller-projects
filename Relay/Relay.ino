int relayState = LOW;        // Initial state of the relay module
int lastButtonState = HIGH;  // the previous reading from the input pin

void setup() {
    pinMode(2, OUTPUT);        // Set pin 2 as output
    pinMode(7, INPUT_PULLUP);  // Set pin 7 as input with an internal pull-up resistor
}

void loop() {
    int buttonState = digitalRead(7);  // Read the state of the button
    // Check if button state has changed from the last loop iteration
    if (lastButtonState == HIGH && buttonState == LOW) {  // Button press detected
        relayState = !relayState;                           // Toggle relay module state
        digitalWrite(2, relayState);                        // Set the relay module state
    }
    lastButtonState = buttonState;  // Update lastButtonState to the current state
    delay(200);                     // Optional: Simple software debouncing
}