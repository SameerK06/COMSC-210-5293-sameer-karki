#include "Car.h"
#include <deque>

const int INITIAL_CAPACITY = 2;

int main() {
    deque<Car> tollBooth;
    for (int i=0; i < INITIAL_CAPACITY; i++) {
        Car car;
        tollBooth.push_back(car);
    }
    cout << "Inital Queue:\n\t";
    // Iterator Loop
    for (auto it = tollBooth.begin(); it != tollBooth.end(); it++) {
        it->print();
        cout << "\t";
    }
    // range-based For Loop
    for (Car& toll : tollBooth) {
        toll.print();
        cout << "\t";
    }
    cout << "\n\n";
    return 0;
}
