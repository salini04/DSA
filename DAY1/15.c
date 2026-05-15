#include <stdio.h>  //t o calculate employee salary with bonus. 
int main() {
    float salary, bonus, totalSalary;
    printf("Enter basic salary: ");
    scanf("%f", &salary);
    bonus = salary * 0.10;
    totalSalary = salary + bonus;
    printf("Bonus = %.2f\n", bonus);
    printf("Total Salary after adding bonus = %.2f\n", totalSalary);
    return 0;
}