#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "common.h"

/*******************************************************************************
 * PREPROCESSING DIRECTIVES
 ******************************************************************************/

/* TODO: Remove this */
#define MAX_LEN 300

/** The set of characters to choose from to denote an encrypted character. */
#define SYMBOLS "aBcDeFgHiJkLmNoPqRsTuVwXyZ012345"
#define SYMBOLS_LEN strlen(SYMBOLS)

/** The set of characters to choose from to denote the overflowed amount. */
#define OVERFLOWS "AbCdEfGh"
#define OVERFLOWS_LEN strlen(OVERFLOWS)

/*******************************************************************************
 * USER-DEFINED TYPES
 ******************************************************************************/

/*******************************************************************************
 * A struct that denotes the actual encrypted character and the number of
 * overflows for a character in a encrypted string. Refer to the encrypt(3) and
 * decrypt(3) functions to see how this structure is created and used.
 ******************************************************************************/
typedef struct encrypted {
    char encrypted;
    int overflows;
} encrypted_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 * Author: Ta-Seen & Hugh
 *
 * The main function of the encryption process responsible for encrypting the
 * given text. We use the given key to 'salt' the resulting encrypted output to
 * make it more unique (and thus make it harder for malicious users to decrypt
 * the text if they don't know the original key).
 *
 * The output string is expected to be twice as long as the input string.
 * Although this may seem inefficient, the given input is expected to have been
 * compressed.
 *
 * Inputs:
 *   - input    The unencrypted string to eventually encrypt.
 *   - key      The password to 'salt' the resulting encrypted output.
 *   - output   A pointer to write the resulting encrypted string to.
 *
 * Output:
 *   Returns 0 if the operation was successful, otherwise an error code defined
 *   by the error_code_t enum.
 ******************************************************************************/
int encrypt(const char *input, const char *key, char *output);

/*******************************************************************************
 * Author: Hugh & Ta-Seen
 *
 * The main function of the decryption process responsible for decrypting the
 * given text. This function will attempt to decrypt the given input text and
 * 'unsalt' it with the given key.
 *
 * This function will not verify if the given key is the correct password. This
 * is so malicious users will not know if the password they have entered was
 * incorrect. In the case that an incorrect key was given anyway, the
 * 'decrypted' string will output gibberish.
 *
 * Inputs:
 *   - input    The encrypted string to decrypt.
 *   - key      The original password used to salt the encrypted input.
 *   - output   A pointer to write the resulting decrypted string to.
 *
 * Outputs:
 *   Returns 0 if the operation was successful, otherwise an error code defined
 *   by the error_code_t enum.
 ******************************************************************************/
int decrypt(const char *input, const char *key, char *output);

#endif /* ENCRYPTION_H */
