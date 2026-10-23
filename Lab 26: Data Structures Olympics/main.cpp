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

    vector<string> v;
    list<string> l;
    set<string> s;
    cout << left << setw(15) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set" << endl;
    cout << string(60, '-') << endl;

    Race1(v, l, s, rawData);
    Race2(v, l, s);
    Race3(v, l, s);
    Race4(v, l, s);

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
    cout << left << setw(15) << "Inserting (ns)" << setw(15) << runResults[2][0] << setw(15) << runResults[2][1] << setw(15) << runResults[2][2] << endl;
}
void Race4(vector<string> &v, list<string> &l, set<string> &s, long runResults[NUM_OPERATIONS][NUM_CONTAINERS]) {
    Timer timer;
    int time_v, time_l, time_s;
    // Vector
    timer.start();
    v.erase(v.begin() + v.size()/2);
    time_v = timer.stop();
    // List
    timer.start();
    auto it = l.begin();
    advance(it, l.size()/2);
    l.erase(it);
    time_l = timer.stop();
    // Set
    timer.start();
    auto itS = s.begin();
    advance(itS, s.size()/2);
    s.erase(itS);
    time_s = timer.stop();
    cout << left << setw(15) << "Deleting (ns)" << setw(15) << time_v << setw(15) << time_l << setw(15) << time_s << endl;
}