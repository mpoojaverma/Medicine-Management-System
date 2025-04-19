#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Medicine {
    string name;
    int quantity;
    float price;
    string expiryDate;
};

vector<Medicine> inventory;

// ✅ Add a medicine
void addMedicine() {
    Medicine med;
    cout << "\n➕ Enter Medicine Details\n";
    cout << "🔹 Name: ";
    cin >> med.name;
    cout << "🔹 Quantity: ";
    cin >> med.quantity;
    cout << "🔹 Price per unit (₹): ";
    cin >> med.price;
    cout << "🔹 Expiry Date (DD/MM/YYYY): ";
    cin >> med.expiryDate;
    inventory.push_back(med);
    cout << "✅ Medicine added successfully!\n";
}

// 📋 View all medicines
void viewMedicines() {
    if (inventory.empty()) {
        cout << "\n⚠️ No medicines in inventory.\n";
        return;
    }
    cout << "\n📦 --- Medicine Inventory ---\n";
    cout << left << setw(5) << "S.No" << setw(15) << "Name"
         << setw(10) << "Qty" << setw(10) << "Price(₹)"
         << "Expiry Date\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < inventory.size(); ++i) {
        cout << left << setw(5) << i + 1 << setw(15) << inventory[i].name
             << setw(10) << inventory[i].quantity
             << setw(10) << inventory[i].price
             << inventory[i].expiryDate << "\n";
    }
}

// 🛠️ Update a medicine
void updateMedicine() {
    string name;
    cout << "\n✏️ Enter medicine name to update: ";
    cin >> name;
    for (auto &med : inventory) {
        if (med.name == name) {
            cout << "🔁 New Quantity: ";
            cin >> med.quantity;
            cout << "💵 New Price (₹): ";
            cin >> med.price;
            cout << "📅 New Expiry Date (DD/MM/YYYY): ";
            cin >> med.expiryDate;
            cout << "✅ Medicine updated successfully!\n";
            return;
        }
    }
    cout << "❌ Medicine not found!\n";
}

// 🗑️ Delete a medicine
void deleteMedicine() {
    string name;
    cout << "\n🗑️ Enter medicine name to delete: ";
    cin >> name;
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            inventory.erase(inventory.begin() + i);
            cout << "✅ Medicine deleted successfully!\n";
            return;
        }
    }
    cout << "❌ Medicine not found!\n";
}

// 💰 Calculate total value
void calculateInventoryValue() {
    float total = 0;
    for (const auto &med : inventory) {
        total += med.quantity * med.price;
    }
    cout << "\n💼 Total Inventory Value: ₹" << total << "\n";
}

// 🧾 Export inventory to file
void exportToFile() {
    ofstream outFile("inventory.txt");
    if (!outFile) {
        cout << "⚠️ Error creating file.\n";
        return;
    }
    outFile << "--- Medicine Inventory Report ---\n";
    outFile << left << setw(15) << "Name"
            << setw(10) << "Qty"
            << setw(10) << "Price(₹)"
            << "Expiry Date\n";
    outFile << "-----------------------------------------\n";
    for (const auto &med : inventory) {
        outFile << left << setw(15) << med.name
                << setw(10) << med.quantity
                << setw(10) << med.price
                << med.expiryDate << "\n";
    }
    outFile.close();
    cout << "📄 Inventory exported to 'inventory.txt' successfully!\n";
}

// 🌐 Main menu
int main() {
    int choice;
    do {
        cout << "\n🌟 --- Medicine Management System --- 🌟\n";
        cout << "1️⃣ Add Medicine\n";
        cout << "2️⃣ View Medicines\n";
        cout << "3️⃣ Update Medicine\n";
        cout << "4️⃣ Delete Medicine\n";
        cout << "5️⃣ Calculate Inventory Value\n";
        cout << "6️⃣ Exit\n";
        cout << "7️⃣ Export Inventory to File\n";
        cout << "🔸 Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: updateMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: calculateInventoryValue(); break;
            case 6: cout << "\n👋 Exiting... Bye RowdyStar! Stay Legendary 💫\n"; break;
            case 7: exportToFile(); break;
            default: cout << "⚠️ Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
