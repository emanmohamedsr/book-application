#pragma once
#include <String.h>
#include <iostream>
using namespace std;

class Email
{
private:
	string email;
	string type;
public:
	Email();
	~Email();
	//set email
	void addEmail();
	//get email
	void printEmail();
};

