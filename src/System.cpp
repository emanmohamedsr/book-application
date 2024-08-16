#include "System.h"

void System::setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void System::separator(int color)
{
	setColor(color);
	for (int i = 0; i < 55; i++)
		cout << '_';
	cout << endl;
	setColor(15);
}

System::System() :libSize(200), libCount(0), cutsSize(100), custCount(0), soldCount(0)
{
	library = new Book[libSize];
	listOfSoldBooks = new Book[libSize];
	customerList = new customer[cutsSize];


}
System::~System()
{
	delete[] customerList;
	delete[] listOfSoldBooks;
	delete[] library;
}
//library system
void System::Types()
{
	cout << "Enter Book type ... \n"
		<< "1) Religious " << endl
		<< "2) Autobiography " << endl
		<< "3) Adventure " << endl
		<< "4) Childern " << endl
		<< "5) Scientific " << endl
		<< "-> 6) add another type " << endl
		<< "Your Choice! ";
}
void System::addBook()
{
	string type;
	char n;
	int ch;
	do {
		Types();
		cin >> ch;

		switch (ch)
		{
		case 1:
			library[libCount++].ADDABOOK("Religious");
			cout << "A Religious book has been added \n";
			break;
		case 2:
			library[libCount++].ADDABOOK("Autobiography");
			cout << "An Autobiography book has been added \n";
			break;
		case 3:
			library[libCount++].ADDABOOK("Adventure");
			cout << "An Adventure book has been added \n";
			break;
		case 4:
			library[libCount++].ADDABOOK("Childern");
			cout << "A Childern book has been added \n";
			break;
		case 5:
			library[libCount++].ADDABOOK("Scientific");
			cout << "A Scientific book has been added \n";
			break;
		case 6:
			cout << "Enter the new type : ";
			cin >> type;
			library[libCount++].ADDABOOK(type);
			break;
		default:
			cout << "Invalied choice \n";
			break;
		}
		cout << "Add another? (y/n) : ";
		cin >> n;
	} while (n != 'n');

}
void System::searchBook()
{
	if (libCount == 0)
	{
		cout << "There isn't any book yet, Try to add books first \n";
		return;
	}
	int id;
	cout << "Enter book id to search : ";
	cin >> id;
	bool found = false;
	for (int i = 0; i < libCount; ++i)
	{
		if (library[i].getID() == id)
		{
			found = true;
			cout << "Book has been found successfully .. her it is .. \n";
			library[i].printBook();
			return;
		}
	}
	if (!found)
		cout << "Search Failed\n";
}
void System::deleteBook()
{
	if (libCount == 0)
	{
		cout << "There isn't any book yet, Try to add books first \n";
		return;
	}
	int id;
	cout << "Enter book id to delete : ";
	cin >> id;
	bool found = false;
	for (int i = 0; i < libCount; ++i)
	{
		if (library[i].getID() == id)
		{
			found = true;
			library[i] = library[libCount - 1];
			--libCount;
			cout << "Book has been deleted successfully \n";
			return;
		}
	}
	if (!found)
		cout << "Delete Failed\n";
}
void System::editBook()
{
	if (libCount == 0)
	{
		cout << "There isn't any book yet, Try to add books first \n";
		return;
	}
	int id;
	string BookType;
	cout << "Enter book id to edit : ";
	cin >> id;
	bool found = false;
	for (int i = 0; i < libCount; ++i)
	{
		if (library[i].getID() == id)
		{
			found = true;
			cout << "Book has been found .. here it is .. \n";
			library[i].printBook();
			cout << "\nEnter book new data ... \n";
			cout << "Enter Book type : ";
			cin >> BookType;
			library[i].ADDABOOK(BookType);
			cout << "Book has been modified successfully \n";
			return;
		}
	}
	if (!found)
		cout << "Edit Failed\n";
}
//information department
void System::printBooks()
{
	if (libCount == 0)
	{
		cout << "There isn't any book yet, Try to add books first \n";
		return;
	}
	int x = 0;
	int k;
	string type;
	int id;

	cout << "\tSome options of reporting Books ... \n"
		<< "\t___________________________________\n"
		<< "1) print all Books in the library\n"
		<< "2) Print Books of a specific type \n"
		<< "3) print a specific book \n"
		<< "Your choice! ";
	cin >> k;
	switch (k)
	{
	case 1:
	{

		for (int i = 0; i < libCount; ++i)
		{
			setColor(14);
			cout << "_____________" << i + 1 << "_____________\n";
			setColor(15);
			library[i].printBook();
		}
		break;
	}
	case 2:
	{
		cout << "Enter book type to print a category : ";
		cin >> type;
		for (int i = 0; i < libCount; ++i)
		{
			if (library[i].getType() == type)
			{
				setColor(14);
				cout << "____________" << ++x << "_____________\n";
				setColor(15);
				library[i].printBook();
			}
		}
		if (x == 0)
		{
			cout << "That type is empty or maybe you miss spelled the type \n";
		}
		break;
	}
	case 3:
	{
		cout << "Enter book id to print : ";
		cin >> id;
		bool found = false;
		for (int i = 0; i < libCount; ++i)
		{
			if (library[i].getID() == id) {
				found = true;
				library[i].printBook();
				return;
			}
		}
		if (!found)
			cout << "print failed\n";
		break;
	}
	default:
		cout << "Invalid choice\n";
		break;
	}
}
int System::counter(string type)
{
	int count = 0;
	for (int i = 0; i < libCount; ++i) {
		if (library[i].getType() == type)
			++count;
	}
	return count;
}
void System::getinfo()
{
	cout << "There is [" << libCount << "] in your library \n"
		<< "Divided into categories ...\n"
		<< counter("Religious") << " : Religious Books \n"
		<< counter("Autobiography") << " : Autobiography Books\n"
		<< counter("Adventure") << " : Adventure books\n"
		<< counter("Childern") << " : Childern books\n"
		<< counter("Scientific") << " : Scientific Books\n" << endl;
	//check if there are other types have been added
	if ((counter("Religious") + counter("Autobiography") + counter("Adventure") + counter("Scientific")) < libCount)
	{
		char ch;
		string y;
		cout << "-> there are some Books remain from types you have addded ... \n"
			<< "Inqure about them ? (y/n) : ";
		cin >> ch;
		while (ch != 'n') {
			cout << "Enter book type get his quantity : ";
			cin >> y;
			cout << counter(y) << " : " << y << " books\n"
				<< "another one ? (y/n) : ";
			cin >> ch;
		}

	}


}
void System::shortage()
{
	cout << "NOTE :: this part is for basic types of books " << endl;
	setColor(12);
	if (counter("Religious") < 4) { cout << "-> Religious\n"; }
	if (counter("Autobiography") < 4) { cout << "-> Autobiography\n"; }
	if (counter("Adventure") < 4) { cout << "-> Adventure\n"; }
	if (counter("Childern") < 4) { cout << "-> Childern\n"; }
	if (counter("Scientific") < 4) { cout << "-> Scientific\n"; }
	setColor(15);
	cout << "The types mentioned here contain NO more than [4] Books" << endl;
}
//customers & orders
void System::makeOrder()
{
	if (!(custCount < cutsSize))
	{
		cout << "Sorry, you can\'t add any more \n";
		return;
	}
	int id;
	int x = 0;
	char c;
	do
	{
		bool found = false;
		cout << "Enter book id to buy : ";
		cin >> id;
		for (int i = 0; i < libCount; i++)
		{
			if (library[i].getID() == id)
			{
				found = true;
				++x;
				customerList[custCount].addorddre(library[i].getType(), id, library[i].getPrice());
				listOfSoldBooks[soldCount++] = library[i];
				library[i] = library[libCount - 1];
				--libCount;
				break;
			}
			else
				found = false;

		}
		cout << "Add another order ? (y/n) : ";
		cin >> c;

	} while (c != 'n');
	if (x > 0)
	{
		customerList[custCount++].addAAAcustomer();
		cout << "Customer added successfully\n";
	}
	if (x == 0) {
		cout << "failed to add any order\n";
	}
}
void System::printCustomer()
{
	if (custCount == 0)
	{
		cout << "There isn\'t any customer yet\n";
		return;
	}
	int n;
	bool found = false;
	cout << "Enter customerNumber to print : ";
	cin >> n;
	for (int i = 0; i < custCount; ++i)
	{
		if (customerList[i].getCustomerNumber() == n)
		{
			found = true;
			customerList[i].printAAAcustomer();
			cout << " ... Orders ... \n";
			customerList[i].printorddre();
			cout << endl << "Toatl pay is : " << customerList[i].getTotalPay() << "$ " << endl;
			break;
		}
	}
	if (!found)
	{
		cout << "Print failed\n";
	}
}
void System::printAllCustomer()
{
	if (custCount == 0)
	{
		cout << "There isn\'t any customer yet\n";
		return;
	}
	for (int i = 0; i < custCount; ++i)
	{
		setColor(12);
		cout << "____________-" << i + 1 << "-_____________\n";
		setColor(15);
		customerList[i].printAAAcustomer();
		cout << " ... Orders ... \n";
		customerList[i].printorddre();
		cout << endl << "Toatl pay is : " << customerList[i].getTotalPay() << "$ " << endl;

	}
}
void System::searchCustomer()
{
	if (custCount == 0)
	{
		cout << "There isn\'t any customer yet\n";
		return;
	}
	int n;
	bool found = false;
	cout << "Enter customerNumber to search : ";
	cin >> n;
	for (int i = 0; i < custCount; ++i)
	{
		if (customerList[i].getCustomerNumber() == n)
		{
			found = true;
			cout << "Customer found successfully\n";
			break;
		}
	}
	if (!found)
		cout << "Search failed\n";

}
//
void System::deleteCustomer()
{
	int n;
	bool found = false;
	cout << "Enter customerNumber to Delete : ";
	cin >> n;
	for (int i = 0; i < custCount; ++i)
	{
		if (customerList[i].getCustomerNumber() == n)
		{
			found = true;
			customerList[i] = customerList[custCount - 1];
			--custCount;
			cout << "Customer has been deleted successfully\n";
			break;
		}
	}
	if (!found)
	{
		cout << "Delete failed\n";
	}
}
//
void System::returnBook(int id)
{
	for (int i = 0; i < soldCount; i++)
	{
		if (listOfSoldBooks[i].getID() == id)
		{
			//add to library again
			library[libCount++] = listOfSoldBooks[i];
			//delte from sold books
			listOfSoldBooks[i] = listOfSoldBooks[soldCount - 1];
			--soldCount;
		}
	}
}
void System::CancelAnOrder()
{
	int n;
	bool found = false;
	cout << "Enter customerNumber to Cancel : ";
	cin >> n;
	for (int i = 0; i < custCount; ++i)
	{
		//search for customer
		if (customerList[i].getCustomerNumber() == n)
		{
			found = true;
			//orderCount returns how many order for that customer
			for (int j = 0; j < customerList[i].ordercount(); ++j)
			{
				//  (returnBook)   restores books
				//  (returnOrder) returns id of each order
				returnBook(customerList[i].returnOrderid(j));
			}
			//after restoring books -> delete customer
			customerList[i] = customerList[custCount - 1];
			--custCount;

			cout << "Customer has been canceled successfully\n";
			break;
		}
	}
	if (!found)
	{
		cout << "Cancel failed\n";
	}

}
//
void System::deleteOrCancel()
{
	if (custCount == 0)
	{
		cout << "There isn\'t any customer yet\n";
		return;
	}
	int ch;
	cout << "Do you want to...(1)Delete completely\t  (2)Cancel and restore Books ? \n";
	cout << "Your choice -> ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		deleteCustomer();
		break;
	case 2:
		CancelAnOrder();
		break;
	default:
		cout << "Invaild choice! \n";
		break;
	}
}

