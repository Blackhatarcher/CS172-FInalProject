#include "stdafx.h"
#include "Account.h"

//defualt account constructor that makes an account with a name of "account" and balance 0
Account::Account() {
	vector<Record> records;
	name = "account";
	balance = 0.0;
}
//create and account of balance b and name n
Account::Account(double b, string n) {
	vector<Record> records;
	name = n;
	balance = b;
}
// will rewrite the coresponding file with the contents of records
Account::~Account() {
	
}
//returns balance
double Account:: getBalance() {
	return balance;
}
//will change balance by x
void Account:: changeBalance(double x) {
	balance += x;
}
//return name
string Account:: getName() {
	return name;
}
// will reduce balance by x and then will add it to a 's balance
void Account:: transfer(double x, Account a) {
	balance -= x;
	a.changeBalance(x);
}
//will open or create a file for this account 
// and construct a series of record objects and populate this accounts's records with them
//and set this accounts balance based on what what's on file
void Account:: update() {

}
