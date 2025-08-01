// orion.c

#include "orion.h"

// Example symmetric key (this would be secret and shared ahead of time)
static const uint8_t secret_key[16] = {0x13, 0x57, 0x9B, 0xDF, 0x24, 0x68,
                                       0xAC, 0xF0, 0x11, 0x22, 0x33, 0x44,
                                       0xDE, 0xAD, 0xBE, 0xEF};

void ORION_Init(void) {
  // In real cases, set up encryption hardware or key schedules
}

// Dummy XOR encryption for demonstration (replace with AES or other in future)
int ORION_Encrypt(const uint8_t *input, size_t len, uint8_t *output,
                  size_t *out_len) {
  for (size_t i = 0; i < len; ++i)
    output[i] = input[i] ^ secret_key[i % sizeof(secret_key)];
  *out_len = len;
  return 0;
}

int ORION_Decrypt(const uint8_t *input, size_t len, uint8_t *output,
                  size_t *out_len) {
  // XOR is symmetric
  return ORION_Encrypt(input, len, output, out_len);
}
