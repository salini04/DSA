//ARRAY STACK PUSH RELATED
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;

void push(int n)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    return 0;
}