#include "stdafx.h"
#include "Account.h"
#include "PurchaseRecord.h"
#include "BankRecord.h"
#include <iostream>
#include <fstream>
#include <string>


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
	output.close();
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
			//create a pointer to a record object
			vector<string> temp_v; // this vector will hold a bunch of strings that will be used later to fill constructor parameters
			//look at the first character in temp_string and use it to determine what sort of record to construct
			
			string temp_string = thestring.substr(2);// this removes  the 0 1 or 2 and the space
			//gonna pull out indivigual substrings and add them to temp_v
			for (int i = 0; i < temp_string.length(); i++) {
				if (temp_string.substr(i, i) == " ") {
					temp_v.push_back(temp_string.substr(0, i-1));
					temp_string = temp_string.substr(i + 1);
				}
			}
			//now I have a vector full of strings
			
			if (thestring.substr(0,0) == "0"){
				//make record class
				string s = temp_v.at(1);// for some reason if I try to nest this operation inside the constructor I get compiler errors
				double thing = stod(s);// this will at least compile
				Record rec(temp_v.at(0),thing, temp_v.at(2));
			}
			if (thestring.substr(0, 0) == "1") {
				//make purchaserecord class
				string s = temp_v.at(1);// for some reason if I try to nest this operation inside the constructor I get compiler errors
				double thing = stod(s);// this will at least compile
				string s2 = temp_v.at(3);
				Catagory cat(s2);
				PurchaseRecord rec(temp_v.at(0), thing, temp_v.at(2), cat);
			}
			else {
				//make bankrecord class
				string s1 = temp_v.at(1);
				double thing1 = stod(s1);

				string s2 = temp_v.at(3);
				double thing2 = stod(s2);

				string s3 = temp_v.at(4);
				double thing3 = stod(s3);

				BankRecord rec(temp_v.at(0), thing1, temp_v.at(2),thing2, thing3);
			}
			records.push_back(will_be_added);
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
