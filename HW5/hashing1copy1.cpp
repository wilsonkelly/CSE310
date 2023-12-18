#include <iostream>
#include <unordered_map>
using namespace std;

struct Account {
    int accountNumber;
    string ownerName;
    double balance;
};

const int M = 753;

int Hash_Function(int key) {
    return key % M;
}

void clearAccount(Account& acc) {
    acc.ownerName = "";
    acc.balance = 0;
    acc.accountNumber = 0;
}

void INSERTAccount(unordered_map<int, Account>& table, Account acc) {
    int hash = Hash_Function(acc.accountNumber - 100000);
    table[hash] = acc;
    cout << "Account inserted!" << endl;
}

void DELETE_Account(unordered_map<int, Account>& table, Account acc) {
    int hash = Hash_Function(acc.accountNumber - 100000);
    auto it = table.find(hash);
    if (it != table.end()) {
        table.erase(it);
        cout << "Account removed" << endl;
    }
    else {
        cout << "Not found!" << endl;
    }
}

Account SEARCH_Account(unordered_map<int, Account>& table, Account acc) {
    int hash = Hash_Function(acc.accountNumber - 100000);
    auto it = table.find(hash);
    if (it != table.end()) {
        return it->second;
    }
    else {
        clearAccount(acc);
        return acc;
    }
}

int main() {
    int buckets = 800;
    unordered_map<int, Account> table;
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
                return 0;
        }
        clearAccount(acc);
    }
}
