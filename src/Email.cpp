#include "Email.h"

Email::Email() : email(" "), type(" ")
{
}

Email::~Email()
{
}


void Email::addEmail()
{
	cout << "Enter Email : ";
	cin >> email;
	cout << "Enter type : ";
	cin >> type;
}

void Email::printEmail()
{
	cout << "*Email : " << email << " *Type : " << type << endl;
}