#include <stdio.h>       // to store and display multiple employee records. 
#include <string.h>

struct Employee
{
    int id;
    char name[100];
    float salary;
};

int main()
{
    struct Employee emps[100];
    int num_employees;

    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);

    for (int i = 0; i < num_employees; i++)
    {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emps[i].id);
        printf("Name: ");
        scanf("%s", emps[i].name);
        printf("Salary: ");
        scanf("%f", &emps[i].salary);
    }

    printf("\nEmployee Details:\n");
    for (int i = 0; i < num_employees; i++)
    {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emps[i].id, emps[i].name, emps[i].salary);
    }

    return 0;
}