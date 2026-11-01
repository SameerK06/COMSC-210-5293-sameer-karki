// Unit Test Driver for displayCellState()
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <array>
#include <list>

using namespace std;
using CellEnvironment = map<string, array<list<string>, 3>>;

void displayCellState(const CellEnvironment& cell);

int main() {
    cout << "[Unit Test 2] Starting displayCellState Unit Test...\n";
    CellEnvironment testCell;
    testCell["Nucleus"][0].push_back("Ion1");
    testCell["Nucleus"][1].push_back("Prot1");
    testCell["Nucleus"][2].push_back("Meta1");
    stringstream captureBuffer;
    streambuf* oldCoutBuffer = cout.rdbuf(captureBuffer.rdbuf());
    displayCellState(testCell);
    cout.rdbuf(oldCoutBuffer);
    string capturedOutput = captureBuffer.str();
    string expectedOutput = "Organelle: Nucleus\n [0] Ions:    Ion1 \n [1] Proteins:   Prot1 \n [2] Metabolites:   Meta1 \n\n";
    cout << "\n[Unit Test 2] (TEST OUTPUT LOG)\n";
    cout << capturedOutput;
    cout << "[Unit Test 2] (END TEST OUTPUT LOG)\n\n";
    if (capturedOutput == expectedOutput) {
        cout << "[Unit Test 2] (PASS) Display formatted the map contents exactly as expected.\n";
    } else {
        cout << "[Unit Test 2] (FAIL) Display formatting did not match expected output.\n";
    }
    return 0;
}

void displayCellState(const CellEnvironment& cell) {
    for (const auto& pair: cell) {
        cout << "Organelle: " << pair.first << "\n [0] Ions:    ";
        for (const auto& item : pair.second[0]) {
            cout << item << " ";
        }
        cout << "\n [1] Proteins:   ";
        for (const auto& item : pair.second[1]) {
            cout << item << " ";
        }
        cout << "\n [2] Metabolites:   ";
        for (const auto& item : pair.second[2]) {
            cout << item << " ";
        }
        cout << "\n\n";
    }
}