#pragma once
#include <String.h>
#include <iostream>
using namespace std;

class phoneNumber
{
private:
	string phone;
	string type;
public:
	phoneNumber();
	~phoneNumber();
	//set phone
	void addNumber();
	//get phone
	void printNumber();
};
