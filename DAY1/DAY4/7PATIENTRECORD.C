#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_QUEUE 100
#define FILE_NAME "patients.txt"

struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[20];
    char disease[50];
    char doctorName[50];
};

struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

int waitingQueue[MAX_QUEUE];
int front = -1;
int rear = -1;

void clearInputBuffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

void readLine(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

int findPatientIndexById(int id)
{
    int i;

    for (i = 0; i < patientCount; i++)
    {
        if (patients[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void savePatientsToFile()
{
    FILE *file = fopen(FILE_NAME, "w");
    int i;

    if (file == NULL)
    {
        printf("\nUnable to save patient records!\n");
        return;
    }

    for (i = 0; i < patientCount; i++)
    {
        fprintf(file, "%d|%s|%d|%s|%s|%s\n",
                patients[i].id,
                patients[i].name,
                patients[i].age,
                patients[i].gender,
                patients[i].disease,
                patients[i].doctorName);
    }

    fclose(file);
}

void loadPatientsFromFile()
{
    FILE *file = fopen(FILE_NAME, "r");
    char line[300];

    if (file == NULL)
    {
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL && patientCount < MAX_PATIENTS)
    {
        line[strcspn(line, "\n")] = '\0';

        if (sscanf(line, "%d|%49[^|]|%d|%19[^|]|%49[^|]|%49[^\n]",
                   &patients[patientCount].id,
                   patients[patientCount].name,
                   &patients[patientCount].age,
                   patients[patientCount].gender,
                   patients[patientCount].disease,
                   patients[patientCount].doctorName) == 6)
        {
            patientCount++;
        }
    }

    fclose(file);
}

void printPatient(struct Patient patient)
{
    printf("ID: %d\n", patient.id);
    printf("Name: %s\n", patient.name);
    printf("Age: %d\n", patient.age);
    printf("Gender: %s\n", patient.gender);
    printf("Disease: %s\n", patient.disease);
    printf("Doctor Name: %s\n", patient.doctorName);
}

void addToWaitingQueue(int patientId)
{
    if (rear == MAX_QUEUE - 1)
    {
        printf("\nWaiting queue is full!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    waitingQueue[rear] = patientId;
}

void addPatient()
{
    int id;

    if (patientCount == MAX_PATIENTS)
    {
        printf("\nPatient storage is full!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (findPatientIndexById(id) != -1)
    {
        printf("\nA patient with this ID already exists!\n");
        return;
    }

    patients[patientCount].id = id;

    printf("Enter Name: ");
    readLine(patients[patientCount].name, sizeof(patients[patientCount].name));

    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);
    clearInputBuffer();

    printf("Enter Gender: ");
    readLine(patients[patientCount].gender, sizeof(patients[patientCount].gender));

    printf("Enter Disease: ");
    readLine(patients[patientCount].disease, sizeof(patients[patientCount].disease));

    printf("Enter Doctor Name: ");
    readLine(patients[patientCount].doctorName, sizeof(patients[patientCount].doctorName));

    addToWaitingQueue(id);
    patientCount++;
    savePatientsToFile();

    printf("\nPatient added successfully!\n");
}

void viewPatients()
{
    int i;

    if (patientCount == 0)
    {
        printf("\nNo patient records found!\n");
        return;
    }

    printf("\n--- Patient Records ---\n");

    for (i = 0; i < patientCount; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printPatient(patients[i]);
    }
}

void searchPatient()
{
    int id;
    int index;

    printf("\nEnter Patient ID to Search: ");
    scanf("%d", &id);
    clearInputBuffer();

    index = findPatientIndexById(id);

    if (index == -1)
    {
        printf("\nPatient not found!\n");
        return;
    }

    printf("\nPatient found!\n");
    printPatient(patients[index]);
}

void deletePatient()
{
    int id;
    int index;
    int i;

    printf("\nEnter Patient ID to Delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    index = findPatientIndexById(id);

    if (index == -1)
    {
        printf("\nPatient not found!\n");
        return;
    }

    for (i = index; i < patientCount - 1; i++)
    {
        patients[i] = patients[i + 1];
    }

    patientCount--;
    savePatientsToFile();

    printf("\nPatient record deleted!\n");
}

void updatePatient()
{
    int id;
    int index;

    printf("\nEnter Patient ID to Update: ");
    scanf("%d", &id);
    clearInputBuffer();

    index = findPatientIndexById(id);

    if (index == -1)
    {
        printf("\nPatient not found!\n");
        return;
    }

    printf("\nEnter New Name: ");
    readLine(patients[index].name, sizeof(patients[index].name));

    printf("Enter New Age: ");
    scanf("%d", &patients[index].age);
    clearInputBuffer();

    printf("Enter New Gender: ");
    readLine(patients[index].gender, sizeof(patients[index].gender));

    printf("Enter New Disease: ");
    readLine(patients[index].disease, sizeof(patients[index].disease));

    printf("Enter New Doctor Name: ");
    readLine(patients[index].doctorName, sizeof(patients[index].doctorName));

    savePatientsToFile();

    printf("\nPatient details updated!\n");
}

void serveNextPatient()
{
    int patientId;
    int index;

    if (front == -1 || front > rear)
    {
        printf("\nNo patients in waiting queue!\n");
        return;
    }

    patientId = waitingQueue[front];
    front++;

    index = findPatientIndexById(patientId);

    printf("\nNext patient from waiting queue:\n");

    if (index == -1)
    {
        printf("Patient ID %d was deleted from records.\n", patientId);
    }
    else
    {
        printPatient(patients[index]);
    }

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void viewWaitingQueue()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\nWaiting queue is empty!\n");
        return;
    }

    printf("\n--- Waiting Queue Patient IDs ---\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", waitingQueue[i]);
    }

    printf("\n");
}

void showMenu()
{
    printf("\n===== Hospital Patient Management System =====\n");
    printf("1. Add Patient\n");
    printf("2. View All Patients\n");
    printf("3. Search Patient by ID\n");
    printf("4. Delete Patient Record\n");
    printf("5. Update Patient Details\n");
    printf("6. View Waiting Queue\n");
    printf("7. Serve Next Patient\n");
    printf("8. Exit\n");
}

int main()
{
    int choice;

    loadPatientsFromFile();

    while (1)
    {
        showMenu();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addPatient();
            break;

        case 2:
            viewPatients();
            break;

        case 3:
            searchPatient();
            break;

        case 4:
            deletePatient();
            break;

        case 5:
            updatePatient();
            break;

        case 6:
            viewWaitingQueue();
            break;

        case 7:
            serveNextPatient();
            break;

        case 8:
            savePatientsToFile();
            printf("\nThank you for using the system!\n");
            exit(0);

        default:
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}