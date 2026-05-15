#include <stdio.h>
int main(){          //pointer Memory Address System :Access variable memory address using pointers.
     int n;
     int *ptr;
     printf("Enter a number:");
     scanf("%d",&n);
     ptr=&n;
     printf("value=%d\n",n);
     printf("address=%p\n",&n);
     printf("pointer value=%d\n",*ptr);
     printf("pointer address=%p\n",&ptr);
     return 0;
}