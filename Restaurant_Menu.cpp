#include <iostream>

using namespace std;


void showMenu(double currentTotal) {
    int choice;
    
    // Display the restaurant menu and current total bill
    cout << "\n--- Restaurant Menu ---";
    cout << "\nCurrent Bill: Rs. " << currentTotal << "\n";
    cout << "1. Burger - Rs. 120\n";
    cout << "2. Pizza  - Rs. 250\n";
    cout << "3. Pasta  - Rs. 180\n";
    cout << "4. Exit & Checkout\n";
    cout << "Enter your choice : ";
    cin >> choice;
    
    
    switch (choice) {
        case 1:
            cout << "Added Burger to your order.\n";
            currentTotal += 120;
            break;
        case 2:
            cout << "Added Pizza to your order.\n";
            currentTotal += 250;
            break;
        case 3:
            cout << "Added Pasta to your order.\n";
            currentTotal += 180;
            break;
        case 4:
cout << "\nThank you for dining with us!\n";
            cout << "Your Final Total Bill is: Rs. " << currentTotal << "\n";
            return; 
        default:
            cout << "Invalid choice! Please select a valid option from the menu.\n";
    }
    
    
    showMenu(currentTotal);
}

int main() {
    
    showMenu(0.0);
    
    return 0;
}

