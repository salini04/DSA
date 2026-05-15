// Browser history management system  using stack:->website history save 
//->new website open ->back button work->current page display ->use  lifo rules
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX 100
char stack[MAX][MAX];

int top=-1;
void visit(char url[])
{
    if(top==MAX-1)
    {
        printf("Stack Overflow means history is full\n");
    }
    else
    {
        top++;
        strcpy(stack[top],url);
        printf("\nvisited:%s\n",url);
    }
}
void back()
{
    if(top==-1)
    {
        printf("Stack Underflow means there is no history\n");
    }
    else
    {
        printf("\nback:%s\n",stack[top]);
        top--;
    }
}

void currentpage()
{
    if(top==-1)
    {
        printf("No history or no current page\n");
    }
    else
    {
        printf("Current page: %s\n",stack[top]);
    }
}

void dhistory(){
    if(top==-1)
    {
        printf("No history to display\n");
    }
    else
    {
        printf("\nFull History:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%s\n",stack[i]);
        }
    }

}

int main()
{
    visit("www.google.com");
    visit("www.facebook.com");
    visit("www.youtube.com");
    currentpage();
    back();
    currentpage();
    dhistory();
    back();
    currentpage();
    dhistory();
    return 0;
}

