#include <iostream>
using namespace std;
#include <stack>

using namespace std;

int main() {
    stack<int> orders; 
    int number;

    cout << "Enter 5 cancelled order numbers:\n";
    
    // 1. Loop to get 5 numbers from the user
    for (int i = 0; i < 5; i++) {
        cin >> number;
        orders.push(number); 
    }

    cout << "\nCancelled orders (Most Recent First):\n";

    // 2. Loop to print and remove numbers until the stack is empty
    while (!orders.empty()) {
        cout << orders.top() << endl; 
        orders.pop();
    }

    return 0;
}

