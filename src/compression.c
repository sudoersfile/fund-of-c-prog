#include "compression.h"

#include <stdio.h>  /* printf, sprintf */
#include <string.h> /* strlen */

int compress(char *input_string, char *compressed_string) {
    int length = strlen(input_string);
    char count[INPUT_MAX_LEN];

    int i, j = 0, k, repeat;

    /* Traverse input_string one by one */
    for (i = 0; i < length; i++) {
        /* Copy the first occurrence of the new character */
        compressed_string[j++] = input_string[i];

        /* Count the number of occurrences of the new character */
        repeat = 1;
        while ((i + 1 < length) && (input_string[i] == input_string[i + 1])) {
            repeat++;
            i++;
        }

        /* Store count in a character array count[] */
        sprintf(count, "%d", repeat);

        /* Copy the count[] to compressed_string */
        for (k = 0; *(count + k); k++, j++) {
            compressed_string[j] = count[k];
        }
    }

    /* Terminate compressed_string */
    compressed_string[j] = '\0';

#if DEBUG_MODE
    printf("Input string: %s\n", input_string);
    printf("Compressed string: %s\n", compressed_string);
#endif

    return 0;
}

int decompress(const char *compressed_string, char *string) {
    int i = 0, j = 0, k, n;

    while (compressed_string[i]) {
        /* Because the form is the first character followed by the number, so
         * the first one is definitely a character, first assigned to another
         * array for subsequent operations.*/
        string[j] = compressed_string[i];

        /* Increment, start processing the next digit */
        i++;
        j++;
        n = 0;

        /* As long as it is a number, it will enter the loop statistics */
        while (compressed_string[i] >= '1' && compressed_string[i] <= '9') {
            n *= 10; /* for next digit */
            n += compressed_string[i] - '0';
            i++;
        }

        for (k = 0; k < n - 1; k++) {
            /* Because the uncompressed characters are already stored in the
             * array s1, only n-1 is left to be placed in s1 */
            string[j + k] = string[j - 1];
            /* Note that it must be n>0 because there may be consecutive
             * characters, which are not compressed. If you add n-1 to j, you
             * will reduce j. */
        }

        if (n > 0) {
            j += n - 1;
        }
    }

    /* After the processing ends, the last one is set to a null character. */
    string[j] = '\0';
    printf("Decompressed string: %s\n", string);

    return 0;
}
