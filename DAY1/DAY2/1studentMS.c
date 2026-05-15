#include <stdio.h>

struct Student{
    int id;
    char name[60];
    float marks;
};

int main(){
struct Student s[3];   //char store
for(int i=0;i<3;i++){
    printf("Enter id: ");
    scanf("%d",&s[i].id);

    printf("Enter name: ");
    scanf("%s",&s[i].name);
    
    printf("Enter marks: ");
    scanf("%f",&s[i].marks);
}

for(int i=0;i<3;i++){
    printf("Enter id: %d \n",s[i].id);
    printf("Enter name:%s \n",s[i].name);
    printf("Enter marks:%f \n",s[i].marks);

}
return 0;
} 
//  EMPLOYEE SALARY MANAGEMENT:-display those employee only who has salary less than 5000  they can do mediclaim   and salary>10000 then can have 5% pf  and add bonus and salary filter
//10 employee data only

// #include <stdio.h>

// struct Employee{
//     int id;
//     char name[60];
//     int salary;
// };

// int main(){
// struct Employee e[10];   //char store
// for(int i=0;i<10;i++){
//     printf("Enter id: ");
//     scanf("%d",&e[i].id);

//     printf("Enter name: ");
//     scanf("%s",&e[i].name);
    
//     printf("Enter marks: ");
//     scanf("%d",&e[i].salary);
// }

// for(int i=0;i<10;i++){
//     printf("Enter id: %d \n",e[i].id);
//     printf("Enter name:%s \n",e[i].name);
//     printf("Enter marks:%d \n",e[i].salary);

// }

// printf("Display those employee whose salary is less then 5000:");
//  if(salary < 5000){
//     printf("Eligible for medi claim.");
// }
// if (salary >10000){
//     int pf=0.05*salary;
//     printf("PF deducted ");
// }
// return 0;
// } 
