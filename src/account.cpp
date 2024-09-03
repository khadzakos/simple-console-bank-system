#include "account.h"

#include <iostream>

void account::deposit(double amount) {
    if (amount < 0) {
        std::cout << "Invalid amount" << std::endl;
        return;
    }
    balance += amount;
}

void account::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Invalid amount" << std::endl;
        return;
    }
    if (balance < amount) {
        std::cout << "Insufficient funds" << std::endl;
        return;
    }
    balance -= amount;
}

double account::getBalance() const {
    return balance;
}

void account::transfer(account &recipient, double amount) {
    if (balance < amount) {
        std::cout << "Insufficient funds" << std::endl;
        return;
    }
    withdraw(amount);
    recipient.deposit(amount);
}