#pragma once
#include"customer.h"
#include"Book.h"
#include <cstdlib>///system("cls")
#include <Windows.h>
class System
{
private:

	//array of Books
	int libCount;
	int libSize;
	Book* library;
	//array of sold books
	int soldCount;
	Book* listOfSoldBooks;
	//array of customers
	int cutsSize;
	int custCount;
	customer* customerList;
public:
	System();
	~System();

	void setColor(int color);
	void separator(int);
	void Types();

	//**//fill library
	void addBook();
	void searchBook();
	void deleteBook();
	void editBook();
	//**//information department
	void printBooks();
	int counter(string type);
	void getinfo();
	void shortage();
	//**//sales department
	void makeOrder();
	void printCustomer();
	void printAllCustomer();
	void searchCustomer();
	void deleteOrCancel();
	void deleteCustomer();   //1
	void returnBook(int id); //0
	void CancelAnOrder();    //1


};

