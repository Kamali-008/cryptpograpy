#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[100];
    int limit;

    printf("Enter Cipher Text (uppercase): ");
    scanf("%s", cipher);

    printf("Enter number of possible plaintexts to display: ");
    scanf("%d", &limit);

    if(limit > 26)
        limit = 26;

    printf("\nPossible Plaintexts:\n");

    for(int key = 0; key < limit; key++)
    {
        printf("\nKey %2d : ", key);

        for(int i = 0; cipher[i] != '\0'; i++)
        {
            if(isalpha(cipher[i]))
            {
                char ch = ((cipher[i] - 'A' - key + 26) % 26) + 'A';
                printf("%c", ch);
            }
            else
            {
                printf("%c", cipher[i]);
            }
        }
    }

    return 0;
}
