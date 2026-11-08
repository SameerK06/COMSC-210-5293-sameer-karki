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

void functionTesting();
void printToll(deque<Car> plaza[]);
void joinToll(deque<Car> plaza[], int index);
void payToll(deque<Car> plaza[], int index);
void switchToll(deque<Car> plaza[], int index);

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
    cout << "Initial queue:" << endl;
    printToll(plaza);
    for (int time = 1; time <= SIM_TIME; time++) {
        cout << "Time: " << time << endl;
        for (int i = 0; i < NUM_LANES; i++) {
            if (plaza[i].empty()) {
                // Range 0-49: 50%
                if (rand() % 100 < PROB_EMPTY_JOIN) {
                    Car newCar;
                    plaza[i].push_back(newCar);
                    cout << "Lane " << i+1 << " Joined: ";
                    plaza[i].back().print();
                }
            } else {
                int prob = rand() % 100;
                // Range 0-45: 46%
                if (prob < PROB_PAY) {
                    cout << "Lane: " << i+1 << " Paid: ";
                    plaza[i].front().print();
                    plaza[i].pop_front();
                // Range 46-84: 39%
                } else if (prob < (PROB_PAY+PROB_JOIN)) {
                    Car newCar;
                    plaza[i].push_back(newCar);
                    cout << "Lane: " << i+1 << " Joined: ";
                    plaza[i].back().print();
                // Range 85-99: 15%
                } else {
                    int newLane = rand() % NUM_LANES;
                    while (newLane == i) {
                        newLane = rand() % NUM_LANES;
                    }
                    cout << "Lane: " << i+1 << " Switched: ";
                    plaza[newLane].push_back(plaza[i].back());
                    plaza[i].pop_back();
                    plaza[newLane].back().print();
                }
            }
        }
        printToll(plaza);
        cout << endl;
    }

    return 0;
}

void printToll(deque<Car> plaza[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i+1 << " Queue: ";
        if (plaza[i].empty()) {
            cout << "empty" << endl;
        } else {
            cout << endl;
            for (Car& car : plaza[i]) {
                cout << "   ";
                car.print();
            }
        }
    }
}

void joinToll(deque<Car> plaza[], int index) {
    
}
void payToll(deque<Car> plaza[], int index);
void switchToll(deque<Car> plaza[], int index);

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