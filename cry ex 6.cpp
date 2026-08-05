#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Find modular inverse of a modulo 26
int modInverse(int a)
{
    int i;
    for (i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main()
{
    char cipher[100];
    int a, b, a_inv;
    int i;

    printf("Enter the ciphertext: ");
    scanf("%s", cipher);

    // Assume B->E and U->T
    int c1 = 'B' - 'A';   // 1
    int c2 = 'U' - 'A';   // 20
    int p1 = 'E' - 'A';   // 4
    int p2 = 'T' - 'A';   // 19

    // Try all possible values of a
    for (a = 1; a < 26; a++)
    {
        if (gcd(a, 26) != 1)
            continue;

        b = (c1 - a * p1) % 26;
        if (b < 0)
            b += 26;

        if (((a * p2 + b) % 26) == c2)
        {
            printf("\nPossible Key Found:\n");
            printf("a = %d\n", a);
            printf("b = %d\n", b);

            a_inv = modInverse(a);

            printf("\nDecrypted Text: ");

            for (i = 0; cipher[i] != '\0'; i++)
            {
                char ch = cipher[i];

                if (ch >= 'A' && ch <= 'Z')
                {
                    int c = ch - 'A';
                    int p = (a_inv * (c - b + 26)) % 26;
                    printf("%c", p + 'A');
                }
                else
                {
                    printf("%c", ch);
                }
            }
            printf("\n");
            break;
        }
    }

    return 0;
}
