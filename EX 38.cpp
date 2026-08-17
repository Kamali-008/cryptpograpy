#include <stdio.h>

int mod26(int x)
{
    x %= 26;

    if (x < 0)
        x += 26;

    return x;
}

int inverseMod26(int x)
{
    int i;

    for (i = 1; i < 26; i++)
    {
        if ((x * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    int P[2][2];
    int C[2][2];

    int det, invDet;
    int K[2][2];

    printf("Enter plaintext matrix P (2x2):\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &P[i][j]);

    printf("Enter ciphertext matrix C (2x2):\n");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &C[i][j]);

    det = mod26(P[0][0] * P[1][1]
              - P[0][1] * P[1][0]);

    invDet = inverseMod26(det);

    if (invDet == -1)
    {
        printf("Key cannot be recovered.\n");
        printf("Plaintext matrix is not invertible modulo 26.\n");
        return 0;
    }

    /* Inverse of P */
    int Pinv[2][2];

    Pinv[0][0] = mod26(P[1][1] * invDet);
    Pinv[0][1] = mod26(-P[0][1] * invDet);
    Pinv[1][0] = mod26(-P[1][0] * invDet);
    Pinv[1][1] = mod26(P[0][0] * invDet);

    /* K = C * P^-1 */

    K[0][0] = mod26(
        C[0][0] * Pinv[0][0] +
        C[0][1] * Pinv[1][0]);

    K[0][1] = mod26(
        C[0][0] * Pinv[0][1] +
        C[0][1] * Pinv[1][1]);

    K[1][0] = mod26(
        C[1][0] * Pinv[0][0] +
        C[1][1] * Pinv[1][0]);

    K[1][1] = mod26(
        C[1][0] * Pinv[0][1] +
        C[1][1] * Pinv[1][1]);

    printf("\nRecovered Hill Cipher Key:\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", K[i][j]);

        printf("\n");
    }

    return 0;
}
