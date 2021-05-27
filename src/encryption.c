#include "encryption.h"

#include <stdio.h>  /* printf */
#include <stdlib.h> /* size_t */
#include <string.h> /* strlen */

/*******************************************************************************
 * Author: Ta-Seen
 *
 * The main mechanism of the encryption algorithm.
 *
 * Inputs:
 *   - input    The unencrypted string to eventually encrypt.
 *   - key      The password to 'salt' the resulting encrypted output.
 *   - output   The resulting encrypted output.
 *
 * Output:
 *   Returns 0 if the operation was successful, otherwise 1.
 ******************************************************************************/
int encrypt_inner(const char *input, const char *key, encrypted_t *output) {
    /* Local variables for iterating over the input and key. */
    int i, k;
    /* Other local variables. */
    int char_sum, sym_index, overflows;

    /* The main process of the encryption algorithm. */
    for (i = 0, k = 0; input[i] != '\0'; i++, k++) {
        /* Start over the key if we're already at the end of the key */
        if (key[k] == '\0') {
            k = 0;
        }

        /* Calculating the new encrypted character from the SYMBOLS set as well
         * as the number of times the new character had overflowed the set. */
        char_sum = (int)input[i] + (int)key[k];
        sym_index = char_sum % SYMBOLS_LEN;
        overflows = char_sum / SYMBOLS_LEN;

        output[i].encrypted = SYMBOLS[sym_index];
        output[i].overflows = overflows;
    }

    return 0;
}

int encrypt(const char *input, const char *key, char *output) {
    /* We can assume that all strings end with the null terminator ('\0'). */
    size_t input_len = strlen(input);

    /* The resulting array of encrypted_t values. */
    encrypted_t encrypted_output[input_len];
    encrypt_inner(input, key, encrypted_output);

    /* Iterating over each character of the input string. */
    size_t idx;
    for (idx = 0; idx < input_len; idx++) {
        size_t output_idx = idx * 2;
        output[output_idx] = encrypted_output[idx].encrypted;

        /* NOTE: 8 seems to be the highest number of overflows */
        size_t overflows = encrypted_output[idx].overflows;

        if (overflows >= OVERFLOWS_LEN) {
#if DEBUG_MODE
            puts("ERROR: 'overflows' is not smaller than the length of the"
                 "'OVERFLOWS' set.");
#endif
            /* We return from here because this is a logical error. */
            return ERROR_UNHANDLED_OVERFLOW;
        }

        output[output_idx + 1] = OVERFLOWS[overflows];
    }

    return 0;
}

int decrypt(const char *input, const char *key, char *output) {
#if 1
    /* Local incremental variables */
    int i, j;
    /* Local variables */
    int decrypted_sum;
    encrypted_t encrypted_msg[MAX_LEN];

    /* Decryption Function */
    for (i = 0; input[i] != '\0'; i++, i++) {
        if (input[i + 1] == '*') {
            encrypted_msg[i].encrypted = input[i];
            encrypted_msg[i].overflows = '0';
        } else if (input[i + 1] == '~') {
            encrypted_msg[i].encrypted = input[i];
            encrypted_msg[i].overflows = '1';
        } else if (input[i + 1] == '@') {
            encrypted_msg[i].encrypted = input[i];
            encrypted_msg[i].overflows = '2';
        } else if (input[i + 1] == '$') {
            encrypted_msg[i].encrypted = input[i];
            encrypted_msg[i].overflows = '3';
        } else if (input[i + 1] == '%') {
            encrypted_msg[i].encrypted = input[i];
            encrypted_msg[i].overflows = '4';
        } else if (input[i + 1] == '!') {
            encrypted_msg[i].encrypted = input[i];
            encrypted_msg[i].overflows = '5';
        } else {
            printf("something has gone wrong with decryption");
            break;
        }
    }

    for (j = 0; j < i; j++) {
        decrypted_sum = (int)encrypted_msg[j].encrypted + (int)key[j] +
                        ((int)encrypted_msg[j].overflows * (int)SYMBOLS_LEN);
        output[j] = (char)decrypted_sum;
    }
    printf("output: %s", output);
#endif

    return 0;
}
