#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

const int NUM_RUNS = 15, NUM_OPERATIONS = 4, NUM_CONTAINERS = 3, NUM_SLICES = 2;

void Race1(vector<string> &v, list<string> &l, set<string> &s, const vector<string> &rawData, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]); // Reading
void Race2(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]); // Sorting
void Race3(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]); // Inserting
void Race4(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]); //Deleting

struct Timer {
    time_point<high_resolution_clock> start_time;
    void start() {
        start_time = high_resolution_clock::now();
    }
    int stop() {
        auto end_time = high_resolution_clock::now();
        return duration_cast<nanoseconds>(end_time - start_time).count();
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

    // 3D array results[slice][operation][container]
    // Slice 0: Current time, Slice 1: Aggeregate time
    long results[NUM_SLICES][NUM_OPERATIONS][NUM_CONTAINERS] = {0};
    for (int run = 0; run < NUM_RUNS; run++) {
        vector<string> v;
        list<string> l;
        set<string> s;

        Race1(v, l, s, rawData, results[0]);
        Race2(v, l, s, results[0]);
        Race3(v, l, s, results[0]);
        Race4(v, l, s, results[0]);

        for (int operation = 0; operation < NUM_OPERATIONS; operation++) {
            for (int cont = 0; cont < NUM_CONTAINERS; cont++) {
                results[1][operation][cont] += results[0][operation][cont];
            }
        }
    }

    string operationNames[NUM_OPERATIONS] = {"Read", "Sort", "Insert", "Delete"};
    cout << "Number of simulations: " << NUM_RUNS << endl;
    cout << right << setw(11) << "Operation" << setw(11) << "Vector" << setw(11) << "List" << setw(11) << "Set" << endl;
    for (int operation = 0; operation < NUM_OPERATIONS; operation++) {

    }

    return 0;
}

void Race1(vector<string> &v, list<string> &l, set<string> &s, const vector<string> &rawData, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]) {
    Timer timer;
    // Vector
    timer.start();
    for (const string& code : rawData) {
        v.push_back(code);
    }
    runResults[0][0] = timer.stop();
    // List
    timer.start();
    for (const string& code: rawData) {
        l.push_back(code);
    }
    runResults[0][1] = timer.stop();
    // Set
    timer.start();
    for (const string& code: rawData) {
        s.insert(code);
    }
    runResults[0][2] = timer.stop();
    cout << left << setw(15) << "Reading (ns)" << setw(15) << runResults[0][0]  << setw(15) << runResults[0][1] 
    << setw(15) << runResults[0][2] << endl;
}

void Race2(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]) {
    Timer timer;
    // Vector
    timer.start();
    sort(v.begin(), v.end());
    runResults[1][0] = timer.stop();
    // List
    timer.start();
    l.sort();
    runResults[1][1] = timer.stop();
    // Set (Already sorted)
    runResults[1][2] = -1;
    cout << left << setw(15) << "Sorting (ns)" << setw(15) << runResults[1][0] << setw(15) << runResults[1][1]
    << setw(15) << runResults[1][2] << endl;
}
void Race3(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]) {
    Timer timer;
    // Vector
    timer.start();
    v.insert(v.begin() + v.size() /2, "TESTCODE");
    runResults[2][0] = timer.stop();
    // List
    timer.start();
    auto it = l.begin();
    advance(it, l.size()/2);
    l.insert(it, "TESTCODE");
    runResults[2][1] = timer.stop();
    // Set
    timer.start();
    s.insert("TESTCODE");
    runResults[2][2] = timer.stop();
    cout << left << setw(15) << "Inserting (ns)" << setw(15) << runResults[2][0] << setw(15) << runResults[2][1]
    << setw(15) << runResults[2][2] << endl;
}
void Race4(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]) {
    Timer timer;
    // Vector
    timer.start();
    v.erase(v.begin() + v.size()/2);
    runResults[3][0] = timer.stop();
    // List
    timer.start();
    auto it = l.begin();
    advance(it, l.size()/2);
    l.erase(it);
    runResults[3][1] = timer.stop();
    // Set
    timer.start();
    auto itS = s.begin();
    advance(itS, s.size()/2);
    s.erase(itS);
    runResults[3][2] = timer.stop();
    cout << left << setw(15) << "Deleting (ns)" << setw(15) << runResults[3][0] << setw(15) << runResults[3][1]
    << setw(15) << runResults[3][2] << endl;
}