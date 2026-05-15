#include <stdio.h>
#include <string.h>

int main(){
    char books[3] [20] = {"react","c","nextjs"};
    char search[20] = "nextjs";
    int found = 0;
    for(int i=0; i<3;i++){
        if(strcmp(books[i],search)==0){
            found = 1;
            break;
        }
    }
    if(found == 1) {
        printf("book found");
    } else {
        printf("book not found");
    }
return 0;
}
