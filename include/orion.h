// orion.h

#ifndef ORION_H
#define ORION_H

#include <stdint.h>
#include <stddef.h>

void ORION_Init(void);

// Encrypt plain data
int ORION_Encrypt(const uint8_t *input, size_t len, uint8_t *output, size_t *out_len);

// Decrypt cipher data
int ORION_Decrypt(const uint8_t *input, size_t len, uint8_t *output, size_t *out_len);

#endif // ORION_H
