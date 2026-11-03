#include "Car.h"
#include <deque>
#include <cstdlib>

const int INITIAL_CAPACITY = 2;

int main() {
    deque<Car> tollBooth;
    for (int i=0; i < INITIAL_CAPACITY; i++) {
        Car car;
        tollBooth.push_back(car);
    }
    cout << "Inital Queue:\n\t";
    for (Car& toll : tollBooth) {
        toll.print();
        cout << "\t";
    }
    cout << "\n\n";
    int time = 1;
    while(!tollBooth.empty()) {
        int prob = rand() & 100;
        if (prob < 55) {
            
        } else {

        }
    }
    return 0;
}
