#include <iostream>
#include "Account.h"


int main() {
	Account acc(std::cin);
	acc.getBalance();
	acc.deposit(std::cin);
	acc.getBalance();
	acc.withdraw(std::cin);
	acc.getBalance();
}

// Main Functionality Class
/*

class BankingSystem {
public:
    void run();
    void createAccount();
    void deposit();
    void withdraw();
    void closeAccount();
    void balanceEnquiry();
private:
    // Add necessary data members and helper functions
};

// Account Class
class Account {
public:
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
private:
    // Add necessary data members
};

// Main Function
int main() {
    BankingSystem bankingSystem;
    bankingSystem.run();
    return 0;
}
*/