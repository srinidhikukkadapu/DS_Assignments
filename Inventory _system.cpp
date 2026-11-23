
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Product {
    int id;
    string name;
    float price;
    int quantity;
    Product* next;
};

Product* table[SIZE] = {NULL};

int hashFunction(int id) {
    return id % SIZE;
}

void addProduct() {
    int id, quantity;
    float price;
    string name;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = table[index];

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Product ID already exists!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Product Name: ";
    cin >> name;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;

    Product* newProduct = new Product;
    newProduct->id = id;
    newProduct->name = name;
    newProduct->price = price;
    newProduct->quantity = quantity;

    newProduct->next = table[index];
    table[index] = newProduct;

    cout << "Product added successfully!\n";
}

void updateProduct() {
    int id;
    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = table[index];

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Enter New Name: ";
            cin >> temp->name;
            cout << "Enter New Price: ";
            cin >> temp->price;
            cout << "Enter New Quantity: ";
            cin >> temp->quantity;

            cout << "Product updated!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Product not found!\n";
}

void removeProduct() {
    int id;
    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = table[index];
    Product* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Product removed!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Product not found!\n";
}

void displayProducts() {
    cout << "\nAvailable Products:\n";

    for (int i = 0; i < SIZE; i++) {
        Product* temp = table[i];

        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << " Name: " << temp->name
                 << " Price: " << temp->price
                 << " Quantity: " << temp->quantity << endl;

            temp = temp->next;
        }
    }
}

void searchProduct() {
    int id;
    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = table[index];

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Product Found!\n";
            cout << "Name: " << temp->name << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Quantity: " << temp->quantity << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Product not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- E-Commerce System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Remove Product\n";
        cout << "4. Display Products\n";
        cout << "5. Search Product\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: updateProduct(); break;
            case 3: removeProduct(); break;
            case 4: displayProducts(); break;
            case 5: searchProduct(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
