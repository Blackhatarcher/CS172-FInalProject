#pragma once
#include <string>

using namespace std;

class Catagory
{
protected:
	string name;
public:
	Catagory();
	Catagory(string n);
	~Catagory();
	string getName();
};

