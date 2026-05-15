#include <stdio.h>    //for simple bank account system using functions and pointers.
#include <string.h>


struct BankAccount
{
    int accountNumber;
    char accountHolderName[100];
    float balance;
};

void createAccount(struct BankAccount *account, int accNumber, char name[], float initialBalance)
{
    account->accountNumber = accNumber;
    strcpy(account->accountHolderName, name);
    account->balance = initialBalance;
}

void displayAccountDetails(const struct BankAccount *account)
{
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder Name: %s\n", account->accountHolderName);
    printf("Balance: %.2f\n", account->balance);
}

int main()
{
    struct BankAccount account;

    createAccount(&account, 12345, "John Doe", 1000.00);
    displayAccountDetails(&account);

    return 0;
}
