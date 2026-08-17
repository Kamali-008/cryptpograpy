#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long mod_pow(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

long long mod_inverse(long long a, long long m)
{
    long long i;

    for (i = 1; i < m; i++)
    {
        if ((a * i) % m == 1)
            return i;
    }

    return -1;
}

int main()
{
    long long p = 23;
    long long q = 11;
    long long g = 4;
    long long x = 3;       // Private key
    long long y;           // Public key
    long long message = 7;

    long long k1, k2;
    long long r1, s1;
    long long r2, s2;
    long long kinv;

    srand(time(NULL));

    /* Public key */
    y = mod_pow(g, x, p);

    printf("Message = %lld\n", message);
    printf("Private Key x = %lld\n", x);
    printf("Public Key y = %lld\n\n", y);

    /* First signature */
    k1 = (rand() % (q - 2)) + 2;
    kinv = mod_inverse(k1, q);

    r1 = mod_pow(g, k1, p) % q;
    s1 = (kinv * (message + x * r1)) % q;

    /* Second signature with different k */
    do
    {
        k2 = (rand() % (q - 2)) + 2;
    } while (k2 == k1);

    kinv = mod_inverse(k2, q);

    r2 = mod_pow(g, k2, p) % q;
    s2 = (kinv * (message + x * r2)) % q;

    printf("First Signature:\n");
    printf("k = %lld\n", k1);
    printf("r = %lld\n", r1);
    printf("s = %lld\n\n", s1);

    printf("Second Signature:\n");
    printf("k = %lld\n", k2);
    printf("r = %lld\n", r2);
    printf("s = %lld\n\n", s2);

    if (r1 != r2 || s1 != s2)
        printf("Result: Signatures are different.\n");
    else
        printf("Result: Signatures are same.\n");

    return 0;
}
