

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

// Linked List Node
struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

// Smart Hospital Management System
class Hospital
{
private:
    Patient* head;
    Patient* hashTable[SIZE];

    // Hash Function
    int hashFunction(int id)
    {
        return id % SIZE;
    }

public:
    Hospital()
    {
        head = NULL;

        for (int i = 0; i < SIZE; i++)
        {
            hashTable[i] = NULL;
        }
    }

    // Register New Patient
    void registerPatient()
    {
        Patient* p = new Patient;

        cout << "Enter Patient ID: ";
        cin >> p->id;

        // Check for duplicate Patient ID
        if (searchByID(p->id) != NULL)
        {
            cout << "Patient ID already exists!\n";
            delete p;
            return;
        }

        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, p->name);

        cout << "Enter Age: ";
        cin >> p->age;

        cout << "Enter Disease: ";
        cin >> ws;
        getline(cin, p->disease);

        // Insert into Linked List
        p->next = head;
        head = p;

        // Insert into Hash Table using Chaining
        int index = hashFunction(p->id);
        p->next = hashTable[index];
        hashTable[index] = p;

        cout << "Patient registered successfully!\n";
    }

    // Search Patient by ID
    Patient* searchByID(int id)
    {
        int index = hashFunction(id);
        Patient* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                return temp;
            }

            temp = temp->next;
        }

        return NULL;
    }

    void searchPatient()
    {
        int id;

        cout << "Enter Patient ID to search: ";
        cin >> id;

        Patient* temp = searchByID(id);

        if (temp != NULL)
        {
            cout << "\nPatient Found!\n";
            cout << "Patient ID: " << temp->id << "\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            cout << "Disease: " << temp->disease << "\n";
        }
        else
        {
            cout << "Patient not found!\n";
        }
    }

    // Display All Patients
    void displayPatients()
    {
        Patient* temp = head;

        if (temp == NULL)
        {
            cout << "No patient records available.\n";
            return;
        }

        cout << "\n===== All Patient Records =====\n";

        while (temp != NULL)
        {
            cout << "\nPatient ID: " << temp->id << "\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            cout << "Disease: " << temp->disease << "\n";

            temp = temp->next;
        }
    }

    // Main Menu
    void menu()
    {
        int choice;

        do
        {
            cout << "\n===== Smart Hospital Patient Record Management System =====\n";
            cout << "1. Register New Patient\n";
            cout << "2. Search Patient\n";
            cout << "3. Display All Patients\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    registerPatient();
                    break;

                case 2:
                    searchPatient();
                    break;

                case 3:
                    displayPatients();
                    break;

                case 4:
                    cout << "Exiting the system...\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }

        } while (choice != 4);
    }

    // Free allocated memory
    ~Hospital()
    {
        Patient* temp = head;

        while (temp != NULL)
        {
            Patient* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Main Function
int main()
{
    Hospital h;
    h.menu();

    return 0;
}
