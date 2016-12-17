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
public:
	string getDate();
	double getAmount();
	Record();
	Record(string d, double a);
	~Record();
	string getString();

};

