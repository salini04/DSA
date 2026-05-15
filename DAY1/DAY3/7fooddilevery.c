#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Order {
    int orderID;
    char customerName[50];
    char foodItem[50];
    struct Order *next;
};
struct Order *head = NULL;

void addOrder(int id, char name[], char food[]) {
    struct Order *newNode;
    newNode = (struct Order*)malloc(sizeof(struct Order));
    newNode->orderID = id;
    strcpy(newNode->customerName, name);
    strcpy(newNode->foodItem, food);
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        struct Order *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Order Added Successfully\n");
}

void showOrders() {
    struct Order *temp = head;
    if(head == NULL) {
        printf("\nNo Orders Found\n");
        return;
    }
    while(temp != NULL) {
        printf("Order ID      : %d\n", temp->orderID);
        printf("Customer Name : %s\n", temp->customerName);
        printf("Food Item     : %s\n", temp->foodItem);
        temp = temp->next;
    }
}

void searchOrder(int id) {
    struct Order *temp = head;
    int found = 0;
    while(temp != NULL) {
        if(temp->orderID == id) {
            printf("\nOrder Found\n");
            printf("Order ID      : %d\n", temp->orderID);
            printf("Customer Name : %s\n", temp->customerName);
            printf("Food Item     : %s\n", temp->foodItem);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(!found) {
        printf("\nOrder Not Found\n");
    }
}

int main() {
    addOrder(1, "Alice", "Pizza");
    addOrder(2, "Bob", "Burger");
    addOrder(3, "Charlie", "Pasta");

    printf("\nAll Orders:\n");
    showOrders();

    printf("\nSearch for Order ID 2:\n");
    searchOrder(2);

    printf("\nSearch for Order ID 5:\n");
    searchOrder(5);

    return 0;
}