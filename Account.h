#ifndef ACCOUNT_H
#define ACOUNT_H

#include <iostream>
#include <execution>

class Account
{
private:
	double amount;

	bool checkValidBalance() {
		if (this->amount < 0)
			return false;
		return true;
	}

	double getValidAmount(std::istream& in)  {
		double bufer;
		std::cout << "Enter a amount: " << std::endl;
		if (in >> bufer)
		{
			while (bufer < 0) {
				std::cerr << "Amount can't be smaller than 0!" << std::endl;
				in.clear();
				in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter a number greater or equal to zero" << std::endl;
				in >> bufer;
			}
			return bufer;
		}
		else {
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid input. Please enter a number!" << std::endl;
			return getValidAmount(in);
		}
	}
public:
	Account(double amount) : amount(checkValidBalance() ? amount : 0) {
		std::cout << "You have successfully created a new Account." << std::endl;
	}

	Account(std::istream& in) : amount(getValidAmount(in)) { 
		std::cout << "You have successfully created a new Account." << std::endl; 
	}

	void deposit(double newAmount) { this->amount += newAmount;
		std::cout << "You have deposited : " 
			<< newAmount << std::endl;
	}

	void deposit(std::istream& in);

	double getBalance() const { 
		std::cout << "Your current balance is: " << amount << std::endl;
			return amount; }

	void withdraw(double amount) { this->amount -= amount;
		std::cout << "Your withdrawed: " 
				<< amount << std::endl;
	}

	void withdraw(std::istream& in);

};

void Account::deposit(std::istream& in) {
	std::cout << "Your are depositing!" << std::endl;
	double newAmount = getValidAmount(in);
	while (!newAmount) {
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		in >> newAmount;
	}
	this->amount += newAmount;
	std::cout << "You have deposited : " << newAmount << std::endl;
}

void Account::withdraw(std::istream& in) {
	std::cout << "You are withdrawing!" << std::endl;
	double withdrawed = getValidAmount(in);
	while (this->amount - withdrawed < 0)
	{
		std::cout << "You don't have enought money!" << std::endl;
		withdrawed = getValidAmount(in);
	}
	
	this->amount -= withdrawed;
	std::cout << "Your withdrawed: "
		<< withdrawed << std::endl;
}
#endif // !ACCOUNT_H
