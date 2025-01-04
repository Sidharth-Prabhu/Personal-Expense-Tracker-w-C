#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define the structure for Expense
typedef struct {
    int id;
    char date[11]; // Format: DD/MM/YYYY
    char category[50];
    float amount;
} Expense;

// Global array and counter for expenses
Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

// Function prototypes
void addExpense();
void viewAllExpenses();
void searchExpensesByCategory();
void calculateTotalExpenses();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    // Load existing expenses from file
    loadFromFile();

    while (1) {
        printf("\n--- Daily Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Search Expenses by Category\n");
        printf("4. Calculate Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewAllExpenses();
                break;
            case 3:
                searchExpensesByCategory();
                break;
            case 4:
                calculateTotalExpenses();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new expense
void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense e;
    printf("Enter Expense ID: ");
    scanf("%d", &e.id);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", e.date);
    printf("Enter Category: ");
    scanf("%s", e.category);
    printf("Enter Amount: ");
    scanf("%f", &e.amount);

    expenses[expenseCount++] = e;
    saveToFile();
    printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewAllExpenses() {
    if (expenseCount == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n--- All Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("ID: %d, Date: %s, Category: %s, Amount: %.2f\n",
               expenses[i].id, expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

// Function to search expenses by category
void searchExpensesByCategory() {
    char category[50];
    int found = 0;

    printf("Enter category to search: ");
    scanf("%s", category);

    printf("\n--- Expenses in Category: %s ---\n", category);
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("ID: %d, Date: %s, Amount: %.2f\n",
                   expenses[i].id, expenses[i].date, expenses[i].amount);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found in this category.\n");
    }
}

// Function to calculate total expenses
void calculateTotalExpenses() {
    float total = 0;

    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }

    printf("Total Expenses: %.2f\n", total);
}

// Function to save expenses to a file
void saveToFile() {
    FILE *file = fopen("expenses.dat", "wb");
    if (file == NULL) {
        printf("Error saving expenses to file!\n");
        return;
    }

    fwrite(expenses, sizeof(Expense), expenseCount, file);
    fclose(file);
}

// Function to load expenses from a file
void loadFromFile() {
    FILE *file = fopen("expenses.dat", "rb");
    if (file == NULL) {
        // No existing file, no expenses to load
        return;
    }

    expenseCount = fread(expenses, sizeof(Expense), MAX_EXPENSES, file);
    fclose(file);
}
