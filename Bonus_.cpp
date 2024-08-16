// Bonus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>///system
#include <windows.h>///sleep,color
#include <iostream>

using namespace std;

///color
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);


#include "System.h"



struct MyStruct
{
    System c;
    void print(string text, bool newLine = true)
    {
        cout << text << (newLine ? "\n" : " ");
    }
    void separator(int color)
    {
        int x = 80;
        SetConsoleTextAttribute(cout_handle, color);
        for (auto i = 0; i < x; ++i)
        {
            cout << "_";
        }
        SetConsoleTextAttribute(cout_handle, 15);
        cout << endl;
    }
    void Back(int x = 3)
    {
        for (auto i = 0; i < x; ++i)
        {
            cout << ".";
            Sleep(400);
        }
    }
    /// main
    void Books_system()
    {
        system("cls");
        SetConsoleTextAttribute(cout_handle, 13);
        print("\t\tWelcome to Our Library system");
        print("\t\t_____________________________\n");
        SetConsoleTextAttribute(cout_handle, 15);
        print("How can we help you \x03 ....");
        print("1) Books Modification System ");
        print("2) Information Depatrment ");
        print("3) Order Processing System ");
        print("0) close ");
        print("Your choice! ", false);
    }
    /// Modification
    void Modification()
    {
        int ch;
        while (true)
        {
            system("cls");
            SetConsoleTextAttribute(cout_handle, 9);
            print("\t\tWelcome in \'Books Modification System\' ");
            print("\t\t______________________________________\n");
            SetConsoleTextAttribute(cout_handle, 15);
            print("-> Enter a service ... ");
            print("1) Add a Book ");
            print("2) Search for a Book ");
            print("3) Delete a Book ");
            print("4) Edit a Book ");
            print("0) Back to Main page ");
            print("Your choice!  ", false);

            cin >> ch;
            separator(9);
            switch (ch)
            {
            case 1:
                //Add 
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tAdd a Book");
                print("\t\t__________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.addBook();

                separator(9);
                print("\t\t<- Back ", false);
                Back();
                break;
            case 2:
                //Search
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tSearch for a Book");
                print("\t\t________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.searchBook();

                separator(9);
                system("pause");
                break;
            case 3:
                //Delete
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tDelete a Book");
                print("\t\t_____________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.deleteBook();

                separator(9);
                print("\t\t<- Back ", false);
                Back();
                break;
            case 4:
                //Edit
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tEdit a Book");
                print("\t\t__________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.editBook();

                separator(9);
                print("\t\t<- Back ", false);
                Back();
                break;
            case 0:
                //out
                print("\t\t\tBack to Main page ", false);
                Back();
                return;
            default:
                //invalid
                print("\t\t\tInvalid choice, Try again ", false);
                Back();
                break;
            }
        }
    }
    ///information
    void Information()
    {
        int ch;
        while (true)
        {
            system("cls");
            SetConsoleTextAttribute(cout_handle, 14);
            print("\t\tWelcome in \'Information Depatrment\' ");
            print("\t\t______________________________________\n");
            SetConsoleTextAttribute(cout_handle, 15);
            print("-> Enter a service ... ");
            print("1) Print Books (All, one & Category) ");
            print("2) Categorys with shortage ");
            print("3) Inquire about Quantities");
            print("0) Back to Main page ");
            print("Your choice!  ", false);

            cin >> ch;
            separator(14);
            switch (ch)
            {
            case 1:
                //print
                system("cls");
                SetConsoleTextAttribute(cout_handle, 14);
                print("\t\tPrint Books (All, one & Category) ");
                print("\t\t________________________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.printBooks();

                separator(14);
                system("pause");
                break;
            case 2:
                //Shortage
                system("cls");
                SetConsoleTextAttribute(cout_handle, 14);
                print("\t\tCategorys with shortage");
                print("\t\t_______________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.shortage();

                separator(14);
                system("pause");
                break;
            case 3:
                //quantities
                system("cls");
                SetConsoleTextAttribute(cout_handle, 14);
                print("\t\tInquire about Quantities");
                print("\t\t________________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.getinfo();

                separator(14);
                system("pause");
                break;
            case 0:
                //out
                print("\t\t\tBack to Main page ", false);
                Back();
                return;
            default:
                //invalid
                print("\t\t\tInvalid choice, Try again ", false);
                Back();
                break;
            }
        }
    }
    /// sales
    void Sales()
    {
        int ch;
        while (true)
        {
            system("cls");
            SetConsoleTextAttribute(cout_handle, 12);
            print("\t\tWelcome in \'Order Processing System\' ");
            print("\t\t____________________________________\n");
            SetConsoleTextAttribute(cout_handle, 15);
            print("-> Enter a service ... ");
            print("1) Make an order");
            print("2) Search for a customer ");
            print("3) Delete a customer ");
            print("4) Print a Customer ");
            print("5) Reporting ");
            print("0) Back to Main page ");
            print("Your choice!  ", false);

            cin >> ch;
            separator(12);
            switch (ch)
            {
            case 1:
                //order
                system("cls");
                SetConsoleTextAttribute(cout_handle, 12);
                print("\t\tMake an order");
                print("\t\t_____________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.makeOrder();

                separator(12);
                print("\t\t<- Back ", false);
                Back(4);
                break;
            case 2:
                //search
                system("cls");
                SetConsoleTextAttribute(cout_handle, 12);
                print("\t\tSearch for a customer");
                print("\t\t_____________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.searchCustomer();

                separator(12);
                print("\t\t<- Back ", false);
                Back(4);
                break;
            case 3:
                //delete
                system("cls");
                SetConsoleTextAttribute(cout_handle, 12);
                print("\t\tDelete a customer");
                print("\t\t_________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.deleteOrCancel();

                separator(12);
                print("\t\t<- Back ", false);
                Back(4);
                break;
            case 4:
                //print
                system("cls");
                SetConsoleTextAttribute(cout_handle, 12);
                print("\t\tPrint a Customer");
                print("\t\t________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.printCustomer();

                separator(12);
                system("pause");
                break;
            case 5:
                //report
                system("cls");
                SetConsoleTextAttribute(cout_handle, 12);
                print("\t\tReporting");
                print("\t\t__________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.printAllCustomer();

                separator(12);
                system("pause");
                break;
            case 0:
                //out
                print("\t\t\tBack to Main page ", false);
                Back();
                return;
            default:
                //invalid
                print("\t\t\tInvalid choice, Try again ", false);
                Back();
                break;
            }
        }
    }
}E;



int main()
{
    int choice;
    while (true)
    {
        E.Books_system();
        cin >> choice;
        E.separator(13);
        switch (choice)
        {
        case 1:
            //Modification 
            E.Modification();
            break;
        case 2:
            //info
            E.Information();
            break;
        case 3:
            //sales
            E.Sales();
            break;
        case 0:
            //out
            E.print("\t\t\tThanks \x03");
            return 0;
            break;
        default:
            E.print("\t   Invalid Choice, Try again ", false);
            E.Back();
            break;
        }

    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
