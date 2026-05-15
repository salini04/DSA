// find the largest of two numbers
#include <stdio.h>
int main(){
    int a,b;
    printf("enter the first and second number=");
    scanf("%d  %d",&a,&b);
    if(a>b){
        printf("a i.e %d is largest among two number",a);
    }
    else{
        printf("b i.e %d is largest among two number",b);
    }
return 0;
}