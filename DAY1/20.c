#include <stdio.h>  //for simple login authentication system. 
#include <string.h>
int main() {
    char username[20], password[20];
    char correctUsername[] = "admin";
    char correctPassword[] = "1234";
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    if(strcmp(username, correctUsername) == 0 &&
       strcmp(password, correctPassword) == 0) {
        printf("Login Successful!\n");
    }
    else {
        printf("Invalid Username or Password!\n");
    }
    return 0;
}