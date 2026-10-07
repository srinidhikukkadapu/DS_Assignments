#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> bankQueue; // Queue to hold token numbers
    int choice;
    int nextToken = 1;    // First token starts at 1

    cout << "--- Bank Token System ---" << endl;

    do {
        // Display options
        cout << "\n1. Take a Token\n";
        cout << "2. Serve Next Customer\n";
        cout << "3. Exit\n";
        cout << "Choose an option (1-3): ";
        cin >> choice;

        if (choice == 1) {
            // Add token to the back of the line
            bankQueue.push(nextToken);
            cout << "Your Token Number is: " << nextToken << endl;
            nextToken++; // Prepare next number (2, 3, etc.)
        } 
        else if (choice == 2) {
            // Serve the token at the front of the line
            if (bankQueue.empty()) {
                cout << "No customers waiting!\n";
            } else {
                cout << "Now serving Token Number: " << bankQueue.front() << endl;
                bankQueue.pop(); // Remove it from the line
            }
        } 
        else if (choice == 3) {
            cout << "Goodbye!\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
