#include <stdio.h>  // to check whether a student is pass or fail. 
int main() {
    int marks;
    printf("Enter marks: ");
    scanf("%d", &marks);
    if (marks >= 40) {
        printf("Student is PASS\n");
    } else {
        printf("Student is FAIL\n");
    }
    return 0;
}