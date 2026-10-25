#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(const set<Goat> &trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(const set<Goat> &trip);
int main_menu();


void milestone_1_find(const set<Goat> &trip);       // std::find_if
void milestone_2_count(const set<Goat> &trip);      // std::count_if
void milestone_3_for_each(const set<Goat> &trip);   // std::for_reach
void milestone_4_accumulate(const set<Goat> &trip); // std::accumulate
void milestone_5_min_max(const set<Goat> &trip);    // std::min_element and std::max_element
void milestone_6(const set<Goat> &trip);            // std::
void milestone_7(const set<Goat> &trip);            // std::
void milestone_8(const set<Goat> &trip);            // std::

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

    set<Goat> trip;
    int choice = 0;
    while (choice != 12) {
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
                milestone_1_find(trip);
                break;
            case 5:
                milestone_2_count(trip);
                break;
            case 6:
                milestone_3_for_each(trip);
                break;
            case 7:
                milestone_4_accumulate(trip);
                break;
            case 8:
                milestone_5_min_max(trip);
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                cout << "Exiting Goat Manager 3001. Goodbye!\n";
                break;
        }
    }
    return 0;
}

int main_menu() {
    int choice;
    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Find goat by name\n";
    cout << "[5] Count goats older than age\n";
    cout << "[6] Display formatted goat badges\n";
    cout << "[7] Calculate total and average age\n";
    cout << "[8] Find youngest and oldest goats\n";
    cout << "[9] \n";
    cout << "[10] \n";
    cout << "[11] \n";
    cout << "[12] Quit\n";
    cout << "Choice --> ";
    while (!(cin >> choice) || choice < 1 || choice > 12) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Please enter a number between 1 and 12.\nChoice --> ";
    }
    return choice;
}

void add_goat(set<Goat> &trip, string names[], string color[]) {
    string randName = names[rand() % SZ_NAMES];
    int randAge = rand() % (MAX_AGE + 1);
    string randColor = color[rand() % SZ_COLORS];
    Goat newGoat(randName, randAge, randColor);
    trip.insert(newGoat);
    cout << "Woop! Woop! Woop!\nNew goat added: " << newGoat.get_name() << ", Age: " << newGoat.get_age() << ", Color: "
    << newGoat.get_color() << endl;
}

void display_trip(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats in the trip.\n";
        return;
    }
    cout << "\n--- Curren Goat Trip ---\n";
    int index = 0;
    for (const Goat &g : trip) {
        cout << "   [" << ++index << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")\n";
    }
}

int select_goat(const set<Goat> &trip) {
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

void delete_goat(set<Goat> &trip) {
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

void milestone_1_find(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nTrip is empty.\n";
        return;
    }
    string targetName;
    cout << "\nEnter exact name to search for: ";
    cin >> targetName;
    auto it = find_if(trip.begin(), trip.end(), [&targetName](const Goat &g) {
        return g.get_name() == targetName;
    });
    if (it != trip.end()) {
        cout << "Found Goat! Name: " << it->get_name() << ", Age: " << it->get_age() << ", Color: " << it->get_color()
        << endl;
    } else {
        cout << "No goat named \"" << targetName << "\" was found in the trip.\n";
    }
}

void milestone_2_count(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nTrip is empty.\n";
        return;
    }
    int minAge;
    cout << "\nEnter threshold age: ";
    while(!(cin >> minAge)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter an integer: ";
    }
    int count = count_if(trip.begin(), trip.end(), [minAge](const Goat &g) {
        return g.get_age() > minAge;
    });
    cout << "Number of goats older than " << minAge << ": " << count << endl;
}

void milestone_3_for_each(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nTrip is empty.\n";
        return;
    }
    cout << "\n--- Goat Badges ---\n";
    for_each(trip.begin(), trip.end(), [](const Goat &g) {
        cout << "+---------------------------------------+\n";
        cout << "| Name:  "<< left << setw(30) << g.get_name() << "|\n";
        cout << "| Age:   "<< left << setw(30) << g.get_age() << "|\n";
        cout << "| Color: "<< left << setw(30) << g.get_color() << "|\n";
        cout << "+---------------------------------------+\n";
    });
}

void milestone_4_accumulate(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nTrip is empty.\n";
        return;
    }
    int totalAge = accumulate(trip.begin(), trip.end(), 0, [](int sum, const Goat &g) {
        return sum + g.get_age();
    });
    double avgAge = static_cast<double>(totalAge)/trip.size();
    cout << fixed << setprecision(2);
    cout << "\nTotal Age of All Goats: " << totalAge << " years\n";
    cout << "Average Goat Age:       " << avgAge << " years\n";
}

void milestone_5_min_max(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nTrip is empty.\n";
        return;
    }
    auto minIt = min_element(trip.begin(), trip.end(), [](const Goat &a, const Goat &b) {
        return a.get_age() < b.get_age();
    });
    auto maxIt = max_element(trip.begin(), trip.end(), [](const Goat &a, const Goat &b) {
        return a.get_age() < b.get_age();
    });
    cout << "\nYoungest Goat: " << minIt->get_name() << " (" << minIt->get_age() << " years, " 
    << minIt->get_color() << ")\n";
    cout << "\nOldest Goat: " << maxIt->get_name() << " (" << maxIt->get_age() << " years, " 
    << maxIt->get_color() << ")\n";
}