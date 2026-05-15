#include <stdio.h>        ////to swap two account balances using pointer. 
void swap_balances(float *balance1, float *balance2)
{
    float temp = *balance1;
    *balance1 = *balance2;
    *balance2 = temp;
}
int main()
{
    float account1_balance, account2_balance;

    printf("Enter balance for Account 1: ");
    scanf("%f", &account1_balance);

    printf("Enter balance for Account 2: ");
    scanf("%f", &account2_balance);

    printf("\nBefore swapping:\n");
    printf("Account 1 Balance: %.2f\n", account1_balance);
    printf("Account 2 Balance: %.2f\n", account2_balance);

    swap_balances(&account1_balance, &account2_balance);

    printf("\nAfter swapping:\n");
    printf("Account 1 Balance: %.2f\n", account1_balance);
    printf("Account 2 Balance: %.2f\n", account2_balance);

    return 0;
}