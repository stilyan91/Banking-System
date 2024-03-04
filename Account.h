#ifndef ACCOUNT_H
#define ACOUNT_H

#include <iostream>

class Account
{
private:
	double amount;
public:
	Account(double amount) : amount(amount){}

	Account(std::istream& in);

	void deposit(double newAmount) { this->amount += newAmount; }

	double getBalance() const { return amount; }

	void withdraw(double amount) { this->amount -= amount; }

};

Account::Account(std::istream& in) {
	in >> amount;
}
#endif // !ACCOUNT_H