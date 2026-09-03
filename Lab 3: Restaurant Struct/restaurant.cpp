#include <iostream>
using namespace std;

struct Restaurant {
    string name;
    string address;
    string cuisines[5];
    double cuisinesPrice[5];
    int rating;
    bool isOpen;
    bool isRecommended;
};

int main() {
    Restaurant mcDonalds;
}