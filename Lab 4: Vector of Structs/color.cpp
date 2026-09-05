#include <iostream>
#include <vector>

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
    // Milestone 1: Create a Color object and display its values
    Color color = {255, 0, 0};
    cout << "Milestone 1: Displaying a single Color object:" << endl;
    color.displayColor();

    // Milestone 2: Create an vector of Color objects and display their values
    vector<Color> colors;
    for(int i = 0; i < rand() % 6 + 25; i++) {
        Color newColor = {rand() % 256, rand() % 256, rand() % 256};
        colors.push_back(newColor);
    }
    cout << endl << "Milestone 2: Displaying a vector of Color objects:" << endl;
    for(const auto& c : colors) {
        c.displayColor();
    }

    return 0;
}