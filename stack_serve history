#include <iostream>
#include <stack> 
using namespace std;

int main() {
    stack<int> history;

    // Add customer tokens to the stack
    history.push(101); // Served first
    history.push(102); // Served second
    history.push(103); // Served last (most recent)

    cout << "Service History (Most Recent First):\n";

    // Print and remove tokens until the stack is empty
    while (!history.empty()) {
        cout << history.top() << "\n"; // Show the top token
        history.pop();                  // Remove the top token
    }

    return 0;
}
