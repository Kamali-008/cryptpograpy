#include <stdio.h>

int main()
{
    int K = 7;
    int X = 12;
    int T, X2, MAC;

    /* One-block CBC-MAC */
    T = X ^ K;

    printf("Message X       = %d\n", X);
    printf("Key K           = %d\n", K);
    printf("CBC-MAC T       = %d\n", T);

    /* Construct X || (X XOR T) */
    X2 = X ^ T;

    printf("\nSecond block X^T = %d\n", X2);

    /* CBC-MAC of two-block message */
    MAC = X2 ^ T ^ K;

    printf("MAC(X || (X^T)) = %d\n", MAC);

    if (MAC == T)
        printf("\nForgery successful! MAC is same as T.\n");
    else
        printf("\nForgery failed.\n");

    return 0;
}
