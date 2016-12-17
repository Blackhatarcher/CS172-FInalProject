#include "stdafx.h"
#include "PurchaseRecord.h"


PurchaseRecord::PurchaseRecord() {

}
PurchaseRecord::PurchaseRecord(Catagory c, string d, double a)
{
	catagory = c;
	date = d;
	amount = a;
}

PurchaseRecord::~PurchaseRecord()
{
}

string PurchaseRecord::getCatagory() {
	return catagory.getName();
}