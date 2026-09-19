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
    course.enrolledStudents = new string[capacity];
}

void enrollStudent(Course& course, const string& studentName) {
    for (int i = 0; i < course.capacity; i++) {
        if (course.enrolledStudents[i].empty()) {
            course.enrolledStudents[i] 
            cout << "Student " << studentName << " enrolled in course " << course.name << endl;
            return;
        }
    }
    cout << "Course " << course.name << " is full. Cannot enroll student " << studentName << endl;
}

void outputCourse(const Course& course) {
    cout << "Course Name: " << course.name << endl;
    cout << "Course Code: " << course.courseCode << endl;
    cout << "Credits: " << course.credits << endl;
    cout << "Year: " << course.year << endl;
    cout << "Capacity: " << course.capacity << endl;
    cout << "Enrolled Students: ";
    if (course.enrolledStudents != nullptr)
    cout << endl;
}
