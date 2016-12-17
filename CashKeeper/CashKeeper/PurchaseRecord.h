#pragma once
#include "Record.h"
#include "Catagory.h"

class PurchaseRecord : public Record
{
protected:
	Catagory catagory;
public:
	PurchaseRecord();
	PurchaseRecord( string d, double a, string s, Catagory c);
	~PurchaseRecord();
	string getCatagory();
	string getString();
	string getRecord();
};

