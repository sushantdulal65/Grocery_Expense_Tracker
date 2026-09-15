// Reading the Grocery_Record.txt so that i can convert the line of the file into a grocery object

#include <iostream>
#include <fstream>
#include <string>
#include "Grocery.h"
using namespace std;

int main()
{
    Grocery g[100];
    fstream file;
    file.open("Grocery_Record.txt", ios::in);

    if (file)
    {
        int index;
        string receipt, item, amount, payer, shared; // a string that hold the individuals tokens.
        while (getline(file, receipt, '|') && getline(file, item, '|') &&
               getline(file, amount, '|') && getline(file, payer, '|') && getline(file, shared))
        {

            index = stoi(receipt);
            g[index].setReceiptNo(index);
            g[index].setItemName(item);
            g[index].setAmount(stoi(amount));
            g[index].setPayer(payer);
            g[index].setSharedNoOfPeople(stoi(shared));
        }
        cout << "Which grocery should i display? Enter receipt no: ";
        cin >> index;
        g[index].displayGrocery();
    }
    else
        cout << "ERROR: opening file";

    file.close();
    return 0;
}