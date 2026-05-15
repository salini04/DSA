#include <stdio.h>     // to calculate total bill using dynamic memory allocation.
#include <stdlib.h>
int main()
{
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    float *prices = (float *)malloc(num_items * sizeof(float));
    if (prices == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");
        return 1; 
    }

    for (int i = 0; i < num_items; i++)
    {
        printf("Enter price for item %d: ", i + 1);
        scanf("%f", &prices[i]);
    }

    float total_bill = 0.0f;
    for (int i = 0; i < num_items; i++)
    {
        total_bill += prices[i];
    }

    printf("\nTotal Bill: %.2f\n", total_bill);

    free(prices);
    
    return 0;
}