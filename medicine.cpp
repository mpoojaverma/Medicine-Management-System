#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Medicine {
    string name;
    int quantity;
    float price;
    string expiryDate;
};

vector<Medicine> inventory;
void addMedicine() {
    Medicine med;
    cout << "Enter medicine name: ";
    cin >> med.name;
    cout << "Enter quantity: ";
    cin >> med.quantity;
    cout << "Enter price per unit: ";
    cin >> med.price;
    inventory.push_back(med);
    cout << "Medicine added successfully!\n";
}
void viewMedicines() {
    if (inventory.empty()) {
        cout << "No medicines in inventory.\n";
        return;
    }
    cout << "\n--- Medicine List ---\n";
    for (int i = 0; i < inventory.size(); ++i) {
        cout << i + 1 << ". " << inventory[i].name
             << " | Qty: " << inventory[i].quantity
             << " | ₹" << inventory[i].price << "\n";
    }
    cout << "---------------------\n";
}
void updateMedicine() {
    string name;
    cout << "Enter medicine name to update: ";
    cin >> name;
    for (auto &med : inventory) {
        if (med.name == name) {
            cout << "Enter new quantity: ";
            cin >> med.quantity;
            cout << "Enter new price: ";
            cin >> med.price;
            cout << "Enter new expiry date (DD/MM/YYYY): ";
            cin >> med.expiryDate;
            cout << "Medicine updated successfully!\n";
            return;
        }
    }
    cout << "Medicine not found!\n";
}

void deleteMedicine() {
    string name;
    cout << "Enter medicine name to delete: ";
    cin >> name;
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            inventory.erase(inventory.begin() + i);
            cout << "Medicine deleted successfully!\n";
            return;
        }
    }
    cout << "Medicine not found!\n";
}
void calculateInventoryValue() {
    float total = 0;
    for (const auto &med : inventory) {
        total += med.quantity * med.price;
    }
    cout << "Total inventory value: ₹" << total << "\n";
}

void addMedicine() {
    Medicine med;
    cout << "Enter medicine name: ";
    cin >> med.name;
    cout << "Enter quantity: ";
    cin >> med.quantity;
    cout << "Enter price per unit: ";
    cin >> med.price;
    cout << "Enter expiry date (DD/MM/YYYY): ";
    cin >> med.expiryDate;
    inventory.push_back(med);
    cout << "Medicine added successfully!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Medicine Management System ---\n";
        cout << "1. Add Medicine\n";
        cout << "2. View Medicines\n";
        cout << "3. Update Medicine\n";
        cout << "4. Delete Medicine\n";
        cout << "5. Calculate Inventory Value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: updateMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: calculateInventoryValue(); break;
            case 6: cout << "Exiting... Bye RowdyStar! 💪\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
