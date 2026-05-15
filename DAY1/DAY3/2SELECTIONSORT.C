//EMPLOYEE SALARY IN ASCENDING ORDER USING SELECTION SORT 
#include <stdio.h>
int main() {
    int n, i, j, min_idx, temp;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    int salaries[n];
    
    printf("Enter the salaries of the employees:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &salaries[i]);
    }
    
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (salaries[j] < salaries[min_idx]) {
                min_idx = j;
            }
        }
        temp = salaries[i];
        salaries[i] = salaries[min_idx];
        salaries[min_idx] = temp;
    }

    printf("Salaries sorted in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", salaries[i]);
    }
    
    return 0;
}


