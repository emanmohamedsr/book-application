#include "phoneNumber.h"

phoneNumber::phoneNumber() :phone(" "), type(" ")
{
}
phoneNumber::~phoneNumber()
{
}


void phoneNumber::addNumber()
{
	cout << "Enter phoneNumber : ";
	cin >> phone;
	cout << "Enter type : ";
	cin >> type;
}
void phoneNumber::printNumber()
{
	cout << "Phone Number : " << phone << " , " << type << endl;
}