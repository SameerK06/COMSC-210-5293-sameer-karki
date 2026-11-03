#include "Car.h"
#include <deque>
#include <cstdlib>

const int INITIAL_CAPACITY = 2;

void printToll(deque<Car>& tollBooth);

int main() {
    deque<Car> tollBooth;
    for (int i=0; i < INITIAL_CAPACITY; i++) {
        Car car;
        tollBooth.push_back(car);
    }
    cout << "Inital Queue:\n";
    printToll(tollBooth);
    int time = 1;
    while(!tollBooth.empty()) {
        int prob = rand() & 100;
        if (prob < 55) {
            cout << "Time: " << time << " Operation: Car Paid: ";
            tollBooth.front().print();
            tollBooth.pop_front();
            printToll(tollBooth);
        } else {
            Car newCar;
            cout << "Time: " << time << " Operation: Joined lane: ";
            tollBooth.push_back(newCar);
            tollBooth.back().print();
            printToll(tollBooth);
        }
    }
    return 0;
}

void printToll(deque<Car>& tollBooth) {
    for (Car& toll : tollBooth) {
        cout << "\t";
        toll.print();
    }
    cout << "\n";
    return;
}