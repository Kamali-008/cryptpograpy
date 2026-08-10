#include <stdio.h>

long long power(long long a, long long e, long long n)
{
    long long r = 1;

    while (e > 0) {
        r = (r * a) % n;
        e--;
    }

    return r;
}

int main()
{
    long long e = 17, n = 3233;
    long long c, i;

    printf("Enter encrypted value: ");
    scanf("%lld", &c);

    /* Try all 26 possible letters */
    for (i = 0; i < 26; i++) {
        if (power(i, e, n) == c) {
            printf("Letter = %c\n", 'A' + i);
            break;
        }
    }

    if (i == 26)
        printf("Letter not found\n");

    return 0;
}
