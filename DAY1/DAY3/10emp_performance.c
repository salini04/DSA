/*
 Employee Performance Ranking using Bubble Sort 
A company wants to generate an employee performance ranking report based on 
monthly performance scores. The scores should be sorted from highest to lowest 
using Bubble Sort so that top-performing employees appear first.
*/
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(float scores[], char names[][50], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(scores[j] < scores[j+1]) { // Sort in descending order
                // Swap scores
                float tempScore = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = tempScore;

                // Swap corresponding names
                char tempName[50];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], tempName);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    float *scores = (float*)malloc(n * sizeof(float));
    char (*names)[50] = (char (*)[50])malloc(n * 50 * sizeof(char));
    
    printf("Enter employee names and their performance scores:\n");
    for(int i = 0; i < n; i++) {
        printf("Employee %d Name: ", i+1);
        scanf("%s", names[i]);
        printf("Employee %d Score: ", i+1);
        scanf("%f", &scores[i]);
    }
    
    bubbleSort(scores, names, n);
    
    printf("\nEmployee Performance Ranking:\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s - %.2f\n", i+1, names[i], scores[i]);
    }
    
    free(scores);
    free(names);
    return 0;
}