#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    char plaintext[100];
    int a, b;
    int i;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1)
    {
        printf("\nInvalid value of a.\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }

    printf("\nCiphertext: ");

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        int p = plaintext[i] - 'A';
        int c = (a * p + b) % 26;

        printf("%c", c + 'A');
    }

    printf("\n");

    return 0;
}
