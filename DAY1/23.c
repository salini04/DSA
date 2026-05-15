#include <stdio.h>        //to store student marks dynamically using malloc(). 
#include <stdlib.h>
int main()
{
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    int *marks = (int *)malloc(num_students * sizeof(int));
    if (marks == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");
        return 1; 
    }

    for (int i = 0; i < num_students; i++)
    {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nStudent Marks:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }

    free(marks);
    
    return 0;
}