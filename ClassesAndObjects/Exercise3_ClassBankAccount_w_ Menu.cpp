#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
/*Write a program, make a Class Bank Account. The class should have:
User Name
Account Num ( array of chars )
Balance ( the balance should be floating point number )
METHODS:
Print – Print all Info of the account ( Name, Account Num, Balance )
Add Balance – Add balance method ( you can not add ZERO or Negative balance )
Withdraw Balance – Withdraw balance method ( you can not withdraw ZERO or Negative balance )
Set Initial Balance – Set Initial balance method
Set Account Number – Setting account number Example ( BGN12 )
GetBalance – returning current balance 
Write extern function that modifies the account, while the user chose to exit.
Would you like to do ?
Press 1 to Show All Information...
Press 2 to Add Balance...
Press 3 to Withdraw Balance...
Press 0 to Exit Program...
*/

class BankAccount {
private:
	string user;
	string accountNum;
	double balance;

public:
	BankAccount(string user_, string accountNum_, double balance_) :
		user(user_),
		accountNum(accountNum_),
		balance(balance_) {

	}

	BankAccount() {
		balance = 0;
	}

	void setInitialBalance(double balance_) {
		balance = balance_;
	}

	void setAccountNum(string accountNum_) {
		accountNum = accountNum_;
	}
	void print() {
		cout << "Name : " << user << endl
			<< "Account number : " << accountNum << endl
			<< "Balance : " << balance << endl;
	}

	double getBalance() {
		return(balance);
	}

	double addBalance(double addedBalance) {
		return(balance += addedBalance);
	}

	void withdrawBalance(double withdrawBalance) {
		if (balance < withdrawBalance) {
			cout << "Not Enought Balance !" << endl; return;
		}
		balance -= withdrawBalance;
	}
};

enum choice { Exit = 0, ShowAll, AddB, WithdrawB };

choice menu(BankAccount &account) {
	
	cout << endl << "Would you like to do ?" << endl
		<< "Press 1 to Show All Information..." << endl
		<< "Press 2 to Add Balance..." << endl
		<< "Press 3 to Withdraw Balance..." << endl
		<< "Press 0 to Exit Program...;" << endl << endl;
		
	int choosen;
	cin >> choosen;
	switch ((choice)choosen)
	{
	case Exit:
		break;
	case ShowAll: account.print();
		break;
	case AddB: 
		cout << "Enter Balance to Add: " << endl;
		double addedBalance;
		cin >> addedBalance;
		account.addBalance(addedBalance);
		cout << "Added: " << addedBalance << endl
			<< "New Balance: " << account.getBalance() << endl;
		break;
	case WithdrawB: 
		cout << "Enter balance to Withdraw:" << endl;
		double withdrawBalance;
		cin >> withdrawBalance;
		account.withdrawBalance(withdrawBalance);
		break;
	default:
		cout << "It is a wrong choice!";
		break;
	}

	return((choice)choosen);
}

int main() {
	string user;
	string accountType;
	int initBalance;

	cout << "Enter Name: " << endl;
	cin >> user;

	cout << "Enter 5 charactes IBAN Code: " << endl;
	cin >> accountType;

	cout << "Enter Initial Balance: " << endl;
	cin >> initBalance;

	BankAccount account(user, accountType, initBalance);

	while (menu(account) != Exit);

	return 0;
}