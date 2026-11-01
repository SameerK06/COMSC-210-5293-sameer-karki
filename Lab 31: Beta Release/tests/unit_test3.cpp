// Unit Test Driver for runSimulation()
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <list>

using namespace std;
using CellEnvironment = map<string, array<list<string>, 3>>;

void runSimulation(CellEnvironment& cell, int timePeriods);

int main() {
    cout << "[Unit Test 3] Starting runSimulation Unit Test...\n";
    CellEnvironment testCell;
    testCell["Cell_Membrane"][0].push_back("Calcium_Ion");
    runSimulation(testCell, 30);
    cout << "[Unit Test 3] Verify Transport...\n";
    if (testCell["Mitochondria"][0].front() == "Calcium_Ion") {
        cout << "[Unit Test 3] (PASS) Verify Transport.\n";
    } else {
        cout << "[Unit Test 3] (FAIL) Verify Transport.\n";
    }
    cout << "[Unit Test 3] Verify Synthesis...\n";
    if (testCell["Mitochondria"][2].back() == "ATP") {
        cout << "[Unit Test 3] (PASS) Verify Synthesis.\n";
    } else {
        cout << "[Unit Test 3] (FAIL) Verify Synthesis.\n";
    }
    cout << "[Unit Test 3] Verify Stress...\n";
    if (testCell["Cell_Membrane"][0].size() == 2 && testCell["Cell_Membrane"][0].front() == "Na+") {
        cout << "[Unit Test 3] (PASS) Verify Stress.\n";
    } else {
        cout << "[Unit Test 3] (FAIL) Verify Stress.\n";
    }
    return 0;
}

void runSimulation(CellEnvironment& cell, int timePeriods) {
    for (int t = 1; t <= timePeriods; t++) {
        for (int eventCount = 1; eventCount <= 30; eventCount++) {
            srand(time(0));
            int chance = (rand() % 100) + 1;
            if (chance <= 20) {
                cell["Mitochondria"][2].push_back("ATP");
                cout << " > [t=" << t << "] SYNTHESIS: ATP created in Mitochondria.\n";
            } 
            else if (chance <= 40) {
                cell["Cell_Membrane"][0].push_back("Na+");
                cell["Cell_Membrane"][0].push_back("Na+");
                cout << " > [t=" << t << "] STRESS: Sudden influx of Na+ at the Cell_Membrane.\n";
            } 
            else if (chance <= 55) {
                if (!cell["Cell_Membrane"][0].empty()) {
                    string ion = cell["Cell_Membrane"][0].front();
                    cell["Cell_Membrane"][0].pop_front();
                    cell["Mitochondria"][0].push_back(ion);
                    cout << " > [t=" << t << "] Transport: " << ion << " moved from Cell_Membrane to Mitochondria.\n";
                }
            }
            else if (chance <= 65) {
                if (!cell["Nucleus"][1].empty()) {
                    string messenger = cell["Nucleus"][1].front();
                    cell["Nucleus"][1].pop_front();
                    cell["Ribosome"][2].push_back("Protein");
                    cout << " > [t=" << t << "] TRANSLATION: Protein created in Ribosome from " << messenger << ".\n";
                }
            }
            else if (chance <= 70) {
                cell["Lysosome"][0].clear();
                cout << " > [t=" << t << "] EXOCYTOSIS: Waste removed from Lysosome.\n";
            }
            else if (chance <= 85) {
                if(!cell["Mitochondria"][2].empty() && cell["Mitochondria"][2].back() == "ATP") {
                    cell["Mitochondria"][2].pop_back();
                    auto it = cell["Cell_Membrane"][0].begin();
                    while (it != cell["Cell_Membrane"][0].end()) {
                        if (*it == "Na+") {
                            it = cell["Cell_Membrane"][0].erase(it);
                            cell["Cell_Membrane"][0].push_back("K+");
                        } else {
                            ++it;
                        }
                    }
                    cout << " > [t=" << t << "] ACTIVE TRANSPORT: Na+ exchanged for K+ using ATP.\n";
                }
            }
            else if (chance >= 99) {
                if (cell["Cell_Membrane"][0].size() > 5) {
                    cell.clear();
                    cout << " > [t=" << t << "] APOPTOSIS: Cell self-destructed due to stress.\n";
                    cout << "[SYSTEM] Simulation complete.\n\n";
                    return;
                }
            }
        }
    }
    cout << "[SYSTEM] Simulation complete.\n\n";
}