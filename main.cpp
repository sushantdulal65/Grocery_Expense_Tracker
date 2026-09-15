// I have been confused by using Grocery.cpp, so i will now have three files, header file,
// implementaion file, and source file
// i am unsure if the terms i have used are correct or not

#include <iostream>
#include <string>
#include <fstream>
#include "Grocery.h"

int main()
{

    int choice; // A Variable that asks user to choose between 4 choices in the program

    // Simply congratulating me for taking step into crating a project
    cout << "\nHey sushant!! Congratulations for working on this project" << endl;

    // Welcome Screen
    cout << "Welcome to Grocery Expense Tracker.\n"
         << endl;

    // Choices Display for User
    cout << "--------------------Choices-----------------------------------" << endl;
    cout << "1. Grocery Entry" << endl;
    cout << "2. Grocery Display" << endl;
    cout << "3. Edit Grocery" << endl;
    cout << "4. Exit the Program" << endl
         << endl;

    // Ask User for choice between 1 and 4
    cout << endl
         << "Choose a number between 1 and 4: ";
    cin >> choice;

    // if User chooses 4, terminate
    if (choice!=1 && choice!=2 && choice!=3)
    {
        cout << "Program closed.";
        return 0;
    }

    // initialization of array of grocery objects
    Grocery g[100];

    // initialization of file stream
    fstream file;

    int i; // Array index

    // an index to denote the maximum receipt number either from file or user input
    // used to indicate a stop position while displaying from index 0 until max_index
    int max_index = 0;

    // OPENING AN EXISTING FILE TO GET THE RECORD FROM THE PREVIOUS INPUTS
    file.open("Grocery_Record.txt", ios::in);

    // Checking if file opens or not
    if (file)
    {
        int index;
        string receipt, item, amount, payer, shared; // a string that hold the individuals tokens.
        while (getline(file, receipt, '|') && getline(file, item, '|') &&
               getline(file, amount, '|') && getline(file, payer, '|') && getline(file, shared))
        {

            index = stoi(receipt);
            if (index > max_index)
                max_index = index;
            g[index].setReceiptNo(index);
            g[index].setItemName(item);
            g[index].setAmount(stoi(amount));
            g[index].setPayer(payer);
            g[index].setSharedNoOfPeople(stoi(shared));
        }
    }
    file.close();

    while (true)
    {

        if (choice == 1)
        {
            cout << "What is the receipt no: ";
            cin >> i;
            if (g[i].isEmpty())
            {
                g[i].setReceiptNo(i);
                if (i > max_index)
                    max_index = i;
                cin >> g[i];
            }
            else
            {
                cout << "The data already exists with such receipt no." << endl;
                cout << "Please use editgrocery to edit existing grocery. " << endl;
            }
        }

        else if (choice == 2)
        {
            int ch;
            cout << "Do you want to display whole list(1) or a particular receipt.(0)" << endl;
            cin >> ch;
            if (ch == 1)
            {
                for (int i = 1; i <= max_index; i++)
                {
                    if (!g[i].isEmpty())
                        g[i].displayGrocery();
                }
            }
            else
            {
                cout << "Which grocery do you want to display? Enter the receipt no.";
                cin >> i;
                g[i].displayGrocery();
            }
        }

        else if (choice == 3)
        {
            cout << "Which grocery do you want to edit? Enter the receipt no.";
            cin >> i;
            g[i].editGrocery();
        }

        else if (choice==4)
        {
            // OPENING FILE AS A OPEN MODE TO MAKE EDITS IN THE PROGRAM AFTER THE PROGRAM RUNS
            file.open("Grocery_Record.txt", ios::out);
            for (i = 1; i <= max_index; i++)
            {
                if(!g[i].isEmpty()){
                file << g[i].getReceiptNo() << "|" << g[i].getItemName() << "|" << g[i].getAmount() << "|"
                     << g[i].getPayer() << "|" << g[i].getSharedNoOfPeople() << endl;
                }
            }
            cout << "Program closed.";
            break;
        }

        cout << "--------------------Choices-----------------------------------" << endl;
        cout << "1. Grocery Entry" << endl;
        cout << "2. Grocery Display" << endl;
        cout << "3. Edit Grocery" << endl;
        cout << "4. Exit the Program" << endl
             << endl;
        cout << endl
             << "Choose a number between 1 and 4: ";
        cin >> choice;
    }
    // is there a way i could store this whole array into a file, and load the array at the beginning in a append or input mode
    file.close();
    return 0;
}