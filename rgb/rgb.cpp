#include "rgb.h"
#include <ctype.h>
#include <string.h>

enum class Color {
    red, 
    green,
    blue, 
    yellow,
    pink,
    cyan, 
    white
};

int RGB::getRed() {
    return red;
}

int RGB::getBlue() {
    return blue;
}

int RGB::getGreen() {
    return green;
}

Color hashString(const char* str) {
    if(strcmp(str, "RED") == 0) return Color::red;
    if(strcmp(str, "GREEN") == 0) return Color::green;
    if(strcmp(str, "BLUE") == 0) return Color::blue;
    if(strcmp(str, "YELLOW") == 0) return Color::yellow;
    if(strcmp(str, "PINK") == 0) return Color::pink;
    if(strcmp(str, "CYAN") == 0) return Color::cyan;
    return Color::white;
}


void RGB::setColor(char* s) {
    for(int i = 0; s[i] != '\0'; i++) s[i] = static_cast<char>(toupper(static_cast<unsigned char>(s[i])));
    switch(hashString(s)) {
        case Color::red :
            red = 128;
            blue = 0;
            green = 0;
            break;
            case Color::green :
            red = 0;
            green = 128;
            blue = 0;
            break;
        case Color::blue :
            red = 0;
            green = 0;
            blue = 128;
            break;
        case Color::yellow :
            red = 226;
            green = 128;
            blue = 37;
            break;
        case Color::pink :
            red = 238;
            green = 138;
            blue = 248;
            break;
        case Color::cyan :
            red = 115;
            green = 251;
            blue = 253;
            break;
        default:
            red = 255;
            green = 255;
            blue = 255;
            break;
    }
}

