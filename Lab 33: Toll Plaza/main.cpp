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

void printToll(deque<Car> plaza[]);

int main() {
    srand(time(0));
    deque<Car> plaza[NUM_LANES];
    Car car1, car2, car3, car4, car5, car6, car7, car8, car9, car10;
    plaza[0].push_back(car1);
    plaza[1].push_back(car2);
    plaza[2].push_back(car3);
    plaza[3].push_back(car4);
    plaza[0].push_back(car5);
    plaza[1].push_back(car6);
    plaza[2].push_back(car7);
    plaza[3].push_back(car8);
    plaza[0].push_front(car9);
    plaza[2].push_front(car10);

    for (int i = 0; i < NUM_LANES; i++) {
        if (!plaza[i].empty()) {
            cout << "Lane " << i+1 << "'s size: " << plaza[i].size() << " cars" << endl;
        } else {
            cout << "Lane " << i+1 << " is empty!" << endl;
        }
    }
    return 0;
}