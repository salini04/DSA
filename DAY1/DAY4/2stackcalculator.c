//calculator using stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
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

int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int n=stack[top];
        top--;
        return n;
    }
}

int main()
{
    char exp[MAX];
    printf("Enter the expression: ");
    scanf("%s",exp);
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            push(exp[i]-'0');
        }
        else
        {
            int op2=pop();
            int op1=pop();
            switch(exp[i])
            {
                case '+':
                    push(op1+op2);
                    break;
                case '-':
                    push(op1-op2);
                    break;
                case '*':
                    push(op1*op2);
                    break;
                case '/':
                    push(op1/op2);
                    break;
            }
        }
    }
    printf("Result: %d\n",pop());
    return 0;
}