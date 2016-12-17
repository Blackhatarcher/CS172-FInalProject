#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Record.h"
using namespace std;
class Record
{
protected:
	string date;
	double amount;
	string source;
public:
	string getDate();
	double getAmount();
	string getSource();
	Record();
	Record(string d, double a, string s);
	~Record();
	string getString();

	string getRecord();

};

