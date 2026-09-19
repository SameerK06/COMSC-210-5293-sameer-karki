#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Course {
    string name;
    string courseCode;
    int credits;
    int year;
    int capacity;
    string* enrolledStudents = nullptr;
    bool active = false;
};

void initCourse(Course& course, const string& name, const string& courseCode, int credits, int year, int capacity, bool active);
void enrollStudent(Course& course, const string& studentName);
void outputCourse(const Course& course);
void clearCourse(Course& course);
void resizeCourse(Course& course, int newCapacity);
void saveCatalogToFile(Course* catalog, int numCourses, const string& outputFile);
void displayCourseOptions(Course* catalog, int numCourses);
int getEnrolledCount(const Course& course);

int main() {
    cout << "=====================================" << endl;
    cout << "          DVC COURSE CATALOG         " << endl;
    cout << "=====================================" << endl;
    int courseCapacity = 100;
    Course* courseCatalog = new Course[courseCapacity];
    cout << "Enter the number of courses to add to the catalog (max " << courseCapacity << ") given a single run of the program: ";
    int numCourses = 0;
    cout << "Enter the file containing all courses information: ";
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file or file doesn't exist: " << filename << endl;
        cout << "Starting with an empty catalog." << endl;
    } else {
        string line;
        while (numCourses < courseCapacity && getline(file, line)) {
            if (line.empty()) {
                continue;
            }
            stringstream ss(line);
            string name, courseCode;
            int credits, year, capacity;
            bool active = true;

            if (ss >> name >> courseCode >> credits >> year >> capacity) {
                if (!(ss >> active)) {
                    active = true;
                }
                initCourse(courseCatalog[numCourses], name, courseCode, credits, year, capacity, active);
                string studentName;
                while (ss >> studentName) {
                    enrollStudent(courseCatalog[numCourses], studentName);
                }
                numCourses++;
            }
        }
        file.close();

        if (numCourses == 0) {
            cout << "The file is empty. Starting with an empty catalog." << endl;
        } else {
            cout << "Loaded " << numCourses << " courses from " << filename << endl;
        }
    }
    // Creating a loop to enroll students in courses as well as displaying course info depending on user input
    while (true) {
        cout << "\n Menu:\n 1: Enroll a student\n 2: Display course info\n 3: Resize a course\n 4: Add a new course to catalog\n"
             << " 0: Exit and save changes\nChoice: ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            cout << "Enter output filename to save changes: ";
            string saveFilename;
            cin >> saveFilename;
            saveCatalogToFile(courseCatalog, numCourses, saveFilename);
            break;
        } else if (choice == 1) {
            if (numCourses == 0) {
                cout << "No courses in catalog. Please add a course first." << endl;
                continue;
            }
            int index;
            string studentName;
        }
    }
    return 0;
}

void initCourse(Course& course, const string& name, const string& courseCode, int credits, int year, int capacity, bool active) {
    course.name = name;
    course.courseCode = courseCode;
    course.credits = credits;
    course.year = year;
    course.capacity = capacity;
    course.enrolledStudents = new string[capacity];
    course.active = active;
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
    cout << "Active: " << (course.active ? "Yes" : "No") << endl;
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
        cout << "Decreasing capacity is not allowed. New capacity must be larger than current capacity." << endl;
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
        newEnrolledStudents = nullptr;
        cout << "Course " << course.name << " capacity successfully resized to " << newCapacity << endl;
    }
}

void saveCatalogToFile(Course* catalog, int numCourses, const string& outputFile) {
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error opening file for saving: " << outputFile << endl;
        return;
    }
    for (int i = 0; i < numCourses; i++) {
        outFile << catalog[i].name << " " << catalog[i].courseCode << " " << catalog[i].credits << " " 
                << catalog[i].year << " " << catalog[i].capacity << " " << catalog[i].active;
        if (catalog[i].enrolledStudents != nullptr) {
            for (string* ptr = catalog[i].enrolledStudents; ptr < catalog[i].enrolledStudents + catalog[i].capacity; ++ptr) {
                if (!ptr->empty()) {
                    outFile << " " << *ptr;
                }
            }
        }
        outFile << "\n";
    }
    outFile.close();
    cout << "Changes successfully saved to " << outputFile << endl;
}

void displayCourseOptions(Course* catalog, int numCourses) {
    cout << "\n-------------------- AVAILABLE COURSES --------------------" << endl;
    for (Course* ptr = catalog; ptr < catalog + numCourses; ptr++) {
        if (ptr->active) {
            int enrolled = getEnrolledCount(*ptr);
            int index = ptr - catalog;
            cout << "[" << index << "]" << ptr->name << " ( " << ptr->courseCode << ") - " << enrolled << "/" << ptr->capacity
                 << " Enrolled";
            if (enrolled >= ptr->capacity) {
                cout << " [FULL]";
            }
            cout << endl;
        }
    }
    cout << "-----------------------------------------------------------" << endl;

}