#include <iostream>
using namespace std;

const int M = 753;

// Structure of Account
struct Account {
    int accountNumber;
    string ownerName;
    double balance;

    Account() : accountNumber(0), ownerName(""), balance(0) {}
};

// Return the hash address
int Hash_Function(int key) {
    return key % M;
}

// Clears the account
void clearAccount(Account& x) {
    x.ownerName = "";
    x.balance = 0;
    x.accountNumber = 0;
}

// Insert an Account to the hash table
void INSERTAccount(Account table[], Account x) {
    // Get the hash value of key
    int hash = Hash_Function(x.accountNumber - 100000);
    int i = hash;
    // Insert account x using linear probing
    do {
        if (table[hash].accountNumber < 1) {
            // Insert account x
            table[hash] = x;
            cout << "Account inserted!" << endl;
            return;
        }
        i++;
        hash = Hash_Function(x.accountNumber - 100000 + i);
    } while (hash != i);
}

// Delete an Account from the hash table
void DELETE_Account(Account table[], Account x) {
    int hash = Hash_Function(x.accountNumber - 100000);
    int i = hash;
    // Delete the account using linear probing
    do {
        if (table[hash].accountNumber == x.accountNumber) {
            // Delete account x
            table[hash].accountNumber = -1;
            cout << "Account removed!" << endl;
            return;
        }
        i++;
        hash = Hash_Function(x.accountNumber - 100000 + i);
    } while (hash != i);

    cout << "Not found!" << endl;
}

// Search an Account in the hash table and return the Account details
Account SEARCH_Account(Account table[], Account x) {
    int hash = Hash_Function(x.accountNumber - 100000);
    int i = hash;
    // Find the key in the list using linear probing
    do {
        if (table[hash].accountNumber == x.accountNumber)
            return table[hash];
        if (table[hash].accountNumber < 1) {
            clearAccount(x);
            return x;
        }
        i++;
        hash = Hash_Function(x.accountNumber - 100000 + i);
    } while (hash != i);

    clearAccount(x);
    return x;
}

// Main function
int main() {
    int buckets = 800;
    // Pointer to an array containing Accounts
    Account* table = new Account[buckets];
    Account acc;

    // Processing menu-driven program
    while (true) {
        cout << " 1. Insert \n 2. Delete \n 3. Search \n 4. Exit \n Enter option: ";
        int option;
        // Read the option
        cin >> option;

        switch (option) {
            // Insert operation
            case 1:
                cin.ignore(80, '\n');
                cout << "Enter the owner's name: ";
                cin >> acc.ownerName;
                cout << "Enter the account number: ";
                cin >> acc.accountNumber;
                cout << "Enter the account balance: ";
                cin >> acc.balance;
                INSERTAccount(table, acc);
                break;
            // Delete an account
            case 2:
                cout << "Enter the account number: ";
                cin >> acc.accountNumber;
                DELETE_Account(table, acc);
                break;
            // Search an account
            case 3:
                cout << "Enter the account number: ";
                cin >> acc.accountNumber;
                acc = SEARCH_Account(table, acc);
                if (acc.accountNumber == 0)
                    cout << "Not found!" << endl;
                else {
                    cout << "Owner's name: " << acc.ownerName << endl;
                    cout << "Account number: " << acc.accountNumber << endl;
                    cout << "Account balance: " << acc.balance << endl;
                }
                break;
            // Exit
            case 4:
                // Delete the table
                delete[] table;
                return 0;
        }
        // Clear the account
        clearAccount(acc);
    }
}
