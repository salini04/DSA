 //Manage student attendance using present and absent values. 
#include <stdio.h>
#define MAX_STUDENTS 100
int main()
{
    int attendance[MAX_STUDENTS] = {0}; // 0 means absent, 1 means present
    int num_students, student_id;

    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);

    if (num_students < 1 || num_students > MAX_STUDENTS)
    {
        printf("Invalid number of students. Please enter a value between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }

    for (int i = 0; i < num_students; i++)
    {
        printf("Enter student ID to mark present (1-%d): ", num_students);
        scanf("%d", &student_id);

        if (student_id < 1 || student_id > num_students)
        {
            printf("Invalid student ID. Please enter a value between 1 and %d.\n", num_students);
            continue;
        }

        attendance[student_id - 1] = 1; // Mark student as present
    }

    printf("\nAttendance Summary:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("Student ID %2d: %s\n", i + 1, attendance[i] == 1 ? "Present" : "Absent");
    }

    return 0;
}

