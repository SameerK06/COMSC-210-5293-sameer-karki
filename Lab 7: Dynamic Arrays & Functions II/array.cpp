#include <iostream>
#include <string>

using namespace std;

string* reverseArray(string* arr, int size);

int main() {
    return 0;
}

string* reverseArray(string* arr, int size) {
    for (int i=0; i<size/2; ++i) {
        string temp = *(arr+i);
        *(arr+i) = *(arr+ (size-1-i));
        *(arr + (size-1-i)) = temp;
    }
    return arr;
}

