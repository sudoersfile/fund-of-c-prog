#ifndef COMPRESSION_H
#define COMPRESSION_H

#include "common.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

/**
 * @brief           Compresses a string using the Run-Length Encoding algorithm.
 * @author          MA & SK
 *
 * @param input     The text to compress.
 * @param output    The destination of the final compressed output.
 *
 * @returns         0 if the encryption operation was successful, otherwise 1.
 */
int compress(char *input, char *output);

/**
 * @brief           Decompresses the given string.
 * @author          MA & SK
 *
 * @param input     The text to decompress.
 * @param output    The destination of the final decompressed output.
 *
 * @returns         0 if the encryption operation was successful, otherwise 1.
 */
int decompress(const char *input, char *output);

#endif /* COMPRESSION_H */
