#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    struct Student *next;
};

struct Student *head = NULL;

void addstudent(int roll)  {
    struct Student *newNode;
    newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    } else {
        struct Student *temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("student added successfully");
}

void viewstudent()  {
        struct Student *temp = head;
        printf("student list:\n");

        while(temp!=NULL){
            printf("Roll no: %d\n",temp->roll);
            temp = temp->next;
        }
}
void searchstudent(int roll)  {
        struct Student *temp = head;
        int found = 0;

        while(temp!=NULL){
            if(temp->roll == roll){
                found =1;
                break;
            }
            temp = temp->next;
        }
        if(found == 1){
            printf("student found\n");
        } else {
             printf("student not found");
        }
}
void deletestudent()  {
        
    if(head == NULL){
        printf("list empty\n");
        return ;
    }
 struct Student *temp = head;
 head = head->next;
 free(temp);
 printf("first student deleted");

        
}

int main(){
    addstudent(101);
    addstudent(102);
    addstudent(103);

    viewstudent();
    searchstudent(102);
    deletestudent();
    viewstudent();

    return 0;

}