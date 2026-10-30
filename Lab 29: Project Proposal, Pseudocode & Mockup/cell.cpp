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

    return 0;
}

// Function Implementations

bool loadCellData(const std::string& filename, CellEnvironment& cell) {
    // PSEUDO:
    // open cell_data.txt
    // if file not open, thrown error
    // while reading, take organelle, catergory index and molecular name
    // insert moleule to cellular map (MAP[organelle][catergoy_index])
}