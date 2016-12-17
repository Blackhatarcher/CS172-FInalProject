#include "stdafx.h"
#include "Record.h"
#include <sstream>

template <typename T>
std::string to_string(T const& value) {
	stringstream sstr;
	sstr << value;
	return sstr.str();
}

Record::Record(string d, double a) {
	date = d;
	amount = a;
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
// return a nicely formatted string version
string Record::getString() {
	return to_string(amount) + " was added on " + date;
}
