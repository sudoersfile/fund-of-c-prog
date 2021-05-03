#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "common.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

/**
 * Encrypts the given text.
 *
 * @author Hugh Hannan
 * @author Ta-Seen Islam
 *
 * @param input     The null-terminated text to encrypt (of any size).
 * @param key       A unique key to salt the output.
 * @param output    A pre-allocated pointer to the destination of the final
 *                  encrypted string.
 *
 * @returns         0 if the encryption operation was successful, otherwise 1.
 */
int encrypt(const char *input, const char *key, const char *output);

/**
 * Decrypts the given encrypted value.
 *
 * @author Hugh Hannan
 * @author Ta-Seen Islam
 *
 * @param input     An encrypted text to be decrypted.
 * @param key       The salt key to un-salt the output.
 * @param output    A pointer to the destination of the decrypted text.
 *
 * @returns         0 if the decryption operation was successful, otherwise 1.
 */
int decrypt(const char *input, const char *key, char *output);

#endif /* ENCRYPTION_H */
