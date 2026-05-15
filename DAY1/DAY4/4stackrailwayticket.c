#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX][MAX];
int top = -1;

void push(char ticket[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow: Cannot book more tickets\n");
    } else {
        top++;
        strcpy(stack[top], ticket);
        printf("Booked Ticket: %s\n", ticket);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow: No tickets to cancel\n");
    } else {
        printf("Cancelled Ticket: %s\n", stack[top]);
        top--;
    }
}

void showLatestTicket() {
    if (top == -1) {
        printf("No tickets booked\n");
    } else {
        printf("Latest Ticket: %s\n", stack[top]);
    }
}

void displayAllTickets() {
    if (top == -1) {
        printf("No tickets booked\n");
    } else {
        printf("All Booked Tickets:\n");
        for (int i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    push("Ticket 101");
    push("Ticket 102");
    showLatestTicket();
    pop();
    showLatestTicket();
    displayAllTickets();
    return 0;
}
