#include <stdio.h>          // to update employee salary using pointer. 
void update_salary(float *salary, float increment)
{
    *salary += increment; // Update the salary by adding the increment
}

int main()
{
    float employee_salary, increment_amount;

    printf("Enter current salary of the employee: ");
    scanf("%f", &employee_salary);

    printf("Enter increment amount: ");
    scanf("%f", &increment_amount);

    printf("\nBefore update:\n");
    printf("Employee Salary: %.2f\n", employee_salary);

    update_salary(&employee_salary, increment_amount);

    printf("\nAfter update:\n");
    printf("Employee Salary: %.2f\n", employee_salary);

    return 0;
}