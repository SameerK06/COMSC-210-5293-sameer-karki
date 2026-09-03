#include <iostream>
#include <string>
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

Restaurant createRestaurant();

int main() {
    // Creating a Restaurant object using the createRestaurant function with user input
    Restaurant restaurant = createRestaurant();
}

Restaurant createRestaurant() {
    Restaurant restaurant;
    bool isOpen;
    bool isRecommended;
    cout << "What is the name of your Restaurant? ";
    getline(cin, restaurant.name);
    cout << "What is the address of your Restaurant? ";
    getline(cin, restaurant.address);
    for (int i = 0; i < 5; i++) {
        cout << "Enter cuisine " << i + 1 << ": ";
        getline(cin, restaurant.cuisines[i]);
        cout << "Enter price for " << restaurant.cuisines[i] << ": ";
        cin >> restaurant.cuisinesPrice[i];
        cin.ignore();
    }
    cout << "What is the rating of your Restaurant? ";
    cin >> restaurant.rating;
    cin.ignore();
    cout << "Is the restaurant open? (1 for yes, 0 for no): ";
    cin >> isOpen;
    restaurant.isOpen = isOpen == 1 ? true : false;
    cout << "Is the restaurant recommended? (1 for yes, 0 for no): ";
    cin >> isRecommended;
    restaurant.isRecommended = isRecommended == 1 ? true : false;
    return restaurant;
}