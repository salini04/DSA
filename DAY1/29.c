#include <stdio.h>     //for hospital patient record system. 
#include <string.h>
struct Patient
{
    int id;
    char name[100];
    int age;
    char diagnosis[200];
};

int main()
{
    struct Patient patients[100];
    int num_patients;

    printf("Enter the number of patients: ");
    scanf("%d", &num_patients);

    for (int i = 0; i < num_patients; i++)
    {
        printf("Enter details for patient %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &patients[i].id);
        printf("Name: ");
        scanf("%s", patients[i].name);
        printf("Age: ");
        scanf("%d", &patients[i].age);
        printf("Diagnosis: ");
        scanf("%s", patients[i].diagnosis);
    }

    printf("\nPatient Details:\n");
    for (int i = 0; i < num_patients; i++)
    {
        printf("ID: %d, Name: %s, Age: %d, Diagnosis: %s\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].diagnosis);
    }

    return 0;
}