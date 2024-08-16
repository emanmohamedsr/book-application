#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
	//data of each book
	string BookType;
	string m_bookName;
	int m_bookID;
	int m_pages;
	double m_price;

public:

	Book();
	~Book();
	//print book in customers class
	void printBook();
	//add book book in customers class
	//takes type to add a different type (not main types)
	void ADDABOOK(string type);
	//search for book
	int getID() const;
	//make counter function and add type to fill oreder date
	string getType() const;
	//add price to order
	double getPrice() const;


};

