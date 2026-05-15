#include <stdio.h>      //to generate employee salary report using calloc().
#include <stdlib.h>
struct Employee
{
    int id;
    char name[100];
    float salary;
};

int main()
{
    int num_employees;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);

    struct Employee *emps = (struct Employee *)calloc(num_employees, sizeof(struct Employee));
    if (emps == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

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

    printf("\nEmployee Salary Report:\n");
    for (int i = 0; i < num_employees; i++)
    {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emps[i].id, emps[i].name, emps[i].salary);
    }

    free(emps);
    return 0;
}