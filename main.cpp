// I have been confused by using Grocery.cpp, so i will now have three files, specification file, 
// implementaion file, and execution file
// i am unsure if the terms i have used are correct or not

#include <iostream>
#include <string>
#include <fstream>
#include "Grocery.h"

int main(){

    int choice; // A Variable that asks user to choose between 4 choices in the program

    cout << "\nHey sushant!! Congratulations for working on this project" << endl;
    cout << "Welcome to Grocery Expense Tracker.\n" << endl;

    cout << "--------------------Choices-----------------------------------" << endl;
    cout << "1. Grocery Entry"<< endl;
    cout << "2. Grocery Display"<<endl;
    cout << "3. Edit Grocery"<< endl;
    cout << "4. Exit the Program"<< endl<<endl;

    cout << endl <<"Choose a number between 1 and 4: ";
    cin >> choice;

    if (choice == 4)
        {
            cout << "Program closed.";
            return 0;
        }

    Grocery g[100];
    fstream file;
    int i; // ARRAY OPERATOR I FORGOT THE TERM CALLED

    // OPENING AN EXISTING FILE TO GET THE RECORD FROM THE PREVIOUS INPUTS
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
    }
    file.close();

    // OPENING FILE AS A APPEND MODE TO MAKE EDITS IN THE PROGRAM AFTER THE PROGRAM RUNS
    file.open("Grocery_Record.txt",ios::out | ios::app);

    while (true){


        if(choice==1)
        {
            cout << "What is the receipt no: ";
            cin >> i;
            if (g[i].getReceiptNo() == 0)
            {g[i].setReceiptNo(i);
            cin>> g[i];
            file << g[i].getReceiptNo() << "|"<< g[i].getItemName() << "|"<<g[i].getAmount() << "|"
            << g[i].getPayer() << "|" << g[i].getSharedNoOfPeople() << endl;
            }
            else{
                cout << "The data already exists with such receipt no." << endl;
                cout << "Please use editgrocery to edit existing grocery. "<< endl;
            }
        }


        else if(choice==2)
        {
            cout << "Which grocery do you want to display? Enter the receipt no.";
            cin >> i;
            g[i].displayGrocery();
        }


        else if(choice==3)
        {
            cout << "Which grocery do you want to edit? Enter the receipt no.";
            cin >> i;
            g[i].editGrocery();
            file << g[i].getReceiptNo() << "|"<< g[i].getItemName() << "|"<<g[i].getAmount() << "|"
            << g[i].getPayer() << "|" << g[i].getSharedNoOfPeople() << endl;
        }


        else if(choice==4)
        {
            cout << "Program closed.";
            break;
        }


        else    
        {
            cout << "Wrong choice!!! Program terminated.";
            break;
        }
    
    cout << "--------------------Choices-----------------------------------" << endl;
    cout << "1. Grocery Entry"<< endl;
    cout << "2. Grocery Display"<<endl;
    cout << "3. Edit Grocery"<< endl;
    cout << "4. Exit the Program"<< endl<<endl;
    cout << endl <<"Choose a number between 1 and 4: ";
    cin >> choice;

    }
    // is there a way i could store this whole array into a file, and load the array at the beginning in a append or input mode
    file.close();
    return 0;
}   