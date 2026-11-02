#include "Car.h"
#include <deque>

const int INITIAL_CAPACITY = 2;

int main() {
    deque<Car> tollBooth;
    for (int i=0; i < INITIAL_CAPACITY; i++) {
        Car car;
        tollBooth.push_back(car);
    }
    for (Car toll : tollBooth) {
        toll.print();
    }
    return 0;
}