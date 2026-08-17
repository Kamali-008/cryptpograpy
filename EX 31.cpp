#include <stdio.h>
#include <stdint.h>

/* Left shift a 128-bit value by 1 bit */
void left_shift_128(uint8_t input[16], uint8_t output[16])
{
    int i;
    uint8_t carry = 0;

    for (i = 15; i >= 0; i--)
    {
        output[i] = (input[i] << 1) | carry;
        carry = (input[i] & 0x80) ? 1 : 0;
    }
}

/* Generate CMAC subkeys K1 and K2 */
void generate_subkeys(uint8_t L[16],
                      uint8_t K1[16],
                      uint8_t K2[16])
{
    int i;
    uint8_t Rb = 0x87;
    uint8_t msb;

    /* Generate K1 */
    msb = L[0] & 0x80;
    left_shift_128(L, K1);

    if (msb)
        K1[15] ^= Rb;

    /* Generate K2 */
    msb = K1[0] & 0x80;
    left_shift_128(K1, K2);

    if (msb)
        K2[15] ^= Rb;
}
void print_value(uint8_t value[16])
{
    int i;

    for (i = 0; i < 16; i++)
        printf("%02X", value[i]);

    printf("\n");
}

int main()
{
    uint8_t L[16] = {
        0x6B, 0xC1, 0xBE, 0xE2,
        0x2E, 0x40, 0x9F, 0x96,
        0xE9, 0x3D, 0x7E, 0x11,
        0x73, 0x93, 0x17, 0x2A
    };

    uint8_t K1[16];
    uint8_t K2[16];

    printf("Input L = ");
    print_value(L);

    generate_subkeys(L, K1, K2);

    printf("CMAC Subkey K1 = ");
    print_value(K1);

    printf("CMAC Subkey K2 = ");
    print_value(K2);

    printf("\nCMAC Constants:\n");
    printf("64-bit block  : Rb = 0x1B\n");
    printf("128-bit block : Rb = 0x87\n");

    return 0;
}
