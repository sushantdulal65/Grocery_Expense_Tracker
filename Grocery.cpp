#include <string>
#include <iostream>
#include <fstream>
#include "Grocery.h"
using namespace std;


//overloading the >> operator
        istream& operator>>(istream& strm,Grocery &obj)
        {
            cout << "What is the amout spent on the grocery? ";
            strm >> obj.amount;
            cout << "What is the item name? ";
            strm >> obj.item_name;
            cout << "Who paid for this item? ";
            strm >> obj.payer;
            cout << "How many number of people is this expense shared with? ";
            strm >> obj.shared_no_of_people;
            return strm;
        }

 void Grocery::displayGrocery() const
    {
        cout << "---------------------------------Display---------------------------------------" << endl;
        cout << "Receipt No: "<< receipt_no<< endl;
        cout << "Item: " << item_name << endl;
        cout << "Amont: " << amount << endl;
        cout << "Paid By: " << payer << endl;
        cout << "Shared By: " << shared_no_of_people << " people" << endl;
    }

    void Grocery::editGrocery() 
    {
        bool a;
        cout << "Current Item name: "<< item_name << endl;
        cout << "Do you want to change item name(0/1): "<< endl;
        cin >> a;
        if (a) 
         {   cout << "What is the item name? ";
             cin >> item_name;
         }
        cout << "Current Amount: "<< amount << endl;
        cout << "Do you want to change amount(0/1): "<< endl;
        cin >> a;
        if (a) 
         {   cout << "What is the amount? ";
             cin >> amount;
         }
        cout << "Current Payer: "<< payer << endl;
        cout << "Do you want to change payer(0/1): "<< endl;
        cin >> a;
        if (a) 
         {   cout << "Who is the payer? ";
             cin >> payer;
         }
        cout << "Current number of people the expense is shared: "<< shared_no_of_people << endl;
        cout << "Do you want to change this value(0/1): "<< endl;
        cin >> a;
        if (a) 
         {   cout << "How many number of people is this expense shared with?";
             cin >> shared_no_of_people;
         }  
              
    }