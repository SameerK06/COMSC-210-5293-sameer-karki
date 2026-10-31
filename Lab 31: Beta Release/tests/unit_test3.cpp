// Unit Test Driver for runSimulation()
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <list>

// cout << "[Unit Test 3]

using namespace std;
using CellEnvironment = map<string, array<list<string>, 3>>;

void runSimulation(CellEnvironment& cell, int timePeriods);

int main() {
    cout << "[Unit Test 2] Starting runSimulation Unit Test...\n";
    CellEnvironment testCell;
    testCell["Cell_Membrane"][0].push_back("Calcium_Ion");
    runSimulation(testCell, 30);
    cout << "[Unit Test 2] Verify Transport...\n";
    if (testCell["Mitochondria"][0].front() == "Calcium_Ion") {
        cout << "[Unit Test 2] (PASS) Verify Transport.\n";
    } else {
        cout << "[Unit Test 2] (FAIL) Verify Transport.\n";
    }
    cout << "[Unit Test 2] Verify Synthesis...\n";
    if (testCell["Mitochondria"][2].back() == "ATP") {
        cout << "[Unit Test 2] (PASS) Verify Synthesis.\n";
    } else {
        cout << "[Unit Test 2] (FAIL) Verify Synthesis.\n";
    }
    cout << "[Unit Test 2] Verify Stress...\n";
    if (testCell["Cell_Membrane"][0].size() == 2 && testCell["Cell_Membrane"][0].front() == "Na+") {
        cout << "[Unit Test 2] (PASS) Verify Stress.\n";
    } else {
        cout << "[Unit Test 2] (FAIL) Verify Stress.\n";
    }
    return 0;
}

void runSimulation(CellEnvironment& cell, int timePeriods) {
    for (int t = 1; t <= timePeriods; t++) {
        if (t == 10) {
            if (!cell["Cell_Membrane"][0].empty()) {
                string ion = cell["Cell_Membrane"][0].front();
                cell["Cell_Membrane"][0].pop_front();
                cell["Mitochondria"][0].push_back(ion);
                cout << " > [t=10] Transport: " << ion << " moved from Cell_Membrane to Mitochondria.\n";
            }
        }
        if (t == 15) {
            cell["Mitochondria"][2].push_back("ATP");
            cout << " > [t=15] SYNTHESIS: ATP created in Mitochondria.\n";
        }
        if (t == 20) {
            if (!cell["Nucleus"][1].empty()) {
                string messenger = cell["Nucleus"][1].front();
                cell["Nucleus"][1].pop_front();
                cell["Ribosome"][2].push_back("Protein");
                cout << " > [t=20] TRANSLATION: Protein created in Ribosome from " << messenger << ".\n";
            }
        }
        if (t == 25) {
            cell["Cell_Membrane"][0].push_back("Na+");
            cell["Cell_Membrane"][0].push_back("Na+");
            cout << " > [t=25] STRESS: Sudden influx of Na+ at the Cell_Membrane.\n";
        }
    }
    cout << "[SYSTEM] Simulation complete.\n\n";
}