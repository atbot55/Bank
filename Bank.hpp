#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

class Account {
private:
    double bal;
    string acc_name;
    int pin;
public:
    static std::map<std::string, Account> data;
    Account(int p, std::string acc) : bal(0), acc_name(acc), pin(p) { data.insert(std::make_pair(acc, *this)); }
    string getAccountName();
    double get_bal() const;
    void deposit(double money, Account& acc);
    void withdraw(double money, Account& acc);

    bool operator<(const Account& other) const {
        return acc_name < other.acc_name;
    }
};

void Menu();
void SignUp(Account acc);

#endif /* BANK_HPP */
