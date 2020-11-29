// Garrick Morley
// CPSC 200 Project 3 A
// This program uses classes

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
using namespace std;

//create class
class BankAccount
{
	public:
		//BankAccount();
		double getBalance();
		void deposit(double amt);
		bool withdraw(double amt);
				
	private:
		int balance;
		int acctNumber;
		string owner;		
};

//decalre the variable 
double amt;

//set up functions
double BankAccount::getBalance()
{
	return balance;
}
void BankAccount::deposit(double amt)
{
	balance += (amt + 0.005) * 100;
}
bool BankAccount::withdraw(double amt)
{
	if (amt > balance)
		return false;
	if (amt <= balance)
	{
		balance -= (amt + 0.005) * 100;
		return true;
	}
}

//execute the program
main()
{
	//set withdraw amount
	amt = 50;
	
	//put money in accounts and see if it worked
	BankAccount acct1, acct2;
	acct1.deposit(500);
	acct2.deposit(600);
	cout << "Account 1 balance: " << acct1.getBalance() / 100.0 << endl;
	cout << "Account 2 balance: " << acct2.getBalance() / 100.0 << endl;
	
	//test withdraw on account 1
	if (acct1.withdraw(amt) == true)
	{
		cout << "Withdraw on account 1 successful" << endl;
		cout << "Remaining balance on account 1: $" << acct1.getBalance() / 100 << endl;
	}
	else if (acct1.withdraw(amt) == false)
		cout << "Insufficient funds in account 1" << endl;
	
	//test withdraw on account 2
	if (acct2.withdraw(amt) == true)
	{
		cout << "Withdraw on account 2 successful" << endl;
		cout << "Remaining balance on account 2: $" << acct2.getBalance() / 100 << endl;
	}
	else if (acct2.withdraw(amt) == false)
		cout << "Insufficient funds in account 2" << endl;
}
