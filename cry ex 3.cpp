#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];
char key[] = "MONARCHY";
char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

void generateMatrix()
{
    int used[26] = {0};
    int i, j, k = 0;

    used['J' - 'A'] = 1; // I and J are treated as the same

    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; alphabet[i] != '\0'; i++)
    {
        char ch = alphabet[i];
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char text[])
{
    int i;
    char a, b;
    int r1, c1, r2, c2;

    printf("Encrypted Text: ");

    for (i = 0; text[i] != '\0'; i += 2)
    {
        a = toupper(text[i]);

        if (text[i + 1] == '\0')
            b = 'X';
        else
            b = toupper(text[i + 1]);

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2)
        {
            printf("%c%c", matrix[r1][(c1 + 1) % 5],
                           matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2)
        {
            printf("%c%c", matrix[(r1 + 1) % 5][c1],
                           matrix[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c%c", matrix[r1][c2],
                           matrix[r2][c1]);
        }
    }
}

int main()
{
    char plaintext[100];

    generateMatrix();

    printf("Playfair Matrix:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    printf("\nEnter plaintext (even number of letters): ");
    scanf("%s", plaintext);

    encrypt(plaintext);

    return 0;
}
