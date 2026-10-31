// Unit Test Driver for loadCellData()
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>

using namespace std;
using CellEnvironment = map<string, array<list<string>, 3>>;
bool loadCellData(const string& filename, CellEnvironment& cell);

int main() {

}

bool loadCellData(const std::string& filename, CellEnvironment& cell) {
    ifstream file(filename);
    if(!file.is_open()) {
        return false;
    }
    string organelle;
    int catergoryIndex;
    string molecule;

    while (file >> organelle >> catergoryIndex >> molecule) {
        cell[organelle][catergoryIndex].push_back(molecule);
    }
    file.close();
    return true; 
}