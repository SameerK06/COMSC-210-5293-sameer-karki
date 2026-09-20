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
int getValidInt();


int main() {
    cout << "=====================================" << endl;
    cout << "          DVC COURSE CATALOG         " << endl;
    cout << "=====================================" << endl;
    int catalogCapacity = 100;
    Course* courseCatalog = new Course[catalogCapacity];
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
        while (numCourses < catalogCapacity && getline(file, line)) {
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
                    ss.clear();
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
        int choice = getValidInt();
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
            displayCourseOptions(courseCatalog, numCourses);
            string studentName;
            cout << "Enter course index to enroll in (0 to " << numCourses-1 << "): ";
            int index = getValidInt();
            if (index >= 0 && index < numCourses) {
                Course* selectedCourse = courseCatalog + index;
                if (selectedCourse->active) {
                    cout << "Enter student name: ";
                    cin >> studentName;
                    enrollStudent(*selectedCourse, studentName);
                } else {
                    cout << "Could not add student to course " << selectedCourse->name << " due to it being inactive" << endl; 
                }
            } else {
                cout << "Invalid course index." << endl;
            }
        } else if (choice == 2) {
            if (numCourses == 0) {
                cout << "No courses in catalog to display." << endl;
                continue;
            }
            displayCourseOptions(courseCatalog, numCourses);
            cout << "Enter course index (0 to " << numCourses - 1 << "): ";
            int index = getValidInt();
            if (index >= 0 && index < numCourses) {
                Course* selectedCourse = courseCatalog + index;
                outputCourse(*selectedCourse);
            } else {
                cout << "Invalid course index." << endl;
            }
        } else if (choice == 3) {
            if (numCourses == 0) {
                cout << "No courses in catalog to display." << endl;
                continue;
            }
            displayCourseOptions(courseCatalog, numCourses);
            int index, newCapacity;
            cout << "Enter course index to enroll in (0 to " << numCourses-1 << "): ";
            index = getValidInt();
            if (index >= 0 && index < numCourses) {
                Course* selectedCourse = courseCatalog + index;
                if (selectedCourse->active) {
                    cout << "Enter new capacity: ";
                    newCapacity = getValidInt();
                    resizeCourse(*selectedCourse, newCapacity);
                } else {
                    cout << "Could not increase capacity of course " << selectedCourse->name << " due to it being inactive" << endl; 
                }
            } else {
                cout << "Invalid course index." << endl;
            }
        } else if (choice == 4) {
            if (numCourses >= catalogCapacity) {
                cout << "Catalog is full (max " << catalogCapacity << " courses)." << endl;
            } else {
                string name, courseCode;
                int credits, year, capacity;
                // didn't want to deal with the string manipulation with the demlim and this
                cout << "Enter Course Name (single world or use _ instead of spaces): ";
                cin >> name;
                cout << "Enter Course Code: ";
                cin >> courseCode;
                cout << "Enter Credits: ";
                credits = getValidInt();
                cout << "Enter Year: ";
                year = getValidInt();
                cout << "Enter Capacity: ";
                capacity = getValidInt();
                Course* newCoursePtr = courseCatalog + numCourses;
                initCourse(*newCoursePtr, name, courseCode, credits, year, capacity, true);
                cout << "Course '" << newCoursePtr->name << "' added at index " << numCourses << "." << endl;
                numCourses++;
            }
        } else {
            cout << "Invalid menu choice. Please try again." << endl;
        }
    }
    for (Course* cPtr = courseCatalog; cPtr < courseCatalog + numCourses; ++cPtr) {
        clearCourse(*cPtr);
    }
    delete[] courseCatalog;
    courseCatalog = nullptr;
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
    if (!course.active || course.enrolledStudents == nullptr) {
        cout << "Cannot enroll. Course is inactive." << endl;
        return;
    }
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
        cout << "Course " << course.name << " capacity successfully resized to " << newCapacity << endl;
    }
}

void saveCatalogToFile(Course* catalog, int numCourses, const string& outputFile) {
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error opening file for saving: " << outputFile << endl;
        return;
    }

    for (Course* cPtr = catalog; cPtr < catalog + numCourses; ++cPtr) {
        outFile << cPtr->name << " " << cPtr->courseCode << " " << cPtr->credits << " " 
                << cPtr->year << " " << cPtr->capacity << " " << cPtr->active;
        if (cPtr->enrolledStudents != nullptr) {
            for (string* sPtr = cPtr->enrolledStudents; sPtr < cPtr->enrolledStudents + cPtr->capacity; ++sPtr) {
                if(!sPtr->empty()) {
                    outFile << " " << *sPtr;
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
    for (Course* ptr = catalog; ptr < catalog + numCourses; ++ptr) {
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

int getEnrolledCount(const Course& course) {
    int count = 0;
    if (course.enrolledStudents != nullptr) {
        for (string* ptr = course.enrolledStudents; ptr < course.enrolledStudents + course.capacity; ++ptr) {
            if (!ptr->empty()){
                count++;
            }
        }
    }
    return count;
}

int getValidInt() {
    int value;
    while(!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return value;
}