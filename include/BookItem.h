#pragma once
#include<iostream>
#include<string>
using namespace std;
class BookItem
{
private:

	//to get total payroll 
	double pay;
	string bookORty;
	int bookORid;

public:
	BookItem();
	~BookItem();
	void addOrder(string t, int id, double p);
	void printOrder();
	double getpay();

	int getID();

};


