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
BankRecord::BankRecord(double a, string d, double i, double f) {
	amount = a;
	date = d;
	initial_balance = i;
	final_balance = f;
}

BankRecord::~BankRecord()
{
}
// return a nicely formated string version
string BankRecord::getString() {
	return to_string(amount) + "was added : Intitial Balance " + to_string(initial_balance) + " Final Balance " + to_string(final_balance);

}
