#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Encrypted Text: ");

    for(i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            printf("%c", key[ch - 'A']);
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            printf("%c", tolower(key[ch - 'a']));
        }
        else
        {
            printf("%c", ch);
        }
    }

    return 0;
}
