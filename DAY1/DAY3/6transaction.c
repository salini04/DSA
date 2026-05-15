/*. BANKING SECTOR:
TRANSACTION HISTORY STORED DYNAMICALLY

FEATURES:
1.ADD TRANSACTION
2.SHOW TRANSACTION HISTORY
3.SEARCH TRANSACTION LIST
4.DELETE FIRST TRANSACTION HISTORY

WORKFLOW:
CUSTOMER TRANSACTION -> NEW TRANSACTION NODE -> HISTORY STORE
-> SEARCH->VIEW->DELETE
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    int transactionID;
    char type[20];
    float amount;
    struct Transaction *next;
};

struct Transaction *head = NULL;


void addTransaction(int id, char type[], float amount) {
    struct Transaction *newNode;
    newNode = (struct Transaction*)malloc(sizeof(struct Transaction));
    newNode->transactionID = id;
    strcpy(newNode->type, type);
    newNode->amount = amount;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        struct Transaction *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Transaction Added Successfully\n");
}


void showTransactions() {
    struct Transaction *temp = head;
    if(head == NULL) {
        printf("\nNo Transaction History Found\n");
        return;
    }
    while(temp != NULL) {
        printf("Transaction ID : %d\n", temp->transactionID);
        printf("Type           : %s\n", temp->type);
        printf("Amount         : %.2f\n", temp->amount);
        temp = temp->next;
    }
}


void searchTransaction(int id) {
    struct Transaction *temp = head;
    int found = 0;
    while(temp != NULL) {

        if(temp->transactionID == id) {
            printf("\nTransaction Found\n");
            printf("Transaction ID : %d\n", temp->transactionID);
            printf("Type           : %s\n", temp->type);
            printf("Amount         : %.2f\n", temp->amount);

            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0) {
        printf("\nTransaction Not Found\n");
    }
}


void deleteTransaction() {

    if(head == NULL) {
        printf("\nNo Transaction To Delete\n");
        return;
    }
    struct Transaction *temp = head;
    head = head->next;
    printf("\nDeleted Transaction ID : %d\n", temp->transactionID);
    free(temp);
}

int main() {

    addTransaction(101, "Deposit", 5000);
    addTransaction(102, "Withdraw", 2000);
    addTransaction(103, "Transfer", 3500);

    showTransactions();
    searchTransaction(102);
    deleteTransaction();
    showTransactions();

    return 0;
}0