#include <stdio.h>  // to find factorial of a number
int main() {
    int n;
    int factorial = 1; 
    printf("Enter an integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %d\n", n, factorial);
    }

    return 0;
}
