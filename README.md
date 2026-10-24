# Grocery Expense Tracker

Date: 08/31/2026

I hope I do not quit this project soon!!!!!!
I will come back tommorow at the same time night after work.

Let's start with basic elements of my project.

First of all, lets identify my problem.

I have not been able to eat healthy diet because of lack of planning of grocery and planning with my rommate. My money involved in grocery is unknown until the end of the month. I want sth that keeps record of money spent per person on grocery, calculates if every nutrients in my daily diet or not, and recommends and plans my walmart visit based on the nutrient intake i plan to take. It also in the later run will help me calculate my calorie intake based on my nepali food, keep track of my water and show a proper chart at the end of the week, and reminds me if the chart is deviated. Later, I will also add my workout settings onto this app.

So, components required:

1. diet planner
2. budget
3. time
4. calorie intake
5. water intake

So, this is my big picture, so without wasting my time, i will begin my project on smaller chunk

## Chunk 1: Grocery Expense Add

First of all, I need to add my expense on grocery into the computer. That will be the input and the computer will store that data into its memory.
So, what are the data that needs to be stored:

- What was the item that was bought?
- What is the amount?
- Who paid the amount?
- How many people share that amount?
- Picture of the receipt.

For this chunk lets create a class named Grocery.

```cpp
class Grocery{
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

    public:
        // Constructor
        Grocery(long int amt = 0, string item="",string paidby="",int sharedby=0)
        {
            amount = amt;
            item_name = item;
            payer = paidby;
            shared_no_of_people = sharedby;
        }
        //mutators or setters
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


}
```

now i have developed a basic running program.
What are the problems?
One will go one over a time and the first one i see is the data is not being stored,
so what shall i use, for this checkup time lets create an array of 10 objects.
do i need to recall that part let me try writing the code without looking anthing

```cpp
class Grocery a[10];
a[0].setname();

```

i feel this is the way lets try in our original project.

Ok i think something is running in the project but my program only stores the grocery while it is running, so i need to add file handling. I need to revesit that concept first of all.

I faced a problem which was that while editing the grocery i could modify it in memory but editing in file wasn't possible, so what i decide to do is every time i am about to close a program i rewrite it in file at the end of program. Also, I will open the file only once to load contents in memory.

Also, I will upload FileTest.cpp so that I do not have a new file over there which makes me overthink.

``` cpp FileTest.cpp
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
```

Now, my program runs somewhat, I will try to see what I need to include in the program.

The problem I see here is that when I try to display record, it asks for receipt no. It is ok to ask for receipt number but sometimes I may like to display the whole record, so i will ask if you want to display entire record or a particular record. Let's proceed on it.

I found a way to display whole record.
But, I have a problem. If i enter a receipt no directly 8, my display grocery will run from 1 until the max index which is 8. So, i will create a function that checks if grocery is_empty. I required to check the emptiness once, which will also be done by this function as well.

Ok, now I guess its time to add a feature that allows the user to delete grocery as well.

Problems I see now:

1. If the grocery is not present at all, it allows me to edit grocery, which should be disallowed. Same case with display grocery as well.
2. Lets see if we get something if i miss say amount i mean if i do not enter amount will it be stored in the file or not

I guess I solved both the problems because now i check before running editgrocery or displaygrocery.
Also, i cannot leave empty while giving input bro so number 2 is also fine.

Now, I would like to add calendar features to my Grocery project.
I want to make my grocery project track when the user entered a particular grocery. And, also later I can add features that allow me to handle or numerical compute the data. I guess I need to change my grocery expense tracker to food grocery expense tracker cause when i read later as well.

So, I am working on adding calendar feature to my grocery and eventually show the portion to each individual about how much they owe like splitwise.

How to add system's date and time in display in c++. Answer from google.

```c++
#include <iostream>
#include <chrono>

int main() {
    // Get the current system zone time
    auto now = std::chrono::system_clock::now();

    std::cout <<now <<endl;              
    return 0;
}
```

08-21:
OK, Now I see I am working on figuring out how to time grocery entry and figure out a way to manipulate the entry on the basis of. Be clear:

Example: I can sort out the grocery entry in August. Let this be my way. No, nothing about sorting for now. So what is the next step. Stop this project for now and think of a different project without beautifying this project. You need to add features of calorie and lot into it.

Forget about everything for now and lets jump into another category:

## Chunk 2: Splitwise

I already have a lot of data. I have the grocery information. Now, what I want to do is I want to use to payer and number of payer information to calculate how much the payer is owed. For example: $5 for Potato paid by Sushant and split into 3 people makes Sushant to be owed (3-1)*5/3
(shared_no_of_people-1)*(amount)/(shared_no_of_people) ok this is the formula
how do i use variable_name
I guess I need a new file for this for individual person and also may be a different class
Say it Person inherited(need to determine if hasa or isa or any other relationship) from the Grocery class.
alright now there should be Person object that has attributes owes, is owed. OK.

Ok forget everything now, i plan to add a member variable shared_with which is a vector of strings and i choose to drop shared_no_of_people because i need to update it everytime i add a person which can easily be calculated from shared_with.size().

Checking my vector knowledge.

Ok, Now I am facing a problem with file handling in order to store the members of shared_with. The getline(file, var_name, 'delimiter|') helps to only get a string "" which is a vector of shared names. Now I have to figure out to split that string object using the delimiter , and store it.
As I had done in the string exercise, I recall using .find() and substr() in order to deal with this issue.
There was a new data type here again size_t which is a integer type commonly used for things like string length, array size. string::npos is returned by find() if a string is not found here. In this case, this data type comes handy.
I will do this program in the concepts_I_revisited portion.

9/29/2026

I am back after a long time. Let me figure out where did I left off, because I have no idea where I left off.

Now, I have successfully deployed the shared_with list onto my app.

NEXT TASK: FIGURE OUT A WAY TO MAKE OWES AND IS_OWED WORKING

Wait a minute on that task. Something is wrong.

For some reason, there was gapping problem in shared_with display which I resolved using include iomanip

Another big problem, while I run displaygrocery, it adds the shared_with list with the list of people in previous receipts in every run. If I don't run displaygrocery, there is no such problem.

Now I guess I need to change the approach of the problem. I find it difficult to see if the grocery exists or not without even going throughout the list. So, I plan to replace the receipt no with symbol number while also keeping the receipt no. So that symbol no will hold the new groceries in ascending order unless explicitly sorted maybe later on. I will also keep receipt no which would be used for searching from user interface. Symbol number only exists for programmer interface.

What are the works I need to do?
Change file writing technique, first list of the table should be S.N.

