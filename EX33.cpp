#include <stdio.h>
#include <stdint.h>

uint64_t initial_permutation(uint64_t block)
{
    uint64_t result = 0;

    int IP[64] = {
        58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7
    };

    for (int i = 0; i < 64; i++)
    {
        uint64_t bit = (block >> (64 - IP[i])) & 1ULL;
        result |= bit << (63 - i);
    }

    return result;
}

uint64_t final_permutation(uint64_t block)
{
    uint64_t result = 0;

    int FP[64] = {
        40,8,48,16,56,24,64,32,
        39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,
        37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,
        35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,
        33,1,41,9,49,17,57,25
    };

    for (int i = 0; i < 64; i++)
    {
        uint64_t bit = (block >> (64 - FP[i])) & 1ULL;
        result |= bit << (63 - i);
    }

    return result;
}

/* Simplified DES Feistel round */
uint32_t feistel(uint32_t right, uint32_t key)
{
    right ^= key;

    right = (right << 1) | (right >> 31);

    return right;
}

/* Simplified DES demonstration */
uint64_t des_encrypt(uint64_t plaintext, uint64_t key)
{
    uint64_t block;
    uint32_t left, right;
    uint32_t round_key;

    block = initial_permutation(plaintext);

    left = (uint32_t)(block >> 32);
    right = (uint32_t)(block & 0xFFFFFFFF);

    round_key = (uint32_t)(key & 0xFFFFFFFF);

    for (int i = 0; i < 16; i++)
    {
        uint32_t temp;

        temp = right;
        right = left ^ feistel(right, round_key);
        left = temp;
    }

    block = ((uint64_t)right << 32) | left;

    return final_permutation(block);
}

uint64_t des_decrypt(uint64_t ciphertext, uint64_t key)
{
   
    return des_encrypt(ciphertext, key);
}

int main()
{
    uint64_t plaintext;
    uint64_t key;
    uint64_t ciphertext;
    uint64_t decrypted;

    printf("Enter 64-bit plaintext in hexadecimal: ");
    scanf("%llx", &plaintext);

    printf("Enter 64-bit DES key in hexadecimal: ");
    scanf("%llx", &key);

    ciphertext = des_encrypt(plaintext, key);

    printf("\nPlaintext  : %016llX\n", plaintext);
    printf("Key        : %016llX\n", key);
    printf("Ciphertext : %016llX\n", ciphertext);

    decrypted = des_decrypt(ciphertext, key);

    printf("Decrypted  : %016llX\n", decrypted);

    return 0;
}
