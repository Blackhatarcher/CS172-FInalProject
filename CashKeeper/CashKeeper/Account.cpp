#include "stdafx.h"
#include "Account.h"
#include <iostream>
#include <fstream>

//defualt account constructor that makes an account with a name of "account" and balance 0
Account::Account() {
	vector<Record> records;
	name = "account";
	balance = 0.0;
}
//create and account of balance b and name n
Account::Account(string n) {
	vector<Record> records;
	name = n;
	balance = 0;
	update();
}
// will rewrite the coresponding file and populate it with records
//and rewrite the balance file
Account::~Account() {
	ofstream output;
	// this will destroy the old file but I don't care because i've got its contents in memory right now
	output.open(name + ".txt");
	//loop through records call its getRecord function
	//the method is overwritten on it child classes
	for (int i = 0; i < records.size(); i++) {
		output << records[i].getRecord() << endl;
	}
	//don't forget to close
	output.close();

	//didn't use the new key ward so I think the vector records get taken care of automatically
	//no need to delete it


	ofstream output(name + "balance" + ".txt"); // again not caring if the file gets deleted
	output << balance;

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
// will read from the accounts .txt file
// and then construct record objects from all of the lines on the file
// and add them to the records vector
//then open the account balance txt 
//and set the balance based on that
void Account:: update() {
	string thestring;
	ifstream input(name + ".txt");
	if (!(input.fail())) {
		while (!input.eof())// will loop through whole file
		{
			input >> thestring;

			vector<string> temp_v; // this vector will hold a bunch of strings that will be used later to fill constructor parameters
			//look at the first character in temp_string and use it to determine what sort of record to construct
			
			string temp_string = thestring.substr(1);// this removes  the 0 1 or 2 
			//gonna pull out indivigual substrings and add them to temp_v
			for (int i = 0; i < temp_string.length(); i++) {

			}
			
			if (thestring.substr(0,0) == "0"){
				//make record class

			}
			if (thestring.substr(0, 0) == "1") {
				//make purchaserecord class
			}
			if (thestring.substr(0, 0) == "2") {
				//make bankrecord class
			}
		}
	}
	input.close();
	//could indlude an else function taht will output to the console if the file doesn't exist

	ifstream input(name + "balance" + ".txt");
	if (!(input.fail())) {
		input >> balance;
	}
	input.close();
	//could indlude an else function taht will output to the console if the file doesn't exist


}
