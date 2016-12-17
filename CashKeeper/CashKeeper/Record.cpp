#include "stdafx.h"
#include "Record.h"
#include <sstream>

template <typename T>
std::string to_string(T const& value) {
	stringstream sstr;
	sstr << value;
	return sstr.str();
}

Record::Record(string d, double a, string s) {
	date = d;
	amount = a;
	source = s;
}
Record::~Record() {

}
string Record::getDate() {
	return date;
}
double Record::getAmount() {
	return amount;
}

Record::Record()
{
	amount = 0.0;
	date = "";
}
string Record::getSource() {
	return source;
}
// return a nicely formatted string version
string Record::getString() {
	return to_string(amount) + " was added on " + date + " to " + source;
}

//return a record that can be written to a file
//the first digit will tell me if it is 
//0 a record
//1 a purchase record 
//2 a bank record
string Record::getRecord() {
	return "0 " + date + " " + to_string(amount) + source;
}