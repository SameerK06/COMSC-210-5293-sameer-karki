#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 500;

struct Student {
    int id;
    double score;
};

int main() {
    Student student_arr[MAX_STUDENTS];
    string filename = "210-lab-13-grades.txt";
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Cannot open input file " << filename << endl;
        return 1;
    }
    int count = 0;
    while (inFile >> student_arr[count].id >> student_arr[count].score) {
        cout 
    }



    return 0;
}