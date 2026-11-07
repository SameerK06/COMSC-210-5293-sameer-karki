#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INITIAL_CAPACITY = 2;
const int NUM_LANES = 4;

void printToll(deque<Car> plaza[]);

int main() {
    srand(time(0));
    deque<Car> plaza[NUM_LANES];
    // deque<Car> tollBooth;
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CAPACITY; j++) {
            Car car;
            plaza[i].push_back(car);
        }
    }
    cout << "Intial Queue:" << endl;
    printToll(plaza);





    // cout << "Initial ";
    // printToll(tollBooth);
    // int time = 1;
    // while(!tollBooth.empty()) {
    //     int prob = rand() % 100;
    //     if (prob < 55) {
    //         cout << "Time: " << time << " Operation: Car Paid: ";
    //         tollBooth.front().print();
    //         tollBooth.pop_front();
    //     } else {
    //         Car newCar;
    //         cout << "Time: " << time << " Operation: Joined lane: ";
    //         tollBooth.push_back(newCar);
    //         tollBooth.back().print();
    //     }
    //     printToll(tollBooth);
    //     time++;
    // }
    return 0;
}

void printToll(deque<Car> plaza[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i+1 << ": " << endl;
        for (Car& car : plaza[i]) {
            cout << "\t";
            car.print();
        }
    }
    return;
}