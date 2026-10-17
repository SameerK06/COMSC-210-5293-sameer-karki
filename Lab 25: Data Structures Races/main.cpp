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

void Race1(vector<string> &v, list<string> &l, set<string> &s, const vector<string> &rawData); // Reading
void Race2(vector<string> &v, list<string> &l, set<string> &s); // Sorting
void Race3(vector<string> &v, list<string> &l, set<string> &s); // Inserting
void Race4(vector<string> &v, list<string> &l, set<string> &s); //Deleting

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

    Race1(v, l, s, rawData);
    Race2(v, l, s);
    Race3(v, l, s);
    Race4(v, l, s);

    return 0;
}

void Race1(vector<string> &v, list<string> &l, set<string> &s, const vector<string> &rawData) {
    Timer timer;
    int time_v, time_l, time_s;
    // Vector
    timer.start();
    for (const string& code : rawData) {
        v.push_back(code);
    }
    time_v = timer.stop();
    // List
    timer.start();
    for (const string& code: rawData) {
        l.push_back(code);
    }
    time_l = timer.stop();
    // Set
    timer.start();
    for (const string& code: rawData) {
        s.insert(code);
    }
    time_s = timer.stop();
    cout << left << setw(15) << "Reading (ns)" << setw(15) << time_v  << setw(15) << time_l << setw(15) << time_s << endl;
}

void Race2(vector<string> &v, list<string> &l, set<string> &s) {
    Timer timer;
    int time_v, time_l, time_s;
    // Vector
    timer.start();
    sort(v.begin(), v.end());
    time_v = timer.stop();
    // List
    timer.start();
    l.sort();
    time_l = timer.stop();
    // Set (Already sorted)
    time_s = -1;
    cout << left << setw(15) << "Sorting (ns)" << setw(15) << time_v << setw(15) << time_l << setw(15) << time_s << endl;
}
void Race3(vector<string> &v, list<string> &l, set<string> &s) {
    Timer timer;
    int time_v, time_l, time_s;
    // Vector
    timer.start();
    v.insert(v.begin() + v.size() /2, "TESTCODE");
    time_v = timer.stop();
    // List
    timer.start();
    auto it = l.begin();
    advance(it, l.size()/2);
    l.insert(it, "TESTCODE");
    time_l = timer.stop();
    // Set
    timer.start();
    s.insert("TESTCODE");
    time_s = timer.stop();
    cout << left << setw(15) << "Inserting (ns)" << setw(15) << time_v << setw(15) << time_l << setw(15) << time_s << endl;
}
void Race4(vector<string> &v, list<string> &l, set<string> &s) {
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

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/