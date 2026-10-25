#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// Villager Name, Value: <Friendship Level, Species, Catachphrase>
using VillagerMap = map<string, tuple<int, string, string>>;

void printVillagers(const VillagerMap& villagers);
void increaseFriendship(VillagerMap& villagers);
void decreaseFriendship(VillagerMap& villagers);
void searchVillager(const VillagerMap& villagers);
void displayMenu();
void addVillager(VillagerMap& villagers);
void deleteVillager(VillagerMap& villagers);

int main() {
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    VillagerMap villagers = {
        {"Drago", {5, "Alligator", "Snap to It!"}},
        {"Kyle", {10, "Wolf", "Hubba hubba!"}}
    };
    villagers["Audie"] = make_tuple(5, "Human", "Lets gooo!");
    villagers["Raymond"] = make_tuple(10, "Elf", "Magic! Magic! Magic!");
    villagers.insert({"Marshal", make_tuple(8, "Hobbit", "Why me?")});


    int choice = 0;
    while(choice != 6) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addVillager(villagers);
                printVillagers(villagers);
                break;
            case 2:
                deleteVillager(villagers);
                printVillagers(villagers);
            case 3:
                increaseFriendship(villagers);
                printVillagers(villagers);
                break;
            case 4:
                decreaseFriendship(villagers);
                printVillagers(villagers);
                break;
            case 5:
                searchVillager(villagers);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
                break;
        }
    }
    return 0;
}

void displayMenu() {
    cout << "1. Add Villager\n2. Delete Villager\n3. Increase Friendship\n"
    << "4. Decrease Friendship\n5. Search for Villager\n6. Exit\nEnter choice: ";
}

void printVillagers(const VillagerMap& villagers) {
    cout << "\nVillager Details:" << endl;
    for (const auto& pair: villagers) {
        const string& name = pair.first;
        const auto& data = pair.second;
        cout << name << " [" << get<0>(data) << ", " << get<1>(data) << ", " << get<2>(data) << "]\n";
    }
    cout << endl;
}

void increaseFriendship(VillagerMap& villagers) {
    string name;
    cout << "Enter villager name: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int& lvl = get<0>(it->second);
        lvl = min(10, lvl+1);
        cout << name << "'s friendship level is now " << lvl << ".\n";
    } else {
        cout << "Villager " << name << " not found.\n";
    }
}

void decreaseFriendship(VillagerMap& villagers) {
    string name;
    cout << "Enter villager name: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int& lvl = get<0>(it->second);
        lvl = max(0, lvl-1);
        cout << name << "'s friendship level is now " << lvl << ".\n";
    } else {
        cout << "Villager " << name << " not found.\n";
    }
}

void searchVillager(const VillagerMap& villagers) {
    string name;
    cout << "Enter villager name: ";
    cin >> name;
    auto it = villagers.find(name);
    if (it != villagers.end()) {
        auto& data = it->second;
        cout << "\nFound " << name << ": [" << get<0>(data) << ", " << get<1>(data) << ", " << get<2>(data) << "]\n";
    } else {
        cout << "Villager " << name << " not found.\n";
    }
}

void addVillager(VillagerMap& villagers) {
    string name, species, catchphrase;
    int level;
    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship Level: ";
    cin >> level;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Species: ";
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, catchphrase);
    level = max(0, min(10, level));
    villagers[name] = make_tuple(level, species, catchphrase);
    cout << name << " added.\n";
}

void deleteVillager(VillagerMap& villagers) {
    string name;
    cout << "Villager name to delete: ";
    cin >> name;

    if (villagers.erase(name) > 0) {
        cout << name << " deleted\n";
    } else {
        cout << "Villager " << name << " not found.\n";
    }
}