#include "Bank.hpp"

#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

map<std::string, Account> Account::data;

string Account::getAccountName(){
    return acc_name;
}

double Account::get_bal() const {
    cout << bal << endl;
    return bal;
}

void Account::deposit(double money, Account& acc) {
    acc.bal += money;
    cout << "New Balance: " << acc.get_bal() << endl;
}

void Account::withdraw(double money, Account& acc) {
    acc.bal -= money;
    cout << "New Balance: " << acc.get_bal() << endl;
}

void Menu() {
    bool running = true;
    while (running) {
        int choice;
        cout << "[1]: Sign up" << endl;
        cout << "[2]: Login" << endl;
        cout << "[3]: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int temp_pin;
                string temp_accName;
                cout << "Enter new Account name:" << endl;
                cin >> temp_accName;
                cout << "Enter new pin:" << endl;
                cin >> temp_pin;
                Account current = Account(temp_pin, temp_accName);
                SignUp(current);
                break;
            }
            case 2: {
                int temp_pin;
                string temp_accName;
                cout << "Enter Account name:" << endl;
                cin >> temp_accName;
                cout << "Enter pin:" << endl;
                cin >> temp_pin;
                // Handle login
                break;
            }
            case 3:
                cout << "Exiting program." << endl;
                running = false; // Set running to false to exit the loop
                break;
            default:
                cout << "Invalid input, Retry" << endl;
                // Clear input stream to prevent infinite loop on bad input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}

void SignUp(Account acc) {
    int x;
    double y;
    while (true) {
        cout << "[1]: Get Balance" << endl;
        cout << "[2]: Withdraw" << endl;
        cout << "[3]: Deposit" << endl;
        cout << "[4]: Exit" << endl;
        cin >> x;
        if (x == 4) { break; }
        switch (x) {
        case 1:
            acc.get_bal();
            break;
        case 2:
            cout << "Amount to withdraw:" << endl;
            cin >> y;
            if (y > acc.get_bal()) { cout << "Insufficient Funds" << endl; }
            else { acc.withdraw(y, acc); }
            break;
        case 3:
            cout << "Amount to Deposit:" << endl;
            cin >> y;
            if (y >= 0) {
                acc.deposit(y, acc);
            }
            else { cout << "Invalid Amount" << endl; }
            break;
        default:
            cout << "Invalid input" << endl;
        }
    }
    Account::data[acc.getAccountName()] = acc;
}
