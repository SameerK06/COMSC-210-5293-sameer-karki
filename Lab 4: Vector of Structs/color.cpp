#include <iostream>

using namespace std;

struct Color {
    int red;
    int green;
    int blue;

    // Function to display the color values
    void displayColor() const {
        cout << "Color (RGB): (" << red << ", " << green << ", " << blue << ")" << endl;
    }

};

int main() {
    Color color = {255, 0, 0};
    color.displayColor();

    return 0;
}