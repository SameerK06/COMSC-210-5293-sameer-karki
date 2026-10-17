#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Timer {
    time_point<high_resolution_clock> start_time;
    void start() {
        start_time = high_resolution_clock::now();
    }
    int stop() {
        auto end_time = high_resolution_clock::now();
        return duration_cast<milliseconds>(end_time - start_time).count();
    }
};

int main() {
    vector<string> rawData;
    ifstream fin("codes.txt");
    if (!fin) {
        cout << "Error opening file codes.txt" << endl;
        return 1; 
    }
    string code;
    while (fin >> code) {
        rawData.push_back(code);
    }
    fin.close();

    vector<string> v;
    list<string> l;
    set<string> s;
    Timer timer;
    int time_v, time_l, time_s;
    cout << left << setw(15) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set" << endl;
    cout << string(60, '-') << endl;
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/