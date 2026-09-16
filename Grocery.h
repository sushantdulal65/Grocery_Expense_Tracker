#ifndef GROCERY_H
#define GROCERY_H

#include <iostream>
#include <string>
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

    int shared_no_of_people;
    // stores the number of people who share this item, for eg: 2

    // picture i will figure out something later.

    int receipt_no;
    // stores the information about which number receipt is it so that it becomes easier to search for the receipt

public:
    // Constructor
    Grocery(long int amt = 0, string item = "", string paidby = "", int sharedby = 0, int receipt = 0)
    {
        amount = amt;
        item_name = item;
        payer = paidby;
        shared_no_of_people = sharedby;
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

    void setSharedNoOfPeople(int sharedby)
    {
        shared_no_of_people = sharedby;
    }
    
    void setReceiptNo(int no)
    {
        receipt_no = no;
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
    void displayGrocery() const;
    void editGrocery();

    // a function that allows the user to delete a particular grocery or
    // entire grocery based on the requirement
    void deleteGrocery(); 
    bool isEmpty() const;
    friend istream &operator>>(istream &, Grocery &); // overloading the >> operator

   
};

#endif