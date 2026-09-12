#include <iostream>

using namespace std;

void enterArrayData(double* arr, int size);
void outputArrayData(const double* arr, int size);

int main() {
    return 0;
}

void enterArrayData(double* arr, int size) {
    cout << "Enter " << size << " values for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Value " << (i + 1) << ": ";
        cin >> *(arr + i); 
    }
}

void outputArrayData(const double* arr, int size) {
    cout << "Array values are: [ " << endl;
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " "; 
    }
    cout << " ]" << endl;
}