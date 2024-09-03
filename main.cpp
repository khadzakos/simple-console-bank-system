#include <iostream>
#include "account.h"
#include "bank_system.h"

int main() {
    BankSystem manager = BankSystem("accounts.txt");
    bool running = true;
    while (running) {
        manager.displayMenu();
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::string name;
                double initialDeposit;
                std::cout << "Enter your name: ";
                std::cin >> name;
                std::cout << "Enter initial deposit: ";
                std::cin >> initialDeposit;
                manager.createAccount(name, initialDeposit);
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                manager.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                manager.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                double balance = manager.getBalance(accountNumber);
                if (balance != -1) {
                    std::cout << "Balance: " << balance << std::endl;
                }
                break;
            }
            case 5: {
                int senderAccountNumber, recipientAccountNumber;
                double amount;
                std::cout << "Enter sender account number: ";
                std::cin >> senderAccountNumber;
                std::cout << "Enter recipient account number: ";
                std::cin >> recipientAccountNumber;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                manager.transfer(senderAccountNumber, recipientAccountNumber, amount);
                break;
            }
            case 6:
                manager.displayAccounts();
                break;
            case 7:
                running = false;
                manager.endProgram();
                break;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
                break;
        }
    }
}

