#include "BankAccount.h"

int BankAccount::total = 0;

BankAccount::BankAccount()
{
	BankAccount::balance = 0;
}

BankAccount::BankAccount(int input) {
	BankAccount::balance = input;
	BankAccount::total += input;
}
void BankAccount::withdraw(int output) {
	BankAccount::balance -= output;
	BankAccount::total -= output;

}
void BankAccount::save(int input) {
	BankAccount::balance += input;
	BankAccount::total += input;

}
int BankAccount::getBalance() {
	return BankAccount::balance;
}

int BankAccount::getAllMoneyInBank()
{
	return BankAccount::total;
}
