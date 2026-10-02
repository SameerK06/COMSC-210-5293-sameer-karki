#include <iostream>
#include <string>

using namespace std;

class Color {
private:
    string name;
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
    Color() {
        setName("");
        setRed(0);
        setGreen(0);
        setBlue(0);
    }
    
    Color(string n, int r, int g, int b) {
        setName(n);
        setRed(r);
        setGreen(g);
        setBlue(b);
    }

    void setName(string name) { this->name = name; }
    void setRed(int red) { this->red = limit(red); }
    void setGreen(int green) { this->green = limit(green); }
    void setBlue(int blue) { this->blue = limit(blue); }

    string getName() const { return name; }
    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }

    void print() const {
        cout << getName() << ":\n"
        << "[ R: " << getRed()
        << " | G: " << getGreen()
        << " | B: " << getBlue() << " ]" << endl;
    }

};

int main() {
    Color pureRed("Pure Red", 255, 0, 0);
    Color pureGreen("Pure Green", 0, 255, 0);
    Color pureBlue("Pure Blue", 0, 0, 255);
    Color impossibleColor("Impossible Color", -1, 1000, 50);
    Color violet("Violet", 143, 0, 255);

    Color colors[5] = { pureRed, pureGreen, pureBlue, impossibleColor, violet };

    for (Color color: colors) {
        color.print();
    }

    return 0;
}