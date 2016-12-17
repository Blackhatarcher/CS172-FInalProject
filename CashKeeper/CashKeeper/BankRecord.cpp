#include "stdafx.h"
#include "BankRecord.h"

template <typename T>
std::string to_string(T const& value) {
	stringstream sstr;
	sstr << value;
	return sstr.str();
}

BankRecord::BankRecord()
{

}
BankRecord::BankRecord(string d, double a, string s, double i, double f) {
	amount = a;
	date = d;
	initial_balance = i;
	final_balance = f;
	s = source;
}

BankRecord::~BankRecord()
{
}
// return a nicely formated string version
string BankRecord::getString() {
	return to_string(amount) + "was added : Intitial Balance " + to_string(initial_balance) + " Final Balance " + to_string(final_balance);

}
//return a string version to be written to a file
string BankRecord::getRecord() {
	return "2 " + date + " " + to_string(amount) + " " + source + " " + to_string(initial_balance) + " " + to_string(final_balance);
}
