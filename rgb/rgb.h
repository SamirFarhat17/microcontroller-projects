#ifndef RGB_H
#define RGB_H
class RGB {
private:
    int red;
    int blue;
    int green;
public:
    RGB() : red(0), blue(0), green(0) {}

    int getRed();
    int getBlue();
    int getGreen();
    void setColor(char* color);
};

#endif