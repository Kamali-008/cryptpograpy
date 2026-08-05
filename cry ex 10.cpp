#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
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

void encrypt(char text[])
{
    int i, r1, c1, r2, c2;
    char a, b;

    printf("\nEncrypted Text: ");

    for(i = 0; text[i] != '\0'; i += 2)
    {
        a = text[i];

        if(text[i + 1] == '\0')
            b = 'X';
        else
            b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if(r1 == r2)
        {
            printf("%c%c", matrix[r1][(c1 + 1) % 5],
                           matrix[r2][(c2 + 1) % 5]);
        }
        else if(c1 == c2)
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
    char plaintext[200];
    int i, j = 0;

    printf("Enter Plain Text (without spaces/punctuation): ");
    scanf("%s", plaintext);

    for(i = 0; plaintext[i]; i++)
        plaintext[i] = toupper(plaintext[i]);

    encrypt(plaintext);

    return 0;
}
