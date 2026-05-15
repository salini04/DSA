#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of patients: ");
    scanf("%d", &n);
    
    int *tokens = (int*)malloc(n * sizeof(int));
    
    printf("Enter the patient token numbers:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &tokens[i]);
    }
    
    bubbleSort(tokens, n);
    
    printf("\nPatient token numbers in ascending order:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", tokens[i]);
    }
    
    free(tokens);
    return 0;
}


