#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2 ) + 3;
        const int MIN = 10000, MAX = 99999;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1)) + MIN / (double) 100;
    }
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }
    ~Chair() {
        delete[] prices;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    // Random number generator
    srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    cout << "Chair 1 (built using setters)" << endl;
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    cout << "Living Room Chair (built using parameterized constructor)" << endl;
    double livingChairPrices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, livingChairPrices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair object
    Chair *collection = new Chair[SIZE];
    cout << "Collection of Chairs:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Collection Item " << i + 1 << ":" << endl;
        collection[i].print();
    }
    delete[] collection;
    
    return 0;
}