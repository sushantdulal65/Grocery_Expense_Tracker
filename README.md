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