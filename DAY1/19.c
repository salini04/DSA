#include <stdio.h> //to sort product prices in ascending order. 
int main() {
    int prices[5], i, j, temp;
    printf("Enter 5 product prices:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &prices[i]);
    }
    for(i = 0; i < 5; i++) {
        for(j = i + 1; j < 5; j++) {
            if(prices[i] > prices[j]) {
                temp = prices[i];
                prices[i] = prices[j];
                prices[j] = temp;
            }
        }
    }
    printf("Prices in Ascending Order:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", prices[i]);
    }
    return 0;
}