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