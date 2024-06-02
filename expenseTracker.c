#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an expense
struct Expense {
    char date[11];  // Assuming format YYYY-MM-DD
    char category[50];
    float amount;
    char description[100];
};

// Function prototypes
void addExpense();
void viewExpenses();
void visualizeExpenses();

// Global variables
struct Expense expenses[100]; // Assuming a maximum of 100 expenses
int numExpenses = 0;

int main() {
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Visualize Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                visualizeExpenses();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addExpense() {
    struct Expense newExpense;
    printf("\nEnter Date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);
    printf("Enter Category: ");
    scanf("%s", newExpense.category);
    printf("Enter Amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter Description: ");
    scanf("%s", newExpense.description);

    expenses[numExpenses++] = newExpense;
    printf("Expense added successfully.\n");
}

void viewExpenses() {
    printf("\nAll Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Date: %s | Category: %s | Amount: %.2f | Description: %s\n",
               expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].description);
    }
}

void visualizeExpenses() {
    // Your visualization code goes here
    printf("\nVisualization can not be implemented in IDE.\n");
}
