// Author Sushant Dulal

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Grocery.h"
using namespace std;

// Break one serialized field into its delimiter-separated values.
static vector<string> split(const string& text, char delimiter)
{
    vector<string> parts;
    string part;
    stringstream stream(text);
    while (getline(stream, part, delimiter))
        parts.push_back(part);
    return parts;
}

// Load both the current seven-field format and older six-field records.
static void loadGroceries(vector<Grocery>& groceries)
{
    ifstream file("Grocery_Record.txt");
    string line;

    while (getline(file, line))
    {
        vector<string> fields = split(line, '|');
        const bool hasSN = fields.size() == 7;
        if ((!hasSN && fields.size() != 6) || fields.empty())
            continue;

        unsigned int sn = hasSN ? static_cast<unsigned int>(stoul(fields[0]))
                                : static_cast<unsigned int>(groceries.size() + 1);
        if (sn == 0)
            continue;

        // Grow through this SN so the vector index remains SN - 1, including gaps.
        while (groceries.size() < sn)
            groceries.emplace_back();

        Grocery& grocery = groceries[sn - 1];
        const size_t offset = hasSN ? 1 : 0;
        grocery.setReceiptNo(stoi(fields[offset]));
        grocery.setItemName(fields[offset + 1]);
        grocery.setAmount(stof(fields[offset + 2]));
        grocery.setPayer(fields[offset + 3]);
        grocery.setSharedWith(split(fields[offset + 4], ','));
        grocery.setDateAdded(stoll(fields[offset + 5]));
    }
}

// Rewrite the file from memory when the user exits.
static void saveGroceries(const vector<Grocery>& groceries)
{
    ofstream file("Grocery_Record.txt", ios::trunc);
    for (const Grocery& grocery : groceries)
    {
        // Keep deleted rows so serial numbers remain stable across restarts.
        string combinedNames;
        for (const string& person : grocery.getSharedWith())
        {
            if (!combinedNames.empty())
                combinedNames += ',';
            combinedNames += person;
        }

        file << grocery.getSN() << '|' << grocery.getReceiptNo() << '|'
             << grocery.getItemName() << '|' << grocery.getAmount() << '|'
             << grocery.getPayer() << '|' << combinedNames << '|'
             << chrono::system_clock::to_time_t(grocery.getDateAdded()) << '\n';
    }
}

int main()
{
    // Only create Grocery objects as records are loaded or added.
    vector<Grocery> groceries;
    loadGroceries(groceries);

    while (true)
    {
        int choice;
        cout << "Welcome to Grocery Expense Tracker.\n\n"
             << "--------------------Choices-----------------------------------\n"
             << "1. Grocery Entry\n"
             << "2. Grocery Display\n"
             << "3. Edit Grocery\n"
             << "4. Delete Grocery\n"
             << "5. Exit the Program\n\n"
             << "Choose a number between 1 and 5: ";
        if (!(cin >> choice))
            return 1;

        if (choice == 1)
        {
            groceries.emplace_back();
            Grocery& grocery = groceries.back();
            cout << "Serial number assigned: " << grocery.getSN() << endl;
            cout << "What is the receipt no: ";
            int receipt;
            cin >> receipt;
            grocery.setReceiptNo(receipt);
            cin >> grocery;
        }
        else if (choice == 2)
        {
            int displayAll;
            cout << "Display whole list (1) or a particular serial number (0)? ";
            cin >> displayAll;
            if (displayAll)
            {
                for (const Grocery& grocery : groceries)
                    if (!grocery.isEmpty())
                        grocery.displayGrocery();
            }
            else
            {
                unsigned int sn;
                cout << "Which serial number do you want to display? ";
                cin >> sn;
                if (sn > 0 && sn <= groceries.size() && !groceries[sn - 1].isEmpty())
                    groceries[sn - 1].displayGrocery();
                else
                    cout << "Grocery doesn't exist.\n";
            }
        }
        else if (choice == 3)
        {
            unsigned int sn;
            cout << "Which serial number do you want to edit? ";
            cin >> sn;
            if (sn > 0 && sn <= groceries.size() && !groceries[sn - 1].isEmpty())
                groceries[sn - 1].editGrocery();
            else
                cout << "Grocery doesn't exist.\n";
        }
        else if (choice == 4)
        {
            int deleteAll;
            cout << "Delete whole list (1) or a particular serial number (0)? ";
            cin >> deleteAll;
            if (deleteAll)
            {
                for (Grocery& grocery : groceries)
                    if (!grocery.isEmpty())
                        grocery.deleteGrocery();
            }
            else
            {
                unsigned int sn;
                cout << "Which serial number do you want to delete? ";
                cin >> sn;
                if (sn > 0 && sn <= groceries.size() && !groceries[sn - 1].isEmpty())
                {
                    groceries[sn - 1].deleteGrocery();
                    cout << "Grocery deleted successfully.\n";
                }
                else
                    cout << "Grocery doesn't exist.\n";
            }
        }
        else if (choice == 5)
        {
            saveGroceries(groceries);
            cout << "Program closed.";
            return 0;
        }
        else
            cout << "Choose a number between 1 and 5.\n";
    }
}
