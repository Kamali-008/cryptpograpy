#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'R','O','Y','A','L'},
    {'N','E','W','Z','D'},
    {'V','B','C','F','G'},
    {'H','I','K','M','P'},
    {'Q','S','T','U','X'}
};

void findPosition(char ch, int *row, int *col)
{
    if(ch == 'J')
        ch = 'I';

    int i, j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decrypt(char text[])
{
    int i;
    int r1, c1, r2, c2;

    printf("\nDecrypted Text:\n");

    for(i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i+1], &r2, &c2);

        if(r1 == r2)
        {
            printf("%c", matrix[r1][(c1 + 4) % 5]);
            printf("%c", matrix[r2][(c2 + 4) % 5]);
        }
        else if(c1 == c2)
        {
            printf("%c", matrix[(r1 + 4) % 5][c1]);
            printf("%c", matrix[(r2 + 4) % 5][c2]);
        }
        else
        {
            printf("%c", matrix[r1][c2]);
            printf("%c", matrix[r2][c1]);
        }
    }
}

int main()
{
    char cipher[500];

    printf("Enter Playfair Cipher Text:\n");
    scanf("%s", cipher);

    decrypt(cipher);

    return 0;
}
