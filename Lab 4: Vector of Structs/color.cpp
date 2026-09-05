#include <iostream>
#include <vector>
#include <cstdlib>

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

    // Milestone 2: Create an vector of Color objects with random RGB values
    vector<Color> colors;
    for(int i = 0; i < rand() % 6 + 25; i++) {
        Color newColor = {rand() % 256, rand() % 256, rand() % 256};
        colors.push_back(newColor);
    }
    
    // Milestone 3: Displaying a vector of Color objects in a table format using string literals
    cout << endl << "Milestone 3: Displaying a vector of Color objects in a table format:" << endl;
    cout << "Index\t\tRed\t\tGreen\t\tBlue\n-----\t\t---\t\t-----\t\t----" << endl;
    
    for (const Color& c : colors) {
        cout << &c - &colors[0] + 1 << "\t\t" 
             << c.red << "\t\t" 
             << c.green << "\t\t" 
             << c.blue << endl;
    }

    return 0;
}