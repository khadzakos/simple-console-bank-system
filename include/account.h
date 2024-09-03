#pragma once

#include <string>

class account {   
public:
    account(int number, std::string name, double initialBalance) 
        : account_number(number), account_holder(name), balance(initialBalance) {}

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    void transfer(account &recipient, double amount);

    int getAccountNumber() const { return account_number; }
    std::string getAccountHolder() const { return account_holder; }

private:
    int account_number;
    std::string account_holder;
    double balance;
};