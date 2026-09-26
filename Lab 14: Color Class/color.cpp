#include <iostream>

using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;

    int limit(int value) {
        if (value < 0) {
            return 0;
        } else if (value > 225) {
            return 225;
        } else {
            return value;
        }
    }
public:
    Color() : red(0), green(0), blue(0) {}
    Color(int r, int g, int b) {
        setRed(r);
        setBlue(g);
        setGreen(b);
    }

    void setRed(int r) {
        red = limit(r);
    }
    void setGreen(int g) {
        green = limit(g);
    }
    void setBlue(int b) {
        blue = limit(b);
    }
    
    int getRed() const {
        return red;
    }
    int getGreen() const {
        return green;
    }
    int getBlue() const {
        return blue;
    }

};

int main() {
    return 0;
}