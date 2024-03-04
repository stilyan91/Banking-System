#include <iostream>
#include "Account.h"


int main() {
	Account acc(std::cin);
	std::cout << acc.getBalance() << std::endl;
	acc.deposit(10);
	std::cout << acc.getBalance() << std::endl;
	acc.withdraw(2);
	std::cout<<acc.getBalance() << std::endl;
}

