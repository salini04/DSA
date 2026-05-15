#include <stdio.h>  //to calculate shopping cart total bill. 
int main() {
    int q1, q2;
    float p1, p2, total;
    printf("Enter price and quantity of Product 1: ");
    scanf("%f %d", &p1, &q1);
    printf("Enter price and quantity of Product 2: ");
    scanf("%f %d", &p2, &q2);
    total = (p1 * q1) + (p2 * q2);
    printf("Total Shopping Bill = %.2f\n", total);
    return 0;
}