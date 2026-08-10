#include <stdio.h>

long long gcd(long long a, long long b)
{
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long power(long long a, long long b, long long n)
{
    long long r = 1;
    while (b--) r = (r * a) % n;
    return r;
}

int main()
{
    long long p = 61, q = 53;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 17, d = 0;
    long long msg, enc, dec;

    /* Find private key d */
    while ((e * (++d)) % phi != 1);

    printf("Public Key  : (%lld, %lld)\n", e, n);
    printf("Private Key : (%lld, %lld)\n", d, n);

    printf("Enter message: ");
    scanf("%lld", &msg);

    enc = power(msg, e, n);
    dec = power(enc, d, n);

    printf("Encrypted    : %lld\n", enc);
    printf("Decrypted    : %lld\n", dec);

    printf("\nIf private key is leaked, changing only e and d");
    printf(" while keeping n is NOT safe.\n");
    printf("Generate new p, q, n, e and d.\n");

    return 0;
}
