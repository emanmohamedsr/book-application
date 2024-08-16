#include "Book.h"

Book::Book() :BookType(" "), m_bookName(" "), m_bookID(0), m_pages(0), m_price(0.0)
{
}
Book::~Book()
{
}
//print book in customers class
void Book::printBook()
{
    cout << "Book Information...\n"
        << "Type : " << BookType
        << "\nID : " << m_bookID
        << "\nName : " << m_bookName
        << "\npages : " << m_pages
        << "\nPrice : " << m_price << endl;

}
//add book takes type as argument (to add onther types) 
void Book::ADDABOOK(string type)
{
    BookType = type;
    cout << "Enter Book information ... \n"
        << "ID : "; cin >> m_bookID;
    cout << "Name : "; cin >> m_bookName;
    cout << "Pages : "; cin >> m_pages;
    cout << "Price : "; cin >> m_price;
}
//search for book
int Book::getID()const
{
    return m_bookID;
}
//search by type -> get count of types
string Book::getType()const
{
    return BookType;
}
//get price & total price   
double Book::getPrice()const
{
    return m_price;
}

//*fun.get (id , type , price) to fill orders array
