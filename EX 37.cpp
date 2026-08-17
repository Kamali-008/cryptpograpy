#include <stdio.h>
#include <ctype.h>
#include <string.h>

char english_freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

void countFrequency(char text[], int freq[])
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char c = toupper(text[i]);
            freq[c - 'A']++;
        }
    }
}

void sortFrequency(int freq[], int order[])
{
    int i, j, temp;

    for (i = 0; i < 26; i++)
        order[i] = i;

    for (i = 0; i < 25; i++)
    {
        for (j = i + 1; j < 26; j++)
        {
            if (freq[order[i]] < freq[order[j]])
            {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
}

void decrypt(char cipher[], int order[])
{
    char map[26];
    int i;

    for (i = 0; i < 26; i++)
        map[order[i]] = english_freq[i];

    printf("\nPossible plaintext:\n");

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            char c = toupper(cipher[i]);
            printf("%c", map[c - 'A']);
        }
        else
        {
            printf("%c", cipher[i]);
        }
    }

    printf("\n");
}

int main()
{
    char cipher[500];
    int freq[26] = {0};
    int order[26];

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    countFrequency(cipher, freq);

    sortFrequency(freq, order);

    decrypt(cipher, order);

    return 0;
}
