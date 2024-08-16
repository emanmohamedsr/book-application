#include "customer.h"

customer::customer() :customerNumber(0), age(0), totalPay(0)
{
    Size = 5;

    phoneCount = 0;
    phone = new phoneNumber[Size];

    emailCount = 0;
    email = new Email[Size];

    orderSize = 50;
    orderCount = 0;
    orderList = new BookItem[orderSize];
}
customer::~customer()
{
    delete[] orderList;
    delete[] email;
    delete[] phone;
}


void customer::addorddre(string type, int id, double price)
{
    orderList[orderCount++].addOrder(type, id, price);
    totalPay += price;
}
void customer::printorddre()
{
    for (int i = 0; i < orderCount; i++)
    {
        cout << "(" << 1 + i << ") ";
        orderList[i].printOrder();
    }
}


void customer::addAAAcustomer()
{
    cout << "Your orders have been recorded successfully \n";
    cout << "Enter Customer Information ... \n"
        << "Number(ID) : ";
    cin >> customerNumber;
    cout << "Name : ";
    cin >> name;
    do
    {
        cout << "Age : ";
        cin >> age;
    } while (age < 0 || age>200);
    cout << "Address : ";
    cin >> address;
    cout << "Date of order : ";
    cin >> dateOfOrder;
    int n;
    do {
        cout << "o_o How many phone numbers -> allowed (0:5) number : ";
        cin >> n;
        if (n <= 5 && n >= 0) {
            for (int i = 1; i <= n; ++i)
            {
                phone[phoneCount++].addNumber();
            }
        }
    } while (!(n <= 5 && n >= 0));
    do
    {
        cout << "o_o How many e-mails -> allowed (0:5) account : ";
        cin >> n;
        if (n <= 5 && n >= 0) {
            for (int i = 1; i <= n; ++i)
            {
                email[emailCount++].addEmail();
            }
        }
    } while (!(n <= 5 && n >= 0));
    cout << endl;
}
void customer::printAAAcustomer()
{
    cout << " ... The Customer ... "
        << "\nNumber  : " << customerNumber
        << "\nName    : " << name
        << "\nAge     : " << age
        << "\naddress : " << address
        << "\nPhone Numbers..." << endl;
    if (phoneCount > 0) {
        for (int i = 0; i < phoneCount; i++)
        {
            cout << "[" << i + 1 << "] ";
            phone[i].printNumber();
            cout << endl;
        }
    }
    else
        cout << "Empty" << endl;
    cout << "e-mails........." << endl;
    if (emailCount > 0) {
        for (int i = 0; i < emailCount; i++)
        {
            cout << "[" << i + 1 << "] ";
            email[i].printEmail();
            cout << endl;
        }
    }
    else
        cout << "Empty" << endl;
    cout << "Order date : " << dateOfOrder << endl;
}


//return total order count to make for loop of orders
int customer::ordercount()
{
    return orderCount;
}
//give values of for loop 0.1.2.3...untill count to get id of order item
int customer::returnOrderid(int count)
{
    return orderList[count].getID();
}



int customer::getCustomerNumber()
{
    return customerNumber;
}
double customer::getTotalPay()
{
    return totalPay;
}
