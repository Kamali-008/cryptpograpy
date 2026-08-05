#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    // Check whether 'a' is valid
    if (a != 1 && a != 3 && a != 5 && a != 7 && a != 9 &&
        a != 11 && a != 15 && a != 17 && a != 19 &&
        a != 21 && a != 23 && a != 25)
    {
        printf("\nInvalid value of 'a'! It must be coprime with 26.\n");
        return 0;
    }

    printf("\nEncrypted Text: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            int p = ch - 'A';
            ch = ((a * p + b) % 26) + 'A';
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            int p = ch - 'a';
            ch = ((a * p + b) % 26) + 'a';
        }

        printf("%c", ch);
    }

    return 0;
}
