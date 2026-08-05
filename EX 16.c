#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[200];
    int freq[26] = {0};
    char map[26];

    // English letter frequency order
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    printf("Enter Cipher Text (UPPERCASE): ");
    scanf("%s", cipher);

    // Count frequency of each letter
    for(int i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            freq[cipher[i] - 'A']++;
    }

    // Build substitution map
    for(int i = 0; i < 26; i++)
    {
        int max = -1;
        int index = -1;

        for(int j = 0; j < 26; j++)
        {
            if(freq[j] > max)
            {
                max = freq[j];
                index = j;
            }
        }

        map[index] = english[i];
        freq[index] = -1;
    }

    printf("\nPossible Plaintext:\n");

    for(int i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            printf("%c", map[cipher[i] - 'A']);
        else
            printf("%c", cipher[i]);
    }

    printf("\n");

    return 0;
}
