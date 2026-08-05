#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], key[100];
    int i, j = 0;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    printf("\nEncrypted Text: ");

    for(i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];

        if(isalpha(ch))
        {
            int shift = toupper(key[j % strlen(key)]) - 'A';

            if(isupper(ch))
                printf("%c", ((ch - 'A' + shift) % 26) + 'A');
            else
                printf("%c", ((ch - 'a' + shift) % 26) + 'a');

            j++;
        }
        else
        {
            printf("%c", ch);
        }
    }

    return 0;
}
