#include <iostream>
#include <list>
using namespace std;

const int M = 753;

// Structure of Account
struct Account {
    int accountNumber;
    string ownerName;
    double balance;
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
void INSERTAccount(list<Account>*& table, Account x) {
    // Get the hash value of key
    int hash = Hash_Function(x.accountNumber - 100000);
    // Insert account x
    table[hash].push_back(x);
    cout << "Account inserted!" << endl;
}

// Delete an Account from the hash table
void DELETE_Account(list<Account>*& table, Account x) {
    int hash = Hash_Function(x.accountNumber - 100000);
    // Find the key in the list
    list<Account>::iterator i;
    for (i = table[hash].begin(); i != table[hash].end(); i++) {
        if ((*i).accountNumber == x.accountNumber)
            break;
    }
    // If key is found in the hash table, remove it
    if (i != table[hash].end()) {
        table[hash].erase(i);
        cout << "Account removed" << endl;
    }
    else
        cout << "Not found!" << endl;
}

// Search an Account in the hash table and return the Account details
Account SEARCH_Account(list<Account>* table, Account x) {
    int hash = Hash_Function(x.accountNumber - 100000);
    // Find the key in the list
    list<Account>::iterator i;
    for (i = table[hash].begin(); i != table[hash].end(); i++) {
        if ((*i).accountNumber == x.accountNumber)
            return *i;
    }
    clearAccount(x);
    return x;
}

// Main function
int main() {
    int buckets = 800;
    // Pointer to an array containing Accounts
    list<Account>* table = new list<Account>[buckets];
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
