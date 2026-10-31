// Alpha Version
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>

using namespace std;

using CellEnvironment = map<string, array<list<string>, 3>>;

// Function Prototypes
// Reads inital biochemical state from ext file
bool loadCellData(const string& filename, CellEnvironment& cell);
// Prints/Display map data to show state of cellular environment
void displayCellState(const CellEnvironment& cell);
// Simulate molecular events over discrete time steps
void runSimulation(CellEnvironment& cell, int timePeriods);

int main() {

    CellEnvironment eukaryoticCell;
    if (!loadCellData("cell_data.txt", eukaryoticCell)) {
        cout << "[SYSTEM] Error loading data. Please correct data or try again!\n";
        return 1;
    }

    cout << "[SYSTEM] Inital State\n";
    displayCellState(eukaryoticCell);

    int timeSteps = 30;
    cout << "\n[SYSTEM] Commencing simulation for " << timeSteps << " milliseconds...\n";
    runSimulation(eukaryoticCell, timeSteps);

    cout << "[SYSTEM] Final State\n";
    displayCellState(eukaryoticCell);

    return 0;
}

// Function Implementations

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
        if (t == 28) {
            for (int i = 0; i <= cell["Lysosome"][0].size(); i++) {
                cell["Lysosome"][0].pop_front();
            }
            cout << " > [t=28] EXOCYTOSIS: Waste removed from Lysosome.\n";
        }
    }
    cout << "[SYSTEM] Simulation complete.\n\n";
}