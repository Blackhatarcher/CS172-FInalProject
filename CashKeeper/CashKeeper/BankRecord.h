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
	BankRecord(string d, double a, string s, double i, double f);
	~BankRecord();
	string getString();
	string getRecord();
};

