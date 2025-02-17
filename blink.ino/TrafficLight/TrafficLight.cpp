#include "TrafficLight.h"
#include <Arduino.h>  // Required for Serial.print()

// ✅ Constructor allocates memory for delay
TrafficLight::TrafficLight() : red(true), yellow(false), green(false), state(STATE::RED) {
    delay = new int(1000); // 🔥 Allocate delay dynamically
}

// ✅ Destructor properly deletes dynamic memory
TrafficLight::~TrafficLight() {
    delete delay;  // 🔥 Free the allocated memory
}

void TrafficLight::transition() {
    switch (state) {
        case RED:
            red = true; yellow = false; green = false;
            *delay = 10;
            break;
        case YELLOW_GREEN:
            red = false; yellow = true; green = true;
            *delay = 1;
            break;
        case GREEN:
            red = false; yellow = false; green = true;
            *delay = 20;
            break;
        case YELLOW:
            red = false; yellow = true; green = false;
            *delay = 4;
            break;
    }
    nextState();
}

int TrafficLight::nextState() { 
    state = (state == FLASHING_GREEN) ? RED : state + 1;
    return state;
}

int TrafficLight::getDelay() { return delay; }
bool  TrafficLight::getRed() { return red; }
bool  TrafficLight::getYellow() { return yellow; }
bool  TrafficLight::getGreen() { return green; }
bool TrafficLight::isFlashingG() { return state == FLASHING_GREEN; }

void TrafficLight::printState() {
    switch (state) {
        case RED:
            Serial.println("RED");
            break;
        case YELLOW_GREEN:
            Serial.println("YELLOW-GREEN");
            break;
        case GREEN:
            Serial.println("GREEN");
            break;
        case YELLOW:
            Serial.println("YELLOW");
            break;
        case FLASHING_GREEN:
            Serial.println("FLASHING_GREEN");
            break;
        default:
            Serial.println("UNKNOWN");
            break;
    }
}
