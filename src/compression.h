#ifndef COMPRESSION_H
#define COMPRESSION_H

#include "common.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 * Author: Sumanyu Khemlani
 * Compresses a string using Run Length Encoding
 * Inputs:
 * Output:
 ******************************************************************************/
int compress(const char *input, char *output);

/*******************************************************************************
 * Author: Muhammad Atif & Larissa Al Youssef
 * Decompresses a string
 * Inputs:
 * Output:
 ******************************************************************************/
int decompress(const char *input, char *output);

#endif /* COMPRESSION_H */
