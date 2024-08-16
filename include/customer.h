#pragma once
#include "phoneNumber.h"//array of phone numbers
#include "Email.h"//array of emials
#include"BookItem.h"
class customer
{
private://data
	int customerNumber;
	string name;
	int age;
	string address;
	string dateOfOrder;
	int Size;
	//array of phones
	int phoneCount;
	phoneNumber* phone;
	//array of emials
	int emailCount;
	Email* email;

	//array of ordres
	int orderSize;
	int orderCount;
	BookItem* orderList;

	double totalPay;
public:

	customer();
	~customer();
	//get custome rinfo (email,phone)
	void addAAAcustomer();
	//fill array of orders
	void addorddre(string type, int id, double price);
	void printorddre();
	//return orders total count
	int ordercount();
	//return orders id untill total count by using for loop
	int returnOrderid(int);
	//print customer info and orders
	void printAAAcustomer();
	//return customer nymber to search
	int getCustomerNumber();
	double getTotalPay();//of orders
};


