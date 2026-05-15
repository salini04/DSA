//2.STUDENT  ROLL NUMBER SEARCHING  SYSTEM: - SEARCHING ROLL NO. WISE- TOP 4 STUDENTS ROLL  WILL BE SHOWN 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int rollno;
    char name[50];
    struct node *next;
};
struct node *head = NULL;
void insert(int rollno, char name[])
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->rollno = rollno;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}
struct node *search(int rollno)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->rollno == rollno)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void displayTop4()
{
    struct node *current = head;
    int count = 0;
    printf("Top 4 Students:\n");
    while (current != NULL && count < 4)
    {
        printf("Roll No: %d, Name: %s\n", current->rollno, current->name);
        current = current->next;
        count++;
        
    }
}
int main()
{
    insert(1, "Alice");
    insert(2, "Bob");
    insert(3, "Charlie");
    insert(4, "David");
    insert(5, "Eve");
    
    int rollnoToSearch = 3;
    struct node *student = search(rollnoToSearch);
    if (student != NULL)
    {
        printf("Student found: Roll No: %d, Name: %s\n", student->rollno, student->name);
    }
    else
    {
        printf("Student with Roll No %d not found.\n", rollnoToSearch);
    }
    
    displayTop4();
    
    return 0;
}



