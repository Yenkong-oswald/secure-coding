#include <iostream>
#include <openssl/aes.h>
#include <cstring>

int main() {
    unsigned char key[16] = "0123456789ABCDEF";
    unsigned char iv[AES_BLOCK_SIZE] = "initVector123456";
    unsigned char input[] = "OpenAI_AES_Test!";
    unsigned char enc_out[128] = {0};
    unsigned char dec_out[128] = {0};

    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_set_decrypt_key(key, 128, &dec_key);

    // CBC mode
    AES_cbc_encrypt(input, enc_out, sizeof(input), &enc_key, iv, AES_ENCRYPT);

    std::cout << "Encrypted: ";
    for (size_t i = 0; i < sizeof(input); ++i)
        printf("%02X ", enc_out[i]);
    std::cout << "\n";

    // Reset IV and decrypt
    memcpy(iv, "initVector123456", AES_BLOCK_SIZE);
    AES_cbc_encrypt(enc_out, dec_out, sizeof(input), &dec_key, iv, AES_DECRYPT);
    std::cout << "Decrypted: " << dec_out << "\n";

    return 0;
}

