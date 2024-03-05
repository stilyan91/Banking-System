#ifndef ACCOUNT_H
#define ACOUNT_H

#include <iostream>
#include <execution>

class Account
{
private:
	double amount;

	static double getValidAmount(std::istream& in)  {
		double bufer;
		std::cout << "Enter a amount: " << std::endl;
		if (in >> bufer)
			return bufer;
		else
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid input. Please enter a number!" << std::endl;
			return getValidAmount(in);
	}
public:
	Account(double amount) : amount(amount) {
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
	double newAmount;
	try
	{
		if(in >> newAmount)
			amount += newAmount;
		else {
			throw std::invalid_argument("You must enter a number!");
			deposit(in);
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "You have deposited : " << newAmount << std::endl;
}

void Account::withdraw(std::istream& in) {
	double withdrawed = getValidAmount(in);
	this->amount -= withdrawed;
	std::cout << "Your withdrawed: "
		<< withdrawed << std::endl;
}
#endif // !ACCOUNT_H
