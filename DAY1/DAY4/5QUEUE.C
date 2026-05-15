//ARRAY QUEUE ENQUEUE RELATED
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int n)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=n;  
    }
}

//display queue
void display(){
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }   
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}