#include "BookItem.h"

BookItem::BookItem() :pay(0), bookORid(0)
{}
BookItem::~BookItem()
{}

double BookItem::getpay()
{
    return pay;
}
//search and restore books 
int BookItem::getID()
{
    return bookORid;
}
//fill order array
void BookItem::addOrder(string t, int id, double p)
{
    bookORty = t;
    bookORid = id;
    pay = p;
}
void BookItem::printOrder()
{
    cout << "Book Type : " << bookORty << "  |Book ID : " << bookORid << "  |Price : " << pay << endl;
}





