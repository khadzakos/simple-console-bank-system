#include "bank_system.h"

#include <iostream>
#include <fstream>
#include <sstream>

void BankSystem::loadAccounts(const std::string &filename) {
    std::ifstream in;
    in.open(filename);
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) 
            continue;
        std::istringstream iss(line);
        int number;
        std::string name;
        double balance;
        if (iss >> number >> name >> balance) {
            accounts.push_back(account(number, name, balance));
            nextAccountNumber = number + 1;
        }
    }
    in.close();
}

void BankSystem::saveAccounts(const std::string &filename) {
    std::ofstream out;
    out.open(filename);
    for (const account &acc : accounts) {
        out << acc.getAccountNumber() << " " << acc.getAccountHolder() << " " << acc.getBalance() << std::endl;
    }
    out.close();
}

BankSystem::BankSystem(const std::string &filename) {
    loadAccounts(filename);
}

BankSystem::~BankSystem() {
    saveAccounts("accounts.txt");
}

void BankSystem::createAccount(const std::string &name, double initialBalance) {
    accounts.push_back(account(nextAccountNumber, name, initialBalance));
    nextAccountNumber++;
}

void BankSystem::deposit(int accountNumber, double amount) {
    int l = 0, r = accounts.size();
    while (r - l >= 1) {
        int m = (l + r) / 2;
        if (accounts[m].getAccountNumber() <= accountNumber) {
            l = m;
        } else if (accounts[m].getAccountNumber() > accountNumber) {
            r = m;
        }
    }
    if (accounts[l].getAccountNumber() == accountNumber) {
        accounts[l].deposit(amount);
        return;
    }
    std::cout << "Account not found" << std::endl;
}

void BankSystem::withdraw(int accountNumber, double amount) {
    int l = 0, r = accounts.size();
    while (r - l >= 1) {
        int m = (l + r) / 2;
        if (accounts[m].getAccountNumber() <= accountNumber) {
            l = m;
        } else if (accounts[m].getAccountNumber() > accountNumber) {
            r = m;
        }
    }
    if (accounts[l].getAccountNumber() == accountNumber) {
        accounts[l].withdraw(amount);
        return;
    }
    std::cout << "Account not found" << std::endl;
}

double BankSystem::getBalance(int accountNumber) {
    int l = 0, r = accounts.size();
    while (r - l >= 1) {
        int m = (l + r) / 2;
        if (accounts[m].getAccountNumber() <= accountNumber) {
            l = m;
        } else if (accounts[m].getAccountNumber() > accountNumber) {
            r = m;
        }
    }
    if (accounts[l].getAccountNumber() == accountNumber) {
        return accounts[l].getBalance();
    }
    std::cout << "Account not found" << std::endl;
    return -1;
}

void BankSystem::transfer(int senderAccountNumber, int recipientAccountNumber, double amount) {
    int l = 0, r = accounts.size();
    while (r - l >= 1) {
        int m = (l + r) / 2;
        if (accounts[m].getAccountNumber() <= senderAccountNumber) {
            l = m;
        } else if (accounts[m].getAccountNumber() > senderAccountNumber) {
            r = m;
        }
    }
    if (accounts[l].getAccountNumber() == senderAccountNumber) {
        int senderIndex = l;
        l = 0, r = accounts.size();
        while (r - l >= 1) {
            int m = (l + r) / 2;
            if (accounts[m].getAccountNumber() <= recipientAccountNumber) {
                l = m;
            } else if (accounts[m].getAccountNumber() > recipientAccountNumber) {
                r = m;
            }
        }
        if (accounts[l].getAccountNumber() == recipientAccountNumber) {
            accounts[senderIndex].transfer(accounts[l], amount);
            return;
        }
        std::cout << "Recipient account not found" << std::endl;
        return;
    }
    std::cout << "Sender account not found" << std::endl;
}

void BankSystem::displayAccounts() {
    for (const account &acc : accounts) {
        std::cout << "Account number: " << acc.getAccountNumber() << std::endl;
        std::cout << "Account holder: " << acc.getAccountHolder() << std::endl;
        std::cout << "Balance: " << acc.getBalance() << std::endl;
        std::cout << std::endl;
    }
}

void BankSystem::endProgram() {
    saveAccounts("accounts.txt");
}

void BankSystem::displayMenu() {
    std::cout << "Chose an option: " << std::endl;
    std::cout << "1. Create an account" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Balance" << std::endl;
    std::cout << "5. Transfer" << std::endl;
    std::cout << "6. Display accounts" << std::endl;
    std::cout << "7. Exit" << std::endl;
}