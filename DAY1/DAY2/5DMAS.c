#include <stdio.h>
#include <stdlib.h>
int main(){          // Dynamic Memory Allocation System :Allocate memory dynamically using malloc().
 
     int n;
     int *ptr;
     printf("Enter a number:");
     scanf("%d",&n);
     ptr=(int*)malloc(5*sizeof(int));
     for(int i=0;i<5;i++){
         ptr[i]=i+1;
     }
     for(int i=0;i<5;i++){
         printf("%d\n",ptr[i]);
     }


     free(ptr);
     return 0;
}