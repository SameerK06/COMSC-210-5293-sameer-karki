#include <iostream>
#include <string>

using namespace std;

struct Course {
    string name;
    string courseCode;
    int credits;
    int year;
    int capacity;
    string* enrolledStudents;
};

void initCourse(Course& course, const string& name, const string& courseCode, int credits, int year, int capacity);
void enrollStudent(Course& course, const string& studentName);
void outputCourse(const Course& course);
void clearCourse(Course& course);
void resizeCourse(Course& course, int newCapacity);

int main() {
    return 0;
}

void initCourse(Course& course, const string& name, const string& courseCode, int credits, int year, int capacity) {
    course.name = name;
    course.courseCode = courseCode;
    course.credits = credits;
    course.year = year;
    course.capacity = capacity;
    course.enrolledStudents = nullptr;
}

