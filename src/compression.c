#include "compression.h"

#include <stdio.h>  /* printf, sprintf */
#include <string.h> /* strlen */

#define BREAK '$'

int compress(const char *input_string, char *compressed_string) {
    int length = strlen(input_string);
    char count[INPUT_MAX_LEN];

    int i, j = 0, k, repeat;

    /* iterate through each letter */
    for (i = 0; i < length; i++) {

        if (input_string[i] == input_string[i + 1]) {

            compressed_string[j++] = BREAK;
            /* Copy the first occurrence of the new character */
            compressed_string[j++] = input_string[i];

            /* Count the number of occurrences of the new character */
            repeat = 1;

            while ((i + 1 < length) &&
                   (input_string[i] == input_string[i + 1])) {
                repeat++;
                i++;
            }
            /* Store repeat in a character array count[] */
            sprintf(count, "%d", repeat);
            /* Copy the count[] to compressed_string */
            for (k = 0; *(count + k); k++, j++) {
                compressed_string[j] = count[k];
            }
        } else {
            if (input_string[i] == BREAK) {
                compressed_string[j++] = input_string[i];
            } else if (input_string[i] >= '0' && input_string[i] <= '9') {
                compressed_string[j++] = BREAK;
            }
            compressed_string[j++] = input_string[i];
        }
    }

    /*terminating the compressed string */
    compressed_string[j] = '\0';

    printf("Compressed  : %s\n", compressed_string);

    return 0;
}

int decompress(const char *compressed_string, char *string) {

    int i = 0, j = 0, k, n;

    while (compressed_string[i]) {
        if (compressed_string[i] == BREAK) {
            i++;
            string[j] = compressed_string[i];

            /*Increment, start processing the next digit */
            i++;
            j++;
            n = 0;
            /*if the letter is a number, it will enter the loop */
            while (compressed_string[i] >= '0' && compressed_string[i] <= '9') {

                n *= 10; /* for next digit */
                n += compressed_string[i] - '0';
                i++;
            }
            for (k = 0; k < n - 1; k++) {
                string[j + k] = string[j - 1];
            }
            if (n > 0) {
                j += n - 1;
            }
        } else {
            string[j] = compressed_string[i];
            i++;
            j++;
        }
    }

    /*terminating the final string */
    string[j] = '\0';

    printf("Decompressed: %s\n", string);
    return 0;
}
