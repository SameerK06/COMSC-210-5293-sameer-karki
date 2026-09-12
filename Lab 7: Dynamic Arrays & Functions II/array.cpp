#include <iostream>
#include <string>

using namespace std;

void displayArray(const string* arr, int size);
string* reverseArray(string* arr, int size);

int main() {
    const int SIZE = 5;
    string* arr = new string[SIZE]{"Bob", "bob1", "bob2", "bob3", "bob4"};
    cout << "Original array: ";
    displayArray(arr, SIZE);
    cout << endl;
    cout << "Reversed array: ";
    displayArray(reverseArray(arr, SIZE), SIZE);
    delete[] arr;
    arr = nullptr;
    return 0;
}

void displayArray(const string* arr, int size) {
    for (int i=0; i<size; ++i) {
        cout << *(arr+i) << " ";
    }
    cout << endl;
}

string* reverseArray(string* arr, int size) {
    for (int i=0; i<size/2; ++i) {
        string temp = *(arr+i);
        *(arr+i) = *(arr+ (size-1-i));
        *(arr + (size-1-i)) = temp;
    }
    return arr;
}



