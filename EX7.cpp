#include <stdio.h>

int main()
{
    // Plaintext-Ciphertext pairs
    int p1 = 4, p2 = 19;    // E and T
    int c1 = 1, c2 = 20;    // B and U

    int a, b;

    for(a = 1; a < 26; a++)
    {
        if((a % 2 != 0) && (a != 13))    // gcd(a,26)=1
        {
            b = (c1 - a * p1) % 26;

            if(b < 0)
                b += 26;

            if(((a * p2 + b) % 26) == c2)
            {
                printf("Key Found:\n");
                printf("a = %d\n", a);
                printf("b = %d\n", b);
                break;
            }
        }
    }

    return 0;
}
