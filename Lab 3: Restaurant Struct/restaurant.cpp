#include <iostream>
#include <string>
#include <fstream>

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
void displayRestaurant(const Restaurant& restaurant);

int main() {
    // Creating a Restaurant object using the createRestaurant function with user input
    Restaurant restaurant = createRestaurant();

    // Creating a Restaurant object using the createRestaurant function with file input
    Restaurant restaurantList[5];
    ifstream inputFile("restaurants.txt");
    if (inputFile.is_open()) {
        for (int i = 0; i < 5; i++) {
            getline(inputFile, restaurantList[i].name);
            getline(inputFile, restaurantList[i].address);
            for (int j = 0; j < 5; j++) {
                getline(inputFile, restaurantList[i].cuisines[j]);
                inputFile >> restaurantList[i].cuisinesPrice[j];
                inputFile.ignore();
            }
            inputFile >> restaurantList[i].rating;
            inputFile >> restaurantList[i].isOpen;
            inputFile >> restaurantList[i].isRecommended;
            inputFile.ignore();
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    // Display the details of the restaurant created using user input
    cout << endl << "Restaurant Details:" << endl;
    displayRestaurant(restaurant);
    cout << endl;
    // Display the details of the restaurants created using file input
    cout << endl << "Restaurant List:" << endl;
    for (int i = 0; i < 5; i++) {
        displayRestaurant(restaurantList[i]);
        cout << endl;
    }
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

void displayRestaurant(const Restaurant& restaurant) {
    cout << "Restaurant Name: " << restaurant.name << endl;
    cout << "Address: " << restaurant.address << endl;
    cout << "Cuisines:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  " << restaurant.cuisines[i] << " - $" << restaurant.cuisinesPrice[i] << endl;
    }
    cout << "Rating: " << restaurant.rating << endl;
    cout << "Open: " << (restaurant.isOpen ? "Yes" : "No") << endl;
    cout << "Recommended: " << (restaurant.isRecommended ? "Yes" : "No") << endl;
}