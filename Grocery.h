#ifndef GROCERY_H
#define GROCERY_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;


class Grocery
{
private:
    long int amount;
    // stores the amount of particular item, for eg: 3 dollars, i will only enter 3 for this case

    string item_name;
    // stores the item that was bought, for eg: tomato

    string payer;
    // stores the first name of person who paid for the grocery, for eg: sushant

    vector<string> shared_with;
    // stores the vector of names of people who share this item, for eg: roshan, aayush, but it doesn't include the payer

    // picture i will figure out something later.

    int receipt_no;
    // stores the information about which number receipt is it so that it becomes easier to search for the receipt
    // Note: receipt_no acts like a primary key for this project, it can't be duplicate, and its should be a positive non-zero number
    
    chrono::system_clock::time_point date_added;
    // stores the info about the time and date at which a particular grocery was first added. 

public:
    // Constructor
    Grocery(long int amt = 0, string item = "", string paidby = "", vector<string> shared_w, int receipt = 0)
    {
        amount = amt;
        item_name = item;
        payer = paidby;
        shared_with = shared_w;
        receipt_no = receipt;
    }
    // mutators or setters
    void setAmount(long int amt)
    {
        amount = amt;
    }
    void setItemName(string item)
    {
        item_name = item;
    }
    void setPayer(string paidby)
    {
        payer = paidby;
    }

    void setSharedWith(vector<string> sharedw)
    {
        shared_with = sharedw;
    }
    
    void setReceiptNo(int no)
    {
        receipt_no = no;
    }
    void setDateAdded(time_t t)
    {
        date_added = chrono::system_clock::from_time_t(t);
    }

    // accessors or getters
    long int getAmount() const
    {
        return amount;
    }
    string getItemName() const
    {
        return item_name;
    }
    string getPayer() const
    {
        return payer;
    }

    int getSharedNoOfPeople() const
    {
        return shared_no_of_people;
    }
    int getReceiptNo() const
    {
        return receipt_no;
    }
    chrono::system_clock::time_point getDateAdded() const{
        return date_added;
    }
    void displayGrocery() const;
    
    void editGrocery();

    // a function that allows the user to delete a particular grocery or
    // entire grocery based on the requirement
    void deleteGrocery(); 

    bool isEmpty() const;
    friend istream &operator>>(istream &, Grocery &); // overloading the >> operator

   
};

#endif