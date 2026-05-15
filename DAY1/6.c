// print multiplication table of number
#include <stdio.h> 
int main()
{ 
    int a ;
    printf("enter a number=");
    scanf("%d",&a);
    printf("Multiplication table of %d\n",a);
    for(int i=1;i<11;i++){
        printf("%d x %d=%d\n",a,i,i*a);
    }
  
 return 0;
}

