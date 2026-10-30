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
    // if file not open, return false
    // while reading, take organelle, catergory index and molecular name
    // insert moleule to cellular map (MAP[organelle][catergoy_index])
    // return true
}

void displauCellState(const CellEnvironment& cell) {
    // PSEUDO:
    // for each key-value pair in map:
    //  print key, values: ion list (index 0), protein list (index 1) and metabolites list (index 2)
}

void runSimulation(CellEnvironment& cell, int timePeriods) {
    // PSEUDO:
    // for t time at 1 to timePeriods
    //  Iterate through map
    //  Apply events
    //   - Transport: pop_front() and pop_back from one list to another
    //   - Synthesis: push_back() a new molecule at random chance
    //   - Environmntal Stress: push_back() random number of moleucles to a specific list.
}