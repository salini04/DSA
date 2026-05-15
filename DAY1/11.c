#include <stdio.h>  //to calculate total and average marks of students.
int main() {
    int marks1, marks2, marks3, total;
    float average;
    printf("Enter marks of subjects: ");
    scanf("%d %d %d", &marks1, &marks2, &marks3);
    total = marks1 + marks2 + marks3;
    average = total / 3.0;
    printf("Total Marks = %d\n", total);
    printf("Average Marks = %.2f\n", average);
    return 0;
}
