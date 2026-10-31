// Pseudocode + Wireframe
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
    // Initialize cellular map
    
    // Open external file and load at minimum 100 lines of molecular data
    // PSEUDO
    // if loadCellData returns true good else throw error

    // Display Inital State
    // cout << "inital state\n" << displayCellState(cell) << endl;

    // Run time-based event simulation
    // PSEUDO:
    // Time periods to 30
    // Call runSimulation passing map and number of periods

    // Display final state of the event after the simulation

    // WIREFRAME
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
    // PSEUDO:
    // for each key-value pair in map:
    //  print key, values: ion list (index 0), protein list (index 1) and metabolites list (index 2)
    
    // WIREFRAME
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
    // PSEUDO:
    // for t time at 1 to timePeriods
    //  Iterate through map
    //  Apply events
    //   - Transport: pop_front() and pop_back from one list to another
    //   - Synthesis: push_back() a new molecule at random chance
    //   - Environmntal Stress: push_back() random number of moleucles to a specific list.

    // WIREFRAME
    for (int t = 1; t <= timePeriods; t++) {
        if (t == 10) {
            cout << "[t=10] Event 1 (Transport): Ca2+ actively transported to Mitochondria.\n";
            cell["Mitochondria"][0].push_back("Ca2+");
        }
        if (t == 15) {
            cout << "[t=15] Event 2 (Synthesis): ATP synthesized in Mitochondria.\n";
            cell["Mitochondria"][2].push_back("ATP");
        }
        if (t == 25) {
            cout << "[t=25] Event 3 (Environmental Stress): Sudden influx of Na+ into Cell_Membrane.\n";
            cell["Cell_Membrane"][0].push_back("Na+");
            cell["Cell_Membrane"][0].push_back("Na+");
            cell["Cell_Membrane"][0].push_back("Na+");
        }
    }
    cout << "[SYSTEM] Simulation complete.\n";
}