# Grocery Expense Tracker

A small command-line C++ program for recording shared grocery expenses. Each entry receives an automatically assigned serial number (SN), which is used to find, edit, and delete it. A receipt number is stored separately as information about the purchase.

## Features

- Add grocery expenses with an item, amount, payer, receipt number, and people sharing the expense.
- Display all active entries or one entry by SN.
- Edit or delete an entry by SN.
- Save records to `Grocery_Record.txt` when exiting and reload them at the next start.
- Grow the in-memory list as entries are added; there is no fixed 100-entry limit.

## Requirements

- A C++ compiler with C++17 support or newer (for example, GCC or MinGW-w64).

## Build and run

From the project directory, compile both source files:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Grocery.cpp -o grocery-expense-tracker
```

On Windows with MinGW-w64:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Grocery.cpp -o Grocery_Expense_Tracker.exe
```

Run the executable from the project directory so it can find `Grocery_Record.txt`:

```sh
./grocery-expense-tracker
```

## Using the program

Choose an action from the menu. When adding an entry, the program assigns its SN and then asks for the receipt number and expense details. Use the SN shown in the display when selecting an entry to display, edit, or delete. The receipt number is not used as the vector index.

Deleting an entry marks its slot as empty. Its SN is retained so that later entries keep their original numbers.

## Data file

`Grocery_Record.txt` is the plain-text data file. It starts empty in a fresh checkout. When the program exits, each record is stored on one line in this order:

```text
SN|receipt number|item|amount|payer|shared people|date added
```

The current loader also accepts the older six-field format, which did not include an SN. Those records receive serial numbers in file order. The text format uses `|` between fields and commas between shared names, so those characters are not currently supported inside names or item text.

## Project files

- `main.cpp` — menu, vector storage, and record-file loading and saving.
- `Grocery.h` — the `Grocery` class declaration and member accessors.
- `Grocery.cpp` — grocery input, display, editing, and deletion behavior.
- `Grocery_Record.txt` — local expense data; keep personal records out of public commits.

## Current scope

This version tracks grocery entries and the people sharing each expense. Automatic balance calculations, receipt images, nutrition tracking, and meal planning are not implemented yet.
