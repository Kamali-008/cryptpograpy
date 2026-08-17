#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
#define TOP 10

/* English letter frequency order */
const char english_freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

/* Count frequency of letters */
void count_frequency(char text[], int freq[])
{
    int i;

    for (i = 0; i < 26; i++)
        freq[i] = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char c = toupper(text[i]);
            freq[c - 'A']++;
        }
    }
}

/* Sort letters according to frequency */
void sort_letters(int freq[], int order[])
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

/* Create plaintext using frequency mapping */
void decrypt_text(char cipher[], int order[], int shift)
{
    char map[26];
    int i;

    for (i = 0; i < 26; i++)
        map[i] = english_freq[(i + shift) % 26];

    printf("Possible plaintext %d: ", shift + 1);

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            char c = toupper(cipher[i]);
            printf("%c", map[order[c - 'A']]);
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
    char cipher[MAX];
    int freq[26];
    int order[26];
    int top;

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("How many possible plaintexts? ");
    scanf("%d", &top);

    if (top > TOP)
        top = TOP;

    count_frequency(cipher, freq);

    sort_letters(freq, order);

    printf("\nTop %d possible plaintexts:\n\n", top);

    for (int i = 0; i < top; i++)
    {
        decrypt_text(cipher, order, i);
    }

    return 0;
}
