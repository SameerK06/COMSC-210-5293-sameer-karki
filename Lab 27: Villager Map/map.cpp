#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    // Villager Name, Value: <Friendship Level, Species, Catachphrase>
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = make_tuple(5, "Human", "Lets gooo!");
    villagers["Raymond"] = make_tuple(10, "Elf", "Magic! Magic! Magic!");
    villagers.insert({"Marshal", make_tuple(8, "Hobbit", "Why me?")});

    // access the map using a range-based for loop
    cout << "Villager Details: " << endl;
    for (const auto& [name, data] : villagers) {
        cout << name << " [" << get<0>(data) << ", " << get<1>(data) << ", " << get<2>(data) << "]\n";
    }

    // Driver Test
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {
        auto& data = it->second;
    }


    // // access the map using iterators
    // cout << "\nVillagers and their favorite colors (iterators):" << endl;
    // for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
    //                                            it != villagerColors.end(); ++it) {
    //     cout << it->first << ": ";
    //     for (auto color : it->second) {
    //         cout << color << " ";
    //     }
    //     cout << endl;
    // }

    // // delete an element
    // villagerColors.erase("Raymond");

    // // search for an element using .find() to avoid errors
    // string searchKey = "Audie";
    // auto it = villagerColors.find(searchKey);
    // if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
    //                                    // if searchKey is not found
    //     cout << "\nFound " << searchKey << "'s favorite colors: ";
    //     for (auto color : it->second)  // range loop to traverse the value/vector
    //         cout << color << " ";
    //     cout << endl;
    // } else
    //     cout << endl << searchKey << " not found." << endl;

    // // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerColors.size() << endl;
    // villagerColors.clear();
    // cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
