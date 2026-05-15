/* 
feature:
product add
product search
product display
stock update

use dsa->
product data store=>
multiple product manage=>
memory access=>            dynamicmemory allocation
runtime memory=>           
product finding=>          searching
product name handeling=>   string
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    int n;
    printf("Enter numbers of products: ");
    scanf("%d",&n);

    struct Product *p;
    p=(struct Product*)malloc(n * sizeof(struct Product));
    //add product
    for(int i=0; i<n; i++){
        printf("\n enter product id: ");
        scanf("%d",&p[i].id);

         printf(" enter product name: ");
        scanf("%s",p[i].name);

         printf("enter product quantity: ");
        scanf("%d",&p[i].quantity);

         printf("enter product price: ");
        scanf("%f",&p[i].price);
    }
    //display
    for(int i=0; i<n; i++){
        printf("\n enter product id:%d",p[i].id);
        printf(" enter product name:%s",p[i].name);
        printf("enter product quantity:%d",p[i].quantity);
        printf("enter product price:%f",p[i].price);

        //low stock alert
        if(p[i].quantity <5){
            printf("low stock alert\n");
        }
        printf("\n");
    }
    //search product
    int searchid;
    int found = 0;

    printf("Enter product id to search: ");
    scanf("%d",&searchid);
     for(int i=0; i<n; i++){
        if(p[i].id == searchid){
            printf("\n product found\n");
            printf("product id:%d\n",p[i].id);
            printf("product name:%s\n",p[i].name);
            printf("product quantity:%d\n",p[i].quantity);
            printf("product price:%f",p[i].price);
            break;
        }
    }
    if(found == 0) {
        printf("\n product not found\n");

    }
    //stock update

    int updatedid;
    int newstock;
  printf("\n product id to updated stock\n");
  scanf("%d",&updatedid);
 for(int i=0; i<n; i++){
        if(p[i].id == updatedid){
            printf("enter new stock: ");
            scanf("%d",&newstock);
            p[i].quantity = newstock;
            printf("\n stock updated successfully\n");
            printf("updated quantity:%d\n",p[i].quantity);
            break;
        }
    }
    free(p);
    return 0;
}