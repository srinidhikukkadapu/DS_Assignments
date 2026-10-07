#include <iostream>
#include <string>

using namespace std;

int main() {
    // Arrays to store token information (handles up to 100 customers)
    int tokens[100];
    string names[100];
    
    int front = 0;         // Tracks the next person to be served
    int rear = 0;          // Tracks where the next new token goes
    int nextTokenNumber = 1; 
    int choice;

    do {
        // Display Menu
        cout << "\n--- BANK TOKEN SYSTEM ---" << endl;
        cout << "1. Issue Token" << endl;
        cout << "2. Display All Tokens" << endl;
        cout << "3. Serve Customer" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Issue a new token
            tokens[rear] = nextTokenNumber;
            cout << "Enter customer name: ";
            cin >> names[rear]; // Takes a single-word name
            
            cout << "Token #" << nextTokenNumber << " issued to " << names[rear] << endl;
            nextTokenNumber++;
            rear++; // Move end of line forward
        }
        else if (choice == 2) {
            // Display all tokens
            if (front == rear) {
                cout << "Queue is empty!" << endl;
            } else {
                cout << "\nWaiting List:" << endl;
                for (int i = front; i < rear; i++) {
                    cout << "Token " << tokens[i] << " - " << names[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            // Serve the next customer
            if (front == rear) {
                cout << "No customers to serve!" << endl;
            } else {
                cout << "Now serving: Token " << tokens[front] << " (" << names[front] << ")" << endl;
                front++; // Move front of line forward (removes served person)
            }
        }
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
