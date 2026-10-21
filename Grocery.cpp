// Author Sushant Dulal

// implementation file for Grocery class

#include <iostream>
#include <iomanip>
#include "Grocery.h"
using namespace std;

istream& operator>>(istream& strm, Grocery& obj) 
{
    cout << "What is the amount spent on the grocery? ";
    strm >> obj.amount;
    cout << "What is the item name? ";
    strm >> obj.item_name;
    cout << "Who paid for this item? ";
    strm >> obj.payer;

    int n;
    cout << "How many people will this transaction be shared with, excluding the payer? ";
    strm >> n;

    obj.shared_with.resize(n);

    // check if the user chooses 0
    if (n!=0)
        cout << "Enter the names of the people sharing this transaction, excluding the payer: ";

    for (int i = 0; i < n; i++)
        strm >> obj.shared_with[i];

    obj.date_added = chrono::system_clock::now();
    return strm;
}

void Grocery::displayGrocery() const {
    
    cout << "---------------------------------Display---------------------------------------" << endl;
    cout << "Receipt No: " << receipt_no << endl;
    cout << "Item: " << item_name << endl;
    cout << "Amount: " << amount << endl;
    cout << "Paid By: " << payer << endl;
    cout << "Shared With: ";
    for (const string& person : shared_with)
        cout << left<< setw(10) << person;
    cout << endl;

    // Convert time_point to time_t, then to readable string
    time_t t = chrono::system_clock::to_time_t(date_added);
    cout << "Date Added: " << ctime(&t) <<endl;
}

void Grocery::editGrocery() {
    bool a;
    cout << "Current item name: " << item_name << endl;
    cout << "Change item name? (0/1): ";
    cin >> a;
    if (a)
    {
        cout << "What is the item name? ";
        cin >> item_name;
    }
    cout << "Current Amount: " << amount << endl;
    cout << "Change amount? (0/1): ";
    cin >> a;
    if (a)
    {
        cout << "What is the amount? ";
        cin >> amount;
    }
    cout << "Current Payer: " << payer << endl;
    cout << "Change payer? (0/1): ";
    cin >> a;
    if (a)
    {
        cout << "Who is the payer? ";
        cin >> payer;
    }
    cout << "Currently shared with: ";
    for (const string& person : shared_with)
        cout << person << "\t";
    cout << endl << "Change the shared-with list? (0/1): ";
    cin >> a;
    if (a)
    {
        int n;
        cout << "How many people will this transaction be shared with, excluding the payer? ";
        cin >> n;
        shared_with.resize(n);
        cout << "Enter the names of the people sharing this transaction, excluding the payer: ";
        for (int i = 0; i < n; i++)
            cin >> shared_with[i];
    }
}

void Grocery::deleteGrocery() {
    receipt_no = 0;
}

// A function to check if a grocery is empty. Logic: empty grocery has receipt no. 0
bool Grocery::isEmpty() const {
    return receipt_no == 0;
}
