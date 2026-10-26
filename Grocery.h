#ifndef GROCERY_H
#define GROCERY_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Represents one grocery expense. SN is assigned in creation order; receipt_no
// is separate information supplied by the user.
class Grocery {
private:
    static unsigned int& serialCounter()
    {
        static unsigned int count = 0;
        return count;
    }
    unsigned int sn;
    float amount;
    string item_name;
    string payer;
    vector<string> shared_with;
    unsigned int receipt_no;
    chrono::system_clock::time_point date_added;

public:
    // A new grocery receives the next serial number. Copies retain their SN.
    Grocery(float amt = 0.0, string item = "", string paidby = "",
            vector<string> shared_w = {}, unsigned int receipt = 0)
        : amount(amt),
          item_name(item),
          payer(paidby),
          shared_with(shared_w),
          receipt_no(receipt),
          date_added()
    {
        sn = ++serialCounter();
    }

    // Setters used when loading a record from disk or updating an entry.
    void setAmount(float amt)
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
    
    void setReceiptNo(unsigned int no)
    {
        receipt_no = no;
    }
    void setDateAdded(time_t t)
    {
        date_added = chrono::system_clock::from_time_t(t);
    }

    // Read-only accessors.
    float getAmount() const
    {
        return amount;
    }
    unsigned int getSN() const
    {
        return sn;
    }
    string getItemName() const
    {
        return item_name;
    }
    string getPayer() const
    {
        return payer;
    }

    vector<string> getSharedWith() const { return shared_with; }
    unsigned int getReceiptNo() const
    {
        return receipt_no;
    }
    chrono::system_clock::time_point getDateAdded() const {
        return date_added;
    }

    // Console operations for one grocery entry.
    void displayGrocery() const;
    void editGrocery();
    void deleteGrocery();

    // Deleted entries are retained as empty slots so later SN values do not shift.
    bool isEmpty() const;
    friend istream& operator>>(istream&, Grocery&);
};

#endif
