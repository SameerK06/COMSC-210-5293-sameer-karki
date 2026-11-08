#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INITIAL_CAPACITY = 2;
const int NUM_LANES = 4;
const int SIM_TIME = 20;
const int PROB_EMPTY_JOIN = 50;
const int PROB_PAY = 46;
const int PROB_JOIN = 39;
const int PROB_SWITCH = 15;

void functionTesting();
void printToll(deque<Car> plaza[]);

int main() {
    srand(time(0));
    // Testing structure
    // functionTesting();
    deque<Car> plaza[NUM_LANES];
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CAPACITY; j++) {
            Car car;
            plaza[i].push_back(car);
        }
    }
    cout << "Inital queue:" << endl;
    printToll(plaza);
    for (int time = 1; time <= SIM_TIME; time++) {
        cout << "Time: " << time << endl;
        for (int i = 0; i < NUM_LANES; i++) {
            if (plaza[i].empty()) {
                if (rand() % 100 < 50) {
                    Car newCar;
                    plaza[i].push_back(newCar);
                    cout << "Lane " << i+1 << " Joined: ";
                    plaza[i].back().print();
                }
            } else {
                
            }
        }
    }

    return 0;
}

void printToll(deque<Car> plaza[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i+1 << ":" << endl;
        for (Car& car : plaza[i]) {
            cout << "   ";
            car.print();
        }
    }
}

void functionTesting() {
    deque<Car> plaza[NUM_LANES];
    Car car1, car2, car3, car4, car5, car6, car7, car8, car9, car10;
    plaza[0].push_back(car1);
    plaza[1].push_back(car2);
    plaza[3].push_back(car4);
    plaza[0].push_back(car5);
    plaza[1].push_back(car6);
    plaza[3].push_back(car8);
    plaza[0].push_front(car9);
    for (int i = 0; i < NUM_LANES; i++) {
        if (!plaza[i].empty()) {
            cout << "Lane " << i+1 << "'s size: " << plaza[i].size() << " cars" << endl;
            cout << "The car at the front is: ";
            plaza[i].front().print();
            cout << "The car at the back is ";
            plaza[i].back().print();
            cout << "Removing the car from the back and front of the lane: ";
            plaza[i].pop_back();
            plaza[i].pop_front();
            cout << "Lane " << i+1 << "'s new size: " << plaza[i].size() << " cars" << endl;
        } else {
            cout << "Lane " << i+1 << " is empty!" << endl;
        }
    }
}