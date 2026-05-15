#include <stdio.h> //sum of  n natural numbers
int main(){
    int n, i, s = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        s += i;
    }
    printf("Sum of %d natural numbers = %d\n", n, s);
    return 0;
}
