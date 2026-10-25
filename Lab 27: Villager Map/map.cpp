#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// Villager Name, Value: <Friendship Level, Species, Catachphrase>
using VillagerMap = map<string, tuple<int, string, string>>;

void printVillagers(const VillagerMap& villagers);
void increaseFriendship(const VillagerMap& villagers);
void decreaseFriendship(const VillagerMap& villagers);
void searchVillager(const VillagerMap& villagers);
void displayMenu();

int main() {
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    VillagerMap villagers;
    villagers["Audie"] = make_tuple(5, "Human", "Lets gooo!");
    villagers["Raymond"] = make_tuple(10, "Elf", "Magic! Magic! Magic!");
    villagers.insert({"Marshal", make_tuple(8, "Hobbit", "Why me?")});

    // access the map using a range-based for loop
    cout << "Villager Details:\nName [Friendship Level, Species, Catachphrase]" << endl;
    for (const auto& pair: villagers) {
        const string& name = pair.first;
        const auto& data = pair.second;
        cout << name << " [" << get<0>(data) << ", " << get<1>(data) << ", " << get<2>(data) << "]\n";
    }

    // Driver Test
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {
        auto& data = it->second;
        cout << "\nFound " << searchKey << ": [" << get<0>(data) << ", " << get<1>(data) << ", " << get<2>(data) << "]\n";
    }

    int choice = 0;
    while(choice != 4) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                increaseFriendship(villagers);
                printVillagers(villagers);
                break;
            case 2:
                decreaseFriendship(villagers);
                printVillagers(villagers);
                break;
            case 3:
                searchVillager(villagers);
                break;
            case 4:
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
    cout << "1. Increase Friendship\n2. Decrease Friendship\n3.Search for Villager\n4. Exit\nEnter choice: ";
}



void increaseFriendship(const VillagerMap& villagers) {
    string name;
    cout << "Enter villager name: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int lvl = get<0>(it->second);
        lvl = min(10, lvl+1);
        cout << name << "'s friendship level is now " << lvl << ".\n";
    } else {
        cout << "Villager " << name << " not found.\n";
    }
}

void decreaseFriendship(const VillagerMap& villagers) {
    string name;
    cout << "Enter villager name: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int lvl = get<0>(it->second);
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

