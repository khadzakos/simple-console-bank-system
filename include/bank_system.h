#pragma once

#include "account.h"
#include <vector>

class BankSystem {
    public:
        BankSystem(const std::string &filename);
        ~BankSystem();

        void createAccount(const std::string &name, double initialBalance);
        void deposit(int accountNumber, double amount);
        void withdraw(int accountNumber, double amount);
        double getBalance(int accountNumber);
        void transfer(int senderAccountNumber, int recipientAccountNumber, double amount);

        void displayMenu();
        void displayAccounts();
        void endProgram();

    private:
        std::vector<account> accounts;
        int nextAccountNumber;

        void loadAccounts(const std::string &filename);
        void saveAccounts(const std::string &filename);
};