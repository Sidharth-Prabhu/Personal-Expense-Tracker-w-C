# Personal Expense Tracker with C

# Daily Expense Tracker

## Aim
To create a program to track daily expenses using arrays to store expense records, structures to organize categories, and files for persistent storage.

---

## Algorithm

### Step 1: Define the Structures
- Create a structure `Expense` with the following fields:
  - `id` (integer): Unique ID for the expense.
  - `date` (string): Date of the expense.
  - `category` (string): Expense category (e.g., Food, Travel, etc.).
  - `amount` (float): Amount of the expense.

### Step 2: Display Menu
- Provide the user with a menu of options:
  1. Add Expense
  2. View All Expenses
  3. Search Expenses by Category
  4. Calculate Total Expenses
  5. Exit

### Step 3: Add Expense
- Prompt the user for the expense details (ID, date, category, amount).
- Store the expense in an array and append it to a file for persistence.

### Step 4: View All Expenses
- Read and display all expense records from the file.

### Step 5: Search Expenses by Category
- Prompt the user for a category.
- Read records from the file and filter those that match the category.

### Step 6: Calculate Total Expenses
- Read all records from the file.
- Sum up the `amount` fields of all expenses and display the total.

### Step 7: Exit
- Terminate the program when the user chooses the exit option.

---

## Sample Run
```
--- Daily Expense Tracker ---
1. Add Expense
2. View All Expenses
3. Search Expenses by Category
4. Calculate Total Expenses
5. Exit
Enter your choice: 1
Enter Expense ID: 1
Enter Date (DD/MM/YYYY): 10/11/2024
Enter Category: Health
Enter Amount: 10000
Expense added successfully!

--- Daily Expense Tracker ---
1. Add Expense
2. View All Expenses
3. Search Expenses by Category
4. Calculate Total Expenses
5. Exit
Enter your choice: 2

--- All Expenses ---
ID: 1, Date: 10/11/2024, Category: Health, Amount: 10000.00
```
