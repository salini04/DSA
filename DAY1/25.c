#include <stdio.h>    //for inventory stock update system.
#define MAX_PRODUCTS 100
int main()
{
    int stock[MAX_PRODUCTS] = {0}; // Initialize stock for each product to 0
    int num_products, product_id, quantity;

    printf("Enter the number of products (max %d): ", MAX_PRODUCTS);
    scanf("%d", &num_products);

    if (num_products < 1 || num_products > MAX_PRODUCTS)
    {
        printf("Invalid number of products. Please enter a value between 1 and %d.\n", MAX_PRODUCTS);
        return 1;
    }

    for (int i = 0; i < num_products; i++)
    {
        printf("Enter product ID to update stock (1-%d): ", num_products);
        scanf("%d", &product_id);

        if (product_id < 1 || product_id > num_products)
        {
            printf("Invalid product ID. Please enter a value between 1 and %d.\n", num_products);
            continue;
        }

        printf("Enter quantity to add to stock for product ID %d: ", product_id);
        scanf("%d", &quantity);

        stock[product_id - 1] += quantity; 
    }

    printf("\nInventory Stock Summary:\n");
    for (int i = 0; i < num_products; i++)
    {
        printf("Product ID %2d: Stock Quantity: %d\n", i + 1, stock[i]);
    }

    return 0;
}