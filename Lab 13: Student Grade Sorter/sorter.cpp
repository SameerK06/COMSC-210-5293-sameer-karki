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
    string inputFile = "210-lab-13-grades.txt";
    string outputFile = "210-lab-13-grades-sorted.txt";
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error: Cannot open input file " << inputFile << endl;
        return 1;
    }
    int count = 0;
    while (inFile >> student_arr[count].id >> student_arr[count].score) {
        count++;
    }
    inFile.close();
    if (count <= 0) {
        cout << "No records found or error reading file " << inputFile << endl;
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

    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error: Cannot open output file " << outputFile << endl;
        return 1;
    }
    for (int i = 0; i < count; i++) {
        outFile << student_arr[i].id << " " << student_arr[i].score << "\n";
    }
    outFile.close();
    cout << "The sorted results are saved to " << outputFile << endl;

    double mean = 0.0;
    double minScore, maxScore = student_arr[0].score;
    int minId, maxId;
    for (int i = 0; i < count; i++) {
        sum += student_arr[i].score;
        if (student_arr[i].score < minScore) {
            minScore = student_arr[i].score;
            minId = student_arr[i].id;
        }
        if (student_arr[i].score > maxScore) {
            maxScore = student_arr[i].score;
            maxId = student_arr[i].id;
        }
    }
    mean/=count;



    return 0;
}