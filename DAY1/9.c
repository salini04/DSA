#include <stdio.h>
int addition(int n1, int n2);

int main() {
    int a, b, sum;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    
    sum = addition(a, b);
    printf("The sum is: %d\n", sum);
    return 0;
}

int addition(int n1, int n2) {
    return n1 + n2; 
}
