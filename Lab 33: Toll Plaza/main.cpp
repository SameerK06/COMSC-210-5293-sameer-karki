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
    return 0;
}