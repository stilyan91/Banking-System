#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <iostream>
#include <map>
#include <thread>
#include <conio.h>

#include "Account.h"

class BankingSystem {
private:
	typedef std::map<int, Account> Accounts;
	Accounts accounts;

	static int accountId;
public:
	void run();
	void showMenu();
	void createAccount();
	auto findAccount(std::istream& in);
	void checkAmount(std::istream& in);
	void depositAmount(std::istream& in);
	void withdraw(std::istream& in);
	void deleteAccount(std::istream& in);
	void exitFunction(std::istream& in);
};

int BankingSystem::accountId = 0;

void BankingSystem::showMenu() {
	system("cls");
	std::cout << "Choose option (1-4): " << std::endl;
	std::cout << "1. Create Account" << std::endl;
	std::cout << "2. Check Account" << std::endl;
	std::cout << "3. Deposit Money" << std::endl;
	std::cout << "4. Withdraw Money" << std::endl;
	std::cout << "5. Close Account" << std::endl;
	std::cout << "0. Exit" << std::endl;	
}

void BankingSystem::run()  {
	std::cout << "Wellcome, you have just started a bank system!" << std::endl;
	showMenu();
	int option;
	while (true) {
		if (std::cin >> option) {
			try {
				switch (option)
				{
				case 1:
					system("cls");
					createAccount();
					showMenu();
					break;
				case 2:
					system("cls");
					checkAmount(std::cin);
					showMenu();
					break;
				case 3:
					system("cls");
					depositAmount(std::cin);
					showMenu();
					break;
				case 4:
					system("cls");
					withdraw(std::cin);
					showMenu();
					break;
				case 5:
					system("cls");
					deleteAccount(std::cin);
					showMenu();
					break;
				case 0:
					std::exit(0);
				default:
					system("cls");
					showMenu();
					throw std::invalid_argument("Invalid option!");
				}
			}
			catch (std::invalid_argument& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Please enter a valid operation." << std::endl;
			showMenu();
		}
	}
}

void BankingSystem::createAccount() {
	accountId++;
	accounts[accountId] = Account(std::cin);
	std::cout << "Your account ID is: " << accountId << 
				" Remember it." << std::endl;
	std::cout << "Press any key to continue..." << std::endl;
	(void)_getch();
	return;
}


auto BankingSystem::findAccount(std::istream& in) {
	int searchedId;
	while (true) {
		std::cout << "Enter Id of your Account: ";
		if (in >> searchedId) {
			std::map<int, Account>::iterator foundAcc = accounts.find(searchedId);
			if (foundAcc != accounts.end())
				return foundAcc;
			else
				std::cerr << "There is not a Account with that Id. Try again." << std::endl;
		}
	else {
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "There is not a Account with that Id. Try again." << std::endl;
			}
		}
	}

void BankingSystem::checkAmount(std::istream & in) {
	auto foundAcc = findAccount(in);
	foundAcc->second.getBalance();
	std::cout << "Press any key to continue..." << std::endl;
	(void)_getch();
	return ;
}

void BankingSystem::depositAmount(std::istream& in) {
	auto foundAcc = findAccount(in);
	foundAcc->second.deposit(std::cin);
	std::cout << "Press any key to continue..." << std::endl;
	(void)_getch();
	return;
}

void BankingSystem::withdraw(std::istream& in) {
	auto foundAcc = findAccount(in);
	foundAcc->second.withdraw(std::cin);
	std::cout << "Press any key to continue..." << std::endl;
	(void)_getch();
	return;
}

void BankingSystem::deleteAccount(std::istream& in) {
	auto foundAcc = findAccount(in);
	int answer;
	std::cout << "Are you sure you want to delete this Account?" << std::endl;
	std::cout << "Yes - 1 No - 2" << std::endl;
	bool isFinished = false;
	while (std::cin >> answer) {
		switch (answer)
		{
		case 1:
			isFinished = true;
			accounts.erase(foundAcc->first);
			std::cout << "Account was deleted succesfully" << std::endl;
			break;
		case 2:
			return;
		default:
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Please enter a valid operation." << std::endl;
			break;
		}
		if (isFinished)
			break;
	}
	std::cout << "Press any key to continue..." << std::endl;
	(void)_getch();
	return;
}


#endif // !BANKINGSYSTEM_H

 