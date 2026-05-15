//Bubble sort : ECOMMERCE WEBSITE  CHECK product price ,low to high input :700 800 900 200, output: 200 700 800 900 , THROUGH ARRAY without function


#include <stdio.h>
int main() {
    int n, i, j, temp;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    
    int prices[n];
    
    printf("Enter the prices of the products:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (prices[j] > prices[j+1]) {
                // Swap prices[j] and prices[j+1]
                temp = prices[j];
                prices[j] = prices[j+1];
                prices[j+1] = temp;
            }
        }
    }
    
    printf("Prices sorted from low to high:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", prices[i]);
    }
    
    return 0;
}

//Bubble sort : ECOMMERCE WEBSITE  CHECK product price ,HIGH TO LOW input :700 800 900 200, output: 200 700 800 900 , THROUGH ARRAY without function
// #include <stdio.h>
// int main() {
//     int arr[] = {700, 800, 900, 200};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (arr[j] < arr[j+1]) {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }

//     printf("Sorted array: \n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }