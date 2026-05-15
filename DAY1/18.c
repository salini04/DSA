#include <stdio.h>
#include <string.h>   //for product search system. 
int main() {
    char products[5][20] = {"Laptop", "Mouse", "Keyboard", "Monitor", "Printer"};
    char search[20];
    int i, found = 0;
    printf("Enter product name to search: ");
    scanf("%s", search);
    for(i = 0; i < 5; i++) {
        if(strcmp(products[i], search) == 0) {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("Product Found!\n");
    } else {
        printf("Product Not Found!\n");
    }
    return 0;
}