#pragma once
#include "Record.h"
#include "Catagory.h"

class PurchaseRecord : public Record
{
protected:
	Catagory catagory;
public:
	PurchaseRecord();
	PurchaseRecord(Catagory c, string d, double a);
	~PurchaseRecord();
	string getCatagory();
};

