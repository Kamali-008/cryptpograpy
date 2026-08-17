#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char plaintext[100];
    char ciphertext[100];
    int key[100];
    int length, i;

    srand(time(NULL));

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    length = 0;

    while (plaintext[length] != '\0')
        length++;

    printf("\nGenerated Key: ");

    for (i = 0; i < length; i++)
    {
        key[i] = rand() % 26;
        printf("%d ", key[i]);
    }

    printf("\n");

    for (i = 0; i < length; i++)
    {
        if (plaintext[i] >= 'A' &&
            plaintext[i] <= 'Z')
        {
            ciphertext[i] =
                ((plaintext[i] - 'A' + key[i]) % 26) + 'A';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[length] = '\0';

    printf("Plaintext  : %s\n", plaintext);
    printf("Ciphertext : %s\n", ciphertext);

    return 0;
}
