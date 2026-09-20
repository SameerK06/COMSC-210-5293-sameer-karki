# Lab 11: Pointers II
[<- Back to Main Repository](../README.md)

## Description
This task showcases real world usage of `array`, `struct` data structures and showcases the effectiveness of the pointer methodology in the real-world. Throughout this task, the program must display myriad of methodology for building a program using `array`, `struct` data structures and also pointer to access those data in memory.

## Creator's Thoughts
 - This was the longest that I spent on this class and pointer suck. I kept trying to remember if it was \*data or data\* that I was supposed to use
 - I did learn a lot more about pointer while building this. I was really worried when I first ran it, because I though that I might have left a dangling point of something or there will be a segment fault error and my machine will brick itself.
 - Didn't really use anything new except for maybe the sstream function which I had to read up to enable this program because making those file input in different line would have hurt my soul.

## Functions Used

* **`initCourse`**
  * **Parameters:** `Course& course` (reference to the course), `const string& name`, `const string& courseCode`, `int credits`, `int year`, `int capacity`, `bool active`.
  * **How it works:** This function acts as a constructor for the `Course` struct. It assigns all the passed scalar values (name, code, credits, etc.) to the struct's members. Crucially, it dynamically allocates a new array of strings for the `enrolledStudents` member based on the provided `capacity` size.

* **`enrollStudent`**
  * **Parameters:** `Course& course` (reference to the course), `const string& studentName`.
  * **How it works:** First, it checks if the course is active and if the student array exists. Then, it utilizes pointer arithmetic (`string* ptr` and `string* endptr`) to iterate through the dynamically allocated `enrolledStudents` array. It searches for the first empty string (an open seat), assigns the `studentName` to that memory address, and immediately returns. If the pointer reaches `endptr` without finding an empty string, it alerts the user that the course is full.

* **`outputCourse`**
  * **Parameters:** `const Course& course` (read-only reference to the course).
  * **How it works:** Prints all the metadata for a single course (Name, Code, Credits, Year, Capacity, Active status). It then uses a pointer-based `for` loop to traverse the `enrolledStudents` array, printing out the names of any students currently occupying a slot.

* **`clearCourse`**
  * **Parameters:** `Course& course` (reference to the course).
  * **How it works:** This is the cleanup function to prevent memory leaks. It uses `delete[]` to free the dynamically allocated memory pointed to by `course.enrolledStudents`. It then sets that pointer to `nullptr` to avoid dangling pointers, resets the capacity to `0`, and flags the course as inactive.

* **`resizeCourse`**
  * **Parameters:** `Course& course` (reference to the course), `int newCapacity`.
  * **How it works:** Validates that `newCapacity` is strictly greater than the current capacity. If valid, it dynamically allocates a brand new string array (`newEnrolledStudents`) of the new size. It uses two pointers (`ptr` for the old array and `newPtr` for the new array) to traverse and copy all existing students over. Finally, it deletes the old `enrolledStudents` array to free the old memory, points the struct's pointer to the new array, and updates the capacity variable.

* **`saveCatalogToFile`**
  * **Parameters:** `Course* catalog` (pointer to the main catalog array), `int numCourses` (total active courses), `const string& outputFile`.
  * **How it works:** Opens an `ofstream` to write to a text file. It uses a pointer (`cPtr`) to iterate through the main catalog array up to `numCourses`. For each course, it writes the metadata on a single line. It then uses a nested pointer loop (`sPtr`) to iterate through that specific course's `enrolledStudents`, appending valid names to the same line. 

* **`displayCourseOptions`**
  * **Parameters:** `Course* catalog` (pointer to the main catalog array), `int numCourses` (total active courses).
  * **How it works:** Generates a formatted menu for the user. It iterates through the catalog array using a pointer (`ptr`). For each active course, it calculates the array index (`ptr - catalog`), calls `getEnrolledCount`, and prints a summary. If the enrolled count equals the capacity, it adds a "[FULL]" tag to the display.

* **`getEnrolledCount`**
  * **Parameters:** `const Course& course` (read-only reference to the course).
  * **How it works:** Initializes a `count` variable at 0. It uses a pointer to iterate through the `enrolledStudents` array from start to finish. For every memory location that does not contain an empty string, it increments the count. It returns the final integer tally.

* **`getValidInt`**
  * **Parameters:** None.
  * **How it works:** A robust input validation loop. It attempts to read an integer from `cin`. If the extraction fails (e.g., the user typed a letter instead of a number), it clears the internal error flag (`cin.clear()`), ignores the bad characters left in the input buffer up to a newline (`cin.ignore()`), and prompts the user again until a valid integer is provided. Also I don't trust the user!!

## Layout
.\
├── README.md\
├── pointer.cpp - C++ source code file.\
├── pointer.exe - Compiled executable.\
└── courses.txt - Datafile for courses catalog.

## Timeline
* **Date Added:** 09-19-2026 at ~3:00 PM
* **Due Date:** 09-20-2026 at 10:00 PM
