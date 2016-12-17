#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Record.h"
using namespace std;

class Account
{
protected:
	vector<Record> records;
	double balance;
	string name;

public:
	Account();
	Account(string n);
	~Account();
	double getBalance();
	void changeBalance(double x);
	string getName();
	void transfer(double x, Account a);
	void update();
};

