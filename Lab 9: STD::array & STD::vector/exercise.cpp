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

    cout << "Array Properties: " << endl;
    cout << "Size: " << tempArray.size() << endl;
    cout << "Max Size: " << tempArray.max_size() << endl;
    cout << "Empty: " << (tempArray.empty() ? "Yes" : "No") << endl;
    cout << "First Element: " << tempArray.front() << endl;
    cout << "Last Element: " << tempArray.back() << endl;
    cout << "Data Pointer: " << tempArray.data() << endl;
    cout << endl << "Elements: \n";
    for (int i=0; i<SIZE; i++) {
        if (i % 2 == 0) {
            cout << "Reading " << i+1 << ": " << tempArray.at(i) << "\n";
        } else {
            cout << "Reading " << i+1 << ": " << tempArray[i] << "\n";
        }
        
    }
    // Using pointer for array
    cout << endl << "Elements using pointer: \n";
    for (int i=0; i<SIZE; i++) {
        cout << "Reading " << i+1 << ": " << *(tempArray.begin() + i) << "\n";
    }
    
    // List first 5 and last 5 elements of the array
    for (double* i = tempArray.begin(); i < tempArray.begin() + 5; i++) {
        cout << "First 5 Elements: " << *i << endl;
    }
    for (double* i = tempArray.end() - 5; i < tempArray.end(); i++) {
        cout << "Last 5 Elements: " << *i << endl;
    }
    return 0;
}
