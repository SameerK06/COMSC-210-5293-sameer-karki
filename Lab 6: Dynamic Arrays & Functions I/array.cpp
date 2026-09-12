#include <iostream>

using namespace std;

void enterArrayData(double* arr, int size);
void outputArrayData(const double* arr, int size);
double sumArray(const double* arr, int size);

int main() {
    const int SIZE = 5;
    double* arr = new double[SIZE];
    enterArrayData(arr, SIZE);
    outputArrayData(arr, SIZE);
    double sum = sumArray(arr, SIZE);
    cout << "Sum of array elements: " << sum << endl;
    delete[] arr;
    arr = nullptr;
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
    cout << "Array values are: [ ";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " "; 
    }
    cout << " ]" << endl;
}

double sumArray(const double* arr, int size) {
    double sum = 0.0;
    for (int i=0; i<size; ++i) {
        sum += *(arr + i);
    }
    return sum;
}