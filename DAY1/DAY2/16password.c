#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int has_uppercase = 0;
    int has_special = 0;

    printf("Enter password: ");
    scanf("%99s", password);

    int length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        if (isupper((unsigned char)password[i]))
        {
            has_uppercase = 1;
        }
        else if (!isalnum((unsigned char)password[i]))
        {
            has_special = 1;
        }
    }

    if (length == 8 && has_uppercase && has_special)
    {
        printf("Password is valid.\n");
    }
    else
    {
        printf("Password is invalid.\n");

        if (length != 8)
        {
            printf("Password length must be exactly 8 characters.\n");
        }
        if (!has_uppercase)
        {
            printf("Password must contain at least one uppercase letter.\n");
        }
        if (!has_special)
        {
            printf("Password must contain at least one special character.\n");
        }
    }

    return 0;
}