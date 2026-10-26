#include <iostream>
#include <iomanip>
#include <limits>
#include "Grocery.h"
using namespace std;

// Read an expense from the selected input stream and timestamp it on entry.
istream& operator>>(istream& strm, Grocery& obj)
{
    cout << "What is the amount spent on the grocery? ";
    strm >> obj.amount;
    cout << "What is the item name? ";
    strm.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(strm, obj.item_name);
    cout << "Who paid for this item? ";
    strm >> obj.payer;

    int n;
    cout << "How many people will this transaction be shared with, excluding the payer? ";
    if (!(strm >> n) || n < 0)
    {
        strm.setstate(ios::failbit);
        return strm;
    }

    obj.shared_with.resize(n);

    if (n > 0)
        cout << "Enter the names of the people sharing this transaction, excluding the payer: ";

    for (int i = 0; i < n; i++)
        strm >> obj.shared_with[i];

    obj.date_added = chrono::system_clock::now();
    return strm;
}

void Grocery::displayGrocery() const {
    cout << "---------------------------------Display---------------------------------------" << endl;
    cout << "SN: " << sn << endl;
    cout << "Receipt No: " << receipt_no << endl;
    cout << "Item: " << item_name << endl;
    cout << "Amount: " << amount << endl;
    cout << "Paid By: " << payer << endl;
    cout << "Shared With: ";
    for (const string& person : shared_with)
        cout << left<< setw(10) << person;
    cout << endl;

    // Convert the stored clock value to a readable local date and time.
    time_t t = chrono::system_clock::to_time_t(date_added);
    cout << "Date Added: " << ctime(&t) << endl;
}

// Prompt for changes to individual fields, leaving SN and date_added unchanged.
void Grocery::editGrocery() {
    bool a;
    cout << "Current item name: " << item_name << endl;
    cout << "Change item name? (0/1): ";
    cin >> a;
    if (a)
    {
        cout << "What is the item name? ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, item_name);
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

// Mark the record as deleted; its vector slot and SN remain reserved.
void Grocery::deleteGrocery() {
    receipt_no = 0;
}

// Receipt number zero marks an unused or deleted slot.
bool Grocery::isEmpty() const {
    return receipt_no == 0;
}
