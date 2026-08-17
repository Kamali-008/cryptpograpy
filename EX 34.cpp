#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void printBlock(const unsigned char *block)
{
    int i;
    for (i = 0; i < BLOCK_SIZE; i++)
        printf("%02X ", block[i]);
    printf("\n");
}

/* Simple XOR-based block cipher for demonstration */
void encryptBlock(unsigned char *input,
                  unsigned char *key,
                  unsigned char *output)
{
    int i;

    for (i = 0; i < BLOCK_SIZE; i++)
        output[i] = input[i] ^ key[i];
}

/* 1 followed by zeros padding */
int addPadding(unsigned char *data, int length)
{
    int padding = BLOCK_SIZE - (length % BLOCK_SIZE);

    if (padding == 0)
        padding = BLOCK_SIZE;

    data[length] = 0x80;

    for (int i = 1; i < padding; i++)
        data[length + i] = 0x00;

    return length + padding;
}

/* ECB Mode */
void ECB(unsigned char *data, int length, unsigned char *key)
{
    unsigned char output[BLOCK_SIZE];

    printf("\nECB Mode:\n");

    for (int i = 0; i < length; i += BLOCK_SIZE)
    {
        encryptBlock(&data[i], key, output);
        printBlock(output);
    }
}

/* CBC Mode */
void CBC(unsigned char *data, int length,
         unsigned char *key, unsigned char *iv)
{
    unsigned char block[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];

    printf("\nCBC Mode:\n");

    for (int i = 0; i < length; i += BLOCK_SIZE)
    {
        for (int j = 0; j < BLOCK_SIZE; j++)
            block[j] = data[i + j] ^ iv[j];

        encryptBlock(block, key, output);

        printBlock(output);

        for (int j = 0; j < BLOCK_SIZE; j++)
            iv[j] = output[j];
    }
}

/* CFB Mode */
void CFB(unsigned char *data, int length,
         unsigned char *key, unsigned char *iv)
{
    unsigned char stream[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];

    printf("\nCFB Mode:\n");

    for (int i = 0; i < length; i += BLOCK_SIZE)
    {
        encryptBlock(iv, key, stream);

        for (int j = 0; j < BLOCK_SIZE; j++)
            output[j] = data[i + j] ^ stream[j];

        printBlock(output);

        for (int j = 0; j < BLOCK_SIZE; j++)
            iv[j] = output[j];
    }
}

int main()
{
    unsigned char data[100];
    unsigned char key[BLOCK_SIZE] =
        { 'K','E','Y','1','2','3','4','5' };

    unsigned char iv1[BLOCK_SIZE] =
        { 0,1,2,3,4,5,6,7 };

    unsigned char iv2[BLOCK_SIZE] =
        { 0,1,2,3,4,5,6,7 };

    int length;

    printf("Enter plaintext: ");
    fgets((char *)data, sizeof(data), stdin);

    length = strlen((char *)data);

    if (data[length - 1] == '\n')
        data[--length] = '\0';

    printf("\nOriginal length = %d", length);

    length = addPadding(data, length);

    printf("\nPadded length = %d\n", length);

    ECB(data, length, key);

    CBC(data, length, key, iv1);

    CFB(data, length, key, iv2);

    return 0;
}
