#include <stdio.h>

long long power(long long a, long long b, long long q)
{
    long long r = 1;

    while (b--)
        r = (r * a) % q;

    return r;
}

int main()
{
    long long a = 5, q = 23;
    long long x = 6, y = 15;
    long long A, B, keyA, keyB;

    /* Alice and Bob send x^a mod q */
    A = power(x, a, q);
    B = power(y, a, q);

    printf("Alice sends : %lld\n", A);
    printf("Bob sends   : %lld\n", B);

    /* Both use the received value and their secret */
    keyA = power(B, x, q);
    keyB = power(A, y, q);

    printf("Alice key   : %lld\n", keyA);
    printf("Bob key     : %lld\n", keyB);

    return 0;
}
