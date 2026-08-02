// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Struct representing a single student record
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Clears bad input state and discards the rest of the line
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Computes the average of a student's scores (0 if no scores)
double calculateAverage(const Student &s) {
    if (s.scores.empty()) return 0.0;
    double sum = 0.0;
    for (double sc : s.scores) sum += sc;
    return sum / s.scores.size();
}

// FEATURE 1 — Add a Student
void addStudent(vector<Student> &students) {
    Student s;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Student ID: ";
    while (!(cin >> s.id)) {
        cout << "Invalid ID. Please enter a numeric ID: ";
        clearInputBuffer();
    }

    int count;
    cout << "How many scores? ";
    while (!(cin >> count) || count < 0) {
        cout << "Invalid number. How many scores? ";
        clearInputBuffer();
    }

    for (int i = 1; i <= count; i++) {
        double score;
        cout << "Enter score " << i << ": ";
        while (!(cin >> score)) {
            cout << "Invalid score. Enter score " << i << ": ";
            clearInputBuffer();
        }
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// FEATURE 2 — Display All Students
void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << left << setw(20) << "Name"
         << setw(12) << "ID"
         << setw(30) << "Scores"
         << "Average\n";
    cout << string(75, '-') << "\n";

    for (const auto &s : students) {
        cout << left << setw(20) << s.name
             << setw(12) << s.id;

        string scoreList;
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoreList += to_string(static_cast<int>(s.scores[i]));
            if (i != s.scores.size() - 1) scoreList += ", ";
        }
        cout << setw(30) << scoreList;

        cout << fixed << setprecision(2) << calculateAverage(s) << "\n";
    }
}

// FEATURE 3 — Calculate Average Score for a Specific Student
void calculateAverageForId(const vector<Student> &students) {
    int id;
    cout << "Enter student ID: ";
    while (!(cin >> id)) {
        cout << "Invalid ID. Enter student ID: ";
        clearInputBuffer();
    }

    for (const auto &s : students) {
        if (s.id == id) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << calculateAverage(s) << "\n";
            return;
        }
    }

    cout << "Error: no student found with ID " << id << ".\n";
}

// Displays the main menu
void printMenu() {
    cout << "\n================================\n";
    cout << "   STUDENT RECORD SYSTEM MENU\n";
    cout << "================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        printMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                calculateAverageForId(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

