#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>

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
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/