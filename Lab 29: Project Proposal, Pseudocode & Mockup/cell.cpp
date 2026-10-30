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