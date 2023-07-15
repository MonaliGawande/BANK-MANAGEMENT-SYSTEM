#include <stdio.h>
#include <stdlib.h>

struct Customer {
    int customerId;
    char customerName[100];
};

struct Account {
    int accountId;
    int customerId;
    double balance;
};

struct Customer customers[100];
struct Account accounts[100];
int customerCount = 0;
int accountCount = 0;

void addCustomer() {
    struct Customer customer;
    printf("Enter customer ID: ");
    scanf("%d", &customer.customerId);
    printf("Enter customer name: ");
    scanf("%s", customer.customerName);

    customers[customerCount++] = customer;
    printf("CUSTOMER CREATED SUCCESSFULLY!\n");
}

void createAccount() {
    struct Account account;
    printf("Enter account ID: ");
    scanf("%d", &account.accountId);
    printf("Enter customer ID for the account: ");
    scanf("%d", &account.customerId);
    printf("Enter initial balance: ");
    scanf("%lf", &account.balance);

    accounts[accountCount++] = account;
    printf("ACCOUNT CREATED SUCCESSFULLY!\n");
}

void deposit() {
    int accountId;
    double amount;
    printf("Enter account ID for deposit: ");
    scanf("%d", &accountId);
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountId == accountId) {
            accounts[i].balance += amount;
            printf("SUCCESSFULLY DEPOSITED!\n AVAILABLE BALANCE IS: %.2lf\n", accounts[i].balance);
            return;
        }
    }

    printf("INVALID ACCOUNT ID!\n");
}

void withdraw() {
    int accountId;
    double amount;
    printf("Enter account ID for withdrawal: ");
    scanf("%d", &accountId);
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountId == accountId) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("WITHDRAWAL SUCCESSFUL!\n NEW BALANCE: %.2lf\n", accounts[i].balance);
            } else {
                printf("INSUFFICIENT BALANCE!\n");
            }
            return;
        }
    }

    printf("INVALID ACCOUNT ID!\n");
}

void displayAccounts() {
    printf("--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account ID: %d\n", accounts[i].accountId);
        printf("Customer ID: %d\n", accounts[i].customerId);
        printf("Balance: %.2lf\n", accounts[i].balance);
        printf("-----------------------\n");
    }
}

int main() {
    int choice;
    do {
        printf("<<<<<<<<<< BANK MANAGEMENT SYSTEM >>>>>>>>>>\n");
        printf("1. Create Customer\n");
        printf("2. Create Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Display Accounts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                createAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                displayAccounts();
                break;
            case 0:
                printf("********************************* EXIT PROGRAM ************************************\n");
                break;
            default:
                printf("INVALID CHOICE! PLEASE TRY AGAIN.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
