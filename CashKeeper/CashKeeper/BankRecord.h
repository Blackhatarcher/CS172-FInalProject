#pragma once
#include "Record.h"
#include <string>
using namespace std;

class BankRecord : public Record
{
protected:
	double initial_balance;
	double final_balance;
public:
	BankRecord();
	BankRecord(double a, string d, double i, double f);
	~BankRecord();
	string getString();

};

