// Create an ATM system to withdraw money and check balance.
#include <stdio.h>  
int main() {
    int pin, enteredPin;
    float balance = 7000000000, withdraw;
    pin = 9748;
    printf("Enter ATM PIN: ");
    scanf("%d", &enteredPin);
    if (enteredPin == pin) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &withdraw);
        if (withdraw <= balance) {
            balance = balance - withdraw;
            printf("Withdrawal Successful!\n");
            printf("Remaining Balance = %.2f\n", balance);
        }
        else {
            printf("Insufficient Balance!\n");
        }
    }
    else {
        printf("Incorrect PIN!\n");
    }
    return 0;
}