#include <stdio.h>

int main()
{
    printf("Playfair Cipher Key Analysis\n");
    printf("----------------------------\n");

    printf("a) Total possible keys (ignoring equivalent keys):\n");
    printf("   = 25!\n");
    printf("   ˜ 2^84\n\n");

    printf("b) Effectively unique keys (considering equivalent keys):\n");
    printf("   = 25! / 2\n");
    printf("   ˜ 2^83\n");

    return 0;
}
