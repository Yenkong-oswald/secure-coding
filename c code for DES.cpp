#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};
    DES_key_schedule schedule;
    DES_set_key_checked(&key, &schedule);

    unsigned char input[] = "OpenAI_DES_Test";
    unsigned char output[64] = {0};
    unsigned char decrypted[64] = {0};

    // Pad to 8-byte multiple for DES
    int len = ((strlen((char*)input) + 7) / 8) * 8;

    DES_cblock ivec = {0};
    DES_ncbc_encrypt(input, output, len, &schedule, &ivec, DES_ENCRYPT);
    printf("Encrypted: ");
    for (int i = 0; i < len; i++) printf("%02X ", output[i]);
    printf("\n");

    // Decrypt
    memset(ivec, 0, sizeof(ivec));
    DES_ncbc_encrypt(output, decrypted, len, &schedule, &ivec, DES_DECRYPT);
    decrypted[len] = '\0';
    printf("Decrypted: %s\n", decrypted);
    return 0;
}

