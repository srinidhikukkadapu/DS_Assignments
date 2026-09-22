#include <iostream>

using namespace std;

int main() {
    int marks[5];
    int n = 5;

    // Input marks for 5 students
    cout << "Enter the marks for 5 students:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " marks: ";
        cin >> marks[i];
    }

    // Sort the array in descending order using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is less than the next element
            if (marks[j] < marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    // Display sorted marks from highest to lowest
    cout << "\nMarks in descending order (Highest to Lowest):" << endl;
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}
