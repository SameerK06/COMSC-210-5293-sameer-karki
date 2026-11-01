// Unit Test Driver for runSimulation()
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;
const int CELL_EVENTS = 5;
using CellEnvironment = map<string, array<list<string>, 3>>;
 
void displayCellState(const CellEnvironment& cell);
bool runSimulation(CellEnvironment& cell, int timePeriods);

int main() {
cout << "[Unit Test 3] Starting Comprehensive Simulation Test...\n";
    CellEnvironment testCell;
    testCell["Cell_Membrane"][0].push_back("Calcium_Ion");
    testCell["Nucleus"][1].push_back("mRNA_Messenger");
    testCell["Golgi_Appartus"][0].push_back("Raw_Protein");
    bool apoptosisTriggered = runSimulation(testCell, 30);
    
    cout << "\n=========================================\n";
    cout << "[Unit Test 3] RESULTS\n";
    cout << "=========================================\n";

    cout << "1. Verify Apoptosis Clearing...\n";
    if (apoptosisTriggered) {
        if (testCell.empty()) {
            cout << "   (PASS) Apoptosis triggered and cell environment was fully cleared.\n";
        } else {
            cout << "   (FAIL) Apoptosis triggered but cell environment is NOT empty.\n";
        }
    } else {
        cout << "   (SKIP) Apoptosis did not trigger this run.\n";
    }

    cout << "2. Verify Transport...\n";
    if (apoptosisTriggered) {
        cout << "   (SKIP) Cell cleared by Apoptosis. Cannot verify Transport.\n";
    } else {
        if (testCell.count("Mitochondria") && !testCell.at("Mitochondria")[0].empty() && testCell.at("Mitochondria")[0].front() == "Calcium_Ion") {
            cout << "   (PASS) Calcium_Ion transported to Mitochondria.\n";
        } else {
            cout << "   (FAIL) Transport did not occur.\n";
        }
    }

    cout << "3. Verify Synthesis...\n";
    if (apoptosisTriggered) {
        cout << "   (SKIP) Cell cleared by Apoptosis. Cannot verify Synthesis.\n";
    } else {
        if (testCell.count("Mitochondria") && !testCell.at("Mitochondria")[2].empty() && testCell.at("Mitochondria")[2].back() == "ATP") {
            cout << "   (PASS) ATP Synthesis verified.\n";
        } else {
            cout << "   (FAIL) Synthesis did not occur (or ATP was consumed).\n";
        }
    }

    cout << "4. Verify Stress...\n";
    if (apoptosisTriggered) {
        cout << "   (SKIP) Cell cleared by Apoptosis. Cannot verify Stress.\n";
    } else {
        if (testCell.count("Cell_Membrane") && !testCell.at("Cell_Membrane")[0].empty() && testCell.at("Cell_Membrane")[0].front() == "Na+") {
            cout << "   (PASS) Na+ Stress influx verified.\n";
        } else {
            cout << "   (FAIL) Stress did not occur (or Na+ was exchanged for K+).\n";
        }
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

bool runSimulation(CellEnvironment& cell, int timePeriods) {
    srand(time(0));
    for (int t = 1; t <= timePeriods; t++) {
        for (int eventCount = 1; eventCount <= CELL_EVENTS; eventCount++) {
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
                    cout << " > [t=" << t << "] APOPTOSIS: Cell self-destructed due to stress.\n";
                    cout << "[SYSTEM] Simulation complete.\n\n";
                    cout << "[SYSTEM] Final State\n";
                    displayCellState(cell);
                    cell.clear();
                    return true;
                }
            }
            if (chance >= 90 && chance <= 95) {
                cell["Nucleus"][2].push_back("Replicated_DNA");
                cout << " > DNA REPLICATION: Copied genetic material.\n";
            }
            if (chance == 70) { 
                if (!cell["Golgi_Appartus"][0].empty()) {
                    cell["Golgi_Appartus"][0].pop_front();
                    cell["Vesicle"][0].push_back("Packaged_Protein");
                    cout << " > PACKAGING: Protein prepped for transport.\n";
                }
            }
        }
    }
    cout << "[SYSTEM] Simulation complete.\n\n";
    return false;
}