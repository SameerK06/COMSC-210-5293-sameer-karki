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
        count++;
    }
    inFile.close();
    if (count <= 0) {
        cout << "No records found or error reading file " << filename << endl;
        return 1;
    } else {
        cout << "Read " << count << " student records" << endl;
    }

    for (int i = 0; i < count-1; i++) {
        int minIndex=i;
        for (int j = i+1; j < count; j++) {
            if (student_arr[i].id < student_arr[minIndex].id) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Student temp = student_arr[i];
            student_arr[i] = student_arr[minIndex];
            student_arr[minIndex] = temp;
        }
    }

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Cannot open output file " << filename << endl;
        return 1;
    }
    for (int i = 0; i < count; i++) {
        outFile << student_arr[i] << " " <<
    }




    return 0;
}