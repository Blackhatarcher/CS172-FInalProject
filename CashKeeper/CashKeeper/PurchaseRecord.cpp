#include "stdafx.h"
#include "PurchaseRecord.h"

template <typename T>
std::string to_string(T const& value) {
	stringstream sstr;
	sstr << value;
	return sstr.str();
}

PurchaseRecord::PurchaseRecord() {

}
PurchaseRecord::PurchaseRecord(string d, double a, string s, Catagory c)
{
	catagory = c;
	date = d;
	amount = a;
	source = s;
}

PurchaseRecord::~PurchaseRecord()
{
}

string PurchaseRecord::getCatagory() {
	return catagory.getName();
}
string PurchaseRecord::getString() {
	return to_string(amount) + " was spent on " + getCatagory();
}
string PurchaseRecord::getRecord() {
	return "1 " + date + " " + to_string(amount) +" "+ source + " " + getCatagory();
}