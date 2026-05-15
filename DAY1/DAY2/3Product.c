#include <stdio.h>
struct Product {
    int id;
    char name[50];
    float price;
};

int main() {
    struct Product products[100];
    int n, i, searchId, found = 0;

    printf("Enter number of products: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of product %d:\n", i + 1);

        printf("Product ID: ");
        scanf("%d", &products[i].id);

        printf("Product Name: ");
        scanf(" %[^\n]", products[i].name);

        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    for(i = 0; i < n; i++) {
        if(products[i].id == searchId) {
            printf("\nProduct Found!\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nProduct not found in database.\n");
    }

    return 0;
}