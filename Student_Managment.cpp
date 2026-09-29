#include <iostream>
using namespace std;

int main() {
    int rollNo[10];
    int marks[10];
    int n = 0; // Keeps track of the current number of students added
    int choice;
    int searchRoll;
    bool found;

    do {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =======";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student by Roll No";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Add Student
                if (n < 10) {
                    cout << "Enter Roll Number: ";
                    cin >> rollNo[n];
                    cout << "Enter Marks: ";
                    cin >> marks[n];
                    n++;
                    cout << "Student added successfully!\n";
                } else {
                    cout << "System storage full! Cannot add more than 10 students.\n";
                }
                break;

            case 2: // Display All Students
                if (n == 0) {
                    cout << "No student records available.\n";
                } else {
                    cout << "\n--- Student Records ---\n";
                    cout << "Roll No\tMarks\n";
                    for (int i = 0; i < n; i++) {
                        cout << rollNo[i] << "\t" << marks[i] << "\n";
                    }
                }
                break;

            case 3: // Search Student
                if (n == 0) {
                    cout << "No student records available to search.\n";
                } else {
                    cout << "Enter Roll Number to search: ";
                    cin >> searchRoll;
                    found = false;
                    for (int i = 0; i < n; i++) {
                        if (rollNo[i] == searchRoll) {
                            cout << "Student Found! Roll No: " << rollNo[i] << ", Marks: " << marks[i] << "\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Student with Roll Number " << searchRoll << " not found.\n";
                    }
                }
                break;

            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
