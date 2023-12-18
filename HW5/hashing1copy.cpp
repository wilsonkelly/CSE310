#include <iostream>
#include <list>
using namespace std;

const int M = 753;

struct Account {
    int accountNumber;
    string ownerName;
    double balance;
};

int Hash_Function(int key) {
    return key % M;
}

void clearAccount(Account& acc) {
    acc.ownerName = "";
    acc.balance = 0;
    acc.accountNumber = 0;
}

void INSERTAccount(list<Account>*& table, Account acc) {
    int hash = Hash_Function(acc.accountNumber - 100000);
    table[hash].push_back(acc);
    cout << "Account inserted!" << endl;
}

void DELETE_Account(list<Account>*& table, Account acc) {
    int hash = Hash_Function(acc.accountNumber - 100000);
    list<Account>::iterator it;
    for (it = table[hash].begin(); it != table[hash].end(); it++) {
        if (it->accountNumber == acc.accountNumber) {
            table[hash].erase(it);
            cout << "Account removed" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

Account SEARCH_Account(list<Account>* table, Account acc) {
    int hash = Hash_Function(acc.accountNumber - 100000);
    list<Account>::iterator it;
    for (it = table[hash].begin(); it != table[hash].end(); it++) {
        if (it->accountNumber == acc.accountNumber)
            return *it;
    }
    clearAccount(acc);
    return acc;
}

int main() {
    int buckets = 800;
    list<Account>* table = new list<Account>[buckets];
    Account acc;

    while (true) {
        cout << " 1. Insert \n 2. Delete \n 3. Search \n 4. Exit \n Enter option: ";
        int option;
        cin >> option;

        switch (option) {
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
            case 2:
                cout << "Enter the account number: ";
                cin >> acc.accountNumber;
                DELETE_Account(table, acc);
                break;
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
            case 4:
                delete[] table;
                return 0;
        }
        clearAccount(acc);
    }
}
