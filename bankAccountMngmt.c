#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char account_holder[100];
    char account_type[10];
    double balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    BankAccount new_account;
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter account holder name: ");
    scanf("%s", new_account.account_holder);
    printf("Enter account type (savings/checking): ");
    scanf("%s", new_account.account_type);

    if (strcmp(new_account.account_type, "savings") != 0 && strcmp(new_account.account_type, "checking") != 0) {
        printf("Invalid account type. Please enter 'savings' or 'checking'.\n");
        return;
    }

    printf("Enter initial balance: ");
    scanf("%lf", &new_account.balance);

    accounts[account_count++] = new_account;
    printf("Account %d created successfully.\n", new_account.account_number);
}

void deposit() {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);

            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited $%.2lf. New balance is $%.2lf.\n", amount, accounts[i].balance);
            } else {
                printf("Deposit amount must be positive.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrew $%.2lf. New balance is $%.2lf.\n", amount, accounts[i].balance);
            } else {
                printf("Insufficient funds or invalid withdrawal amount.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void check_balance() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("The balance for account %d is $%.2lf.\n", account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void calculate_interest() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            double interest_rate = 0.0;
            if (strcmp(accounts[i].account_type, "savings") == 0) {
                interest_rate = 0.04;
            } else if (strcmp(accounts[i].account_type, "checking") == 0) {
                interest_rate = 0.01;
            }

            double interest = accounts[i].balance * interest_rate;
            printf("Interest for account %d is $%.2lf.\n", account_number, interest);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                calculate_interest();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
