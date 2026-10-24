// Author Sushant Dulal

// source file for Grocery class

#include <iostream>
#include <string>
#include <fstream>
#include "Grocery.h"
using namespace std;

//******************************************************************************
//* a function that will separate tokens from a string into a vector of string *
//* s is the big string, delimiter is the character that separates the tokens, *
//* tokens is the vector that will store individual tokens separately,         *
//* for example: "Ram,Hari,Sita" --This whole string is s,',' is delimiter,and *
//* Ram  Hari and Sita are the tokens.                                         *
//******************************************************************************

void split(const string& s, char delim, vector<string>& tokens);

int main()
{

    int choice;        // A Variable that asks user to choose between 4 choices in the program     

    // Welcome Screen
    cout << "Welcome to Grocery Expense Tracker.\n\n";

    // Choices Display for User
    cout << "--------------------Choices-----------------------------------" << endl;
    cout << "1. Grocery Entry" << endl;
    cout << "2. Grocery Display" << endl;
    cout << "3. Edit Grocery" << endl;
    cout << "4. Delete Grocery" << endl;
    cout << "5. Exit the Program" << endl << endl;

    // Ask User for choice between 1 and 5
    cout << "\nChoose a number between 1 and 5: ";
    cin >> choice;

    // if user chooses 5 or any other number, terminate
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
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
        vector<string> v; //a vector that will hold the members of shared with
        string receipt, item, amount, payer, shared,time; // a string that hold the individuals tokens.
        
        while (getline(file, receipt, '|') && getline(file, item, '|') &&
               getline(file, amount, '|') && getline(file, payer, '|') && 
               getline(file, shared, '|') && getline(file,time))
        {
            index = stoi(receipt);
            if (index > max_index)
                max_index = index;
            
            split(shared,',',v);
            g[index].setReceiptNo(index);
            g[index].setItemName(item);
            g[index].setAmount(stof(amount));
            g[index].setPayer(payer);
            g[index].setSharedWith(v);
            g[index].setDateAdded(stoll(time));
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
                cout << "Please use edit grocery to edit existing grocery. " << endl<< endl;
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
                if (!g[i].isEmpty())
                    g[i].displayGrocery();
                else
                    cout << "Grocery doesn't exist. Back to choices again." << endl;
            }
        }

        else if (choice == 3)
        {
            cout << "Which grocery do you want to edit? Enter the receipt no.";
            cin >> i;
            if (!g[i].isEmpty())
                g[i].editGrocery();
            else
                cout << "Grocery doesn't exist. Back to choices again." << endl;
        }

        else if (choice == 4)
        {
            int ch;
            cout << "Do you want to delete whole list(1) or a particular grocery.(0)" << endl;
            cin >> ch;
            if (ch == 1)
            {
                for (int i = 1; i <= max_index; i++)
                {
                    if (!g[i].isEmpty())
                        g[i].deleteGrocery();
                }
            }
            else
            {
                cout << "Which grocery do you want to delete? Enter the receipt no.";
                cin >> i;
                if (!g[i].isEmpty())
                {
                    g[i].deleteGrocery();
                    cout << "Grocery deleted successfully." << endl;
                }
                else
                    cout << "Grocery doesn't exist. Back to choices again." << endl;
            }
        }
        else if (choice == 5)
        {
            // OPENING FILE AS A OPEN MODE TO MAKE EDITS IN THE PROGRAM AFTER THE PROGRAM RUNS
            file.open("Grocery_Record.txt", ios::out);
            for (i = 1; i <= max_index; i++)
            {
                if (!g[i].isEmpty())
                {
                    string combined_names = "";
                    //converting those vectors to string split with comma
                    for(string s: g[i].getSharedWith())
                    {   
                        if(combined_names=="")
                            {combined_names+=s;
                            continue;}
                        combined_names = combined_names + ","+s;
                    }
                    file << g[i].getReceiptNo() << "|" << g[i].getItemName() << "|" << g[i].getAmount() << "|"
                         << g[i].getPayer() << "|" << combined_names <<"|" << chrono::system_clock::to_time_t(g[i].getDateAdded()) << endl;
                }
            }
            cout << "Program closed.";
            break;
        }

        cout << "--------------------Choices-----------------------------------" << endl;
        cout << "1. Grocery Entry" << endl;
        cout << "2. Grocery Display" << endl;
        cout << "3. Edit Grocery" << endl;
        cout << "4. Delete Grocery" << endl;
        cout << "5. Exit the Program" << endl
             << endl;
        cout << endl
             << "Choose a number between 1 and 5: ";
        cin >> choice;
    }
    // is there a way i could store this whole array into a file, and load the array at the beginning in a append or input mode
    file.close();
    return 0;
}

void split(const string& s, char delim, vector<string>& tokens)
{
    int tokenStart = 0; // Starting position of the next token

    //Find the first occurence of the delimiter.
    int delimPosition = s.find(delim);

    // While we haven't run out of delimiters...
    while(delimPosition != string::npos)
    {
        //Extract the token.
        string tok = s.substr(tokenStart, delimPosition - tokenStart);

        //Push the token onto the tokens vector.
        tokens.push_back(tok);

        //Move delimPosition to the next character position.
        delimPosition++;

        //Move tokenStart to delmiPosition.
        tokenStart = delimPosition;

        //Find the next occurence of the delimiter.
        delimPosition = s.find(delim,delimPosition);


        //if no more delimiters, extract the last token.
        if(delimPosition == string::npos)
        {
            //Extract the token.
            string tok = s.substr(tokenStart, delimPosition - tokenStart);

            //Push the token onto the vector.
            tokens.push_back(tok);
        }

    }


}