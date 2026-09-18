#include <iostream>
#include <fstream>
#include <array>

using namespace std;

const int SIZE = 30;
const string FILENAME = "exercise.txt";

int main() {
    array<double, SIZE> tempArray{};
    ifstream inFile(FILENAME);
    if (!inFile) {
        // No sure if I was allowed to use cerr, so I used cout instead
        cout << "Error opening file: " << FILENAME << endl;
        return 1;
    }
    for (int i=0; i<SIZE; i++) {
        inFile >> tempArray[i];
    }
    inFile.close();
    return 0;
}
