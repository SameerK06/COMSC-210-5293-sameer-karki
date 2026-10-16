#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;
    int choice = 0;
    while (choice != 4) {
        choice = main_menu();
        switch (choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                cout << "Exiting Goat Manager 3001. Goodbye!\n";
                break;
        }
    }
    return 0;
}

int main_menu() {
    int choice;
    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\n";
    cout << "Choice --> ";
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Please enter a number between 1 and 4.\nChoice --> ";
    }
    return choice;
}

void add_goat(list<Goat> &trip, string names[], string color[]) {
    string randName = names[rand() % SZ_NAMES];
    int randAge = rand() % (MAX_AGE + 1);
    string randColor = color[rand() % SZ_COLORS];
    Goat newGoat(randName, randAge, randColor);
    trip.push_back(newGoat);
    cout << "Woop! Woop! Woop!\nNew goat added: " << newGoat.get_name() << ", Age: " << newGoat.get_age() << ", Color: "
    << newGoat.get_color() << endl;
}

void display_trip(list<Goat> trip) {
    if (trip.empty()) {
        cout << "No goats in the trip.\n";
        return;
    }
    cout << "\n--- Curren Goat Trip ---\n";
    int index = 0;
    for (const Goat &g : trip) {
        cout << "   [" << index++ << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")\n";
    }
}

int select_goat(list<Goat> trip) {
    display_trip(trip);
    int choice;
    cout << "Select a goat to delete (1-" << trip.size() << ") -->";
    while (!(cin >> choice) || choice < 1 || choice > trip.size()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Please enter a number between 1 and  " << trip.size() << ".\nChoice --> ";
    }
    return choice;
}

void delete_goat(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "The trip is empty. No goats to delete.\n";
        return;
    }
    int choice = select_goat(trip);
    auto it = trip.begin();
    advance(it, choice - 1);
    cout << "\nDeleting goat: " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")\n";
    trip.erase(it);
}