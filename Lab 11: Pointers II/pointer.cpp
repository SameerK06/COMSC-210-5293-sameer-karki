#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Course {
    string name;
    string courseCode;
    int credits;
    int year;
    int capacity;
    string* enrolledStudents;
    bool active;
};

void initCourse(Course& course, const string& name, const string& courseCode, int credits, int year, int capacity);
void enrollStudent(Course& course, const string& studentName);
void outputCourse(const Course& course);
void clearCourse(Course& course);
void resizeCourse(Course& course, int newCapacity);

int main() {
    cout << "=====================================" << endl;
    cout << "          DVC COURSE CATALOG         " << endl;
    cout << "=====================================" << endl;
    int courseCapacity = 100;
    Course* courseCatalog = new Course[courseCapacity];
    cout << "Enter the number of courses to add to the catalog (max " << courseCapacity << "): ";
    int numCourses;
    cin >> numCourses;
    cout << "Enter the file containing all courses information: ";
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        delete[] courseCatalog;
        courseCatalog = nullptr;
        cout << "Exiting program." << endl;
        return 1;
    }
    return 0;
}

void initCourse(Course& course, const string& name, const string& courseCode, int credits, int year, int capacity) {
    course.name = name;
    course.courseCode = courseCode;
    course.credits = credits;
    course.year = year;
    course.capacity = capacity;
    course.enrolledStudents = new string[capacity];
    course.active = true;
}

void enrollStudent(Course& course, const string& studentName) {
    string* ptr = course.enrolledStudents;
    string* endptr = course.enrolledStudents + course.capacity;
    while(ptr < endptr) {
        if (ptr->empty()) {
            *ptr = studentName;
            cout << "Student " << studentName << " enrolled in course " << course.name << endl;
            return;
        }
        ptr++;
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
    if (course.enrolledStudents != nullptr) {
        for (string* ptr = course.enrolledStudents; ptr < course.enrolledStudents + course.capacity; ++ptr) {
            if (!ptr->empty()) {
                cout << *ptr << " ";
            }
        }
        cout << endl;
    }
}

void clearCourse(Course& course) {
    delete[] course.enrolledStudents;
    course.enrolledStudents = nullptr;
    course.capacity = 0;
    course.active = false;
}

void resizeCourse(Course& course, int newCapacity) {
    if (newCapacity <= course.capacity) {
        cout << "Increasing capacity is not allowed. New capacity must be larger than current capacity." << endl;
    } else {
        string* newEnrolledStudents = new string[newCapacity];
        string* ptr = course.enrolledStudents;
        string* newPtr = newEnrolledStudents;
        while (ptr < course.enrolledStudents + course.capacity) {
            if (!ptr->empty()) {
                *newPtr = *ptr;
                newPtr++;
            }
        ptr++;
        }
        delete[] course.enrolledStudents;
        course.enrolledStudents = newEnrolledStudents;
        course.capacity = newCapacity;
        delete[] newEnrolledStudents;
        newEnrolledStudents = nullptr;
    }
}