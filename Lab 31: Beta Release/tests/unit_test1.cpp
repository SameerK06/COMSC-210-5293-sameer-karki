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
    cout << "[Unit Test 1] Starting loadCellData Unit Test\nCreating temporary test file: test_mock_data.txt...\n";
    ofstream testFile("test_mock_data.txt");
    testFile << "Nucleus 1 Test_Protein\n";
    testFile << "Mitochondria 2 Test_Metabolite\n";
    testFile.close();

    CellEnvironment testCell;

    cout << "[Unit Test 1] Test Valid File Processing and Valid Assert of Map...\n";
    bool result = loadCellData("test_mock_data.txt", testCell);
    if (result) {
        cout << "[Unit Test 1] (PASS) Test Valid File Processing\n";
        if (testCell["Nucleus"][1].front() == "Test_Protein") {
            cout << "[Unit Test 1] (PASS) Valid Assert of Map\n";
        } else {
            cout << "[Unit Test 1] (FAIL) Valid Assert of Map\n";
        }
    } else {
        cout << "[Unit Test 1] (FAIL) Test Valid File Processing\n";
    }

    cout << "[Unit Test 1] Test Valid Failure to Load...\n";
    CellEnvironment emptyCell;
    bool badResult = loadCellData("does_not_exist.txt", emptyCell);
    if (!badResult) {
        cout << "[Unit Test 1] (PASS) Test Valid Failure to Load\n";
    } else {
        cout << "[Unit Test 1] (FAIL) Test Valid Failure to Load\n";
    }
    return 0;
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