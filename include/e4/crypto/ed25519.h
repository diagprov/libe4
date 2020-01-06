#ifndef ED25519_H
#define ED25519_H
#ifdef __cplusplus
extern "C" {
#endif

#include "e4/stdint.h"

void ed25519_sign(unsigned char *signature, const unsigned char *message, size_t message_len, const unsigned char *public_key, const unsigned char *private_key);
int ed25519_verify(const unsigned char *signature, const unsigned char *message, size_t message_len, const unsigned char *public_key);
void ed25519_add_scalar(unsigned char *public_key, unsigned char *private_key, const unsigned char *scalar);

#ifdef __cplusplus
}
#endif

#endif
