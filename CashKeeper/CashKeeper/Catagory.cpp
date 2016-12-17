#include "stdafx.h"
#include "Catagory.h"

Catagory::Catagory()
{
	name = "";
}
Catagory::Catagory(string n) {
	name = n;
}

Catagory::~Catagory()
{
}

string Catagory::getName() {
	return name;
}