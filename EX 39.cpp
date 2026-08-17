#include <stdio.h>
#include <ctype.h>
#include <string.h>

void decrypt(char cipher[], int key)
{
    int i;
    char result[500];

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            char c = toupper(cipher[i]);

            result[i] =
                ((c - 'A' - key + 26) % 26) + 'A';
        }
        else
        {
            result[i] = cipher[i];
        }
    }

    result[i] = '\0';

    printf("Key %2d : %s\n", key, result);
}

int main()
{
    char cipher[500];

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("\nPossible plaintexts:\n");

    for (int key = 0; key < 26; key++)
        decrypt(cipher, key);

    return 0;
}
