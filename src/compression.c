#include "compression.h"

#include <stdio.h>  /* sprintf */
#include <string.h> /* strlen */

int compress(char *input, char *output) {
    int input_len = strlen(input);
    char count[INPUT_MAX_LEN];

    int i, j, repeat;
    j = 0;

    /* Traverse through the input string by each character. */
    for (i = 0; i < input_len; i++) {
        /* Copy the first occurrence of the new character. */
        output[j] = input[j];
        j++;

        /* Count the number of occurrences of the new characater. */
        repeat = 1;
        while ((i + 1 < input_len) && (input[i] == input[i + 1])) {
            repeat++;
            i++;
        }

        /* Store count in the count char array. */
        sprintf(count, "%d", repeat);

        /* Copy the contents of count into output. */
        int k;
        for (k = 0; *(count + k); k++, j++) {
            output[j] = count[k];
        }
    }

    /* Terminate the compressed string. */
    output[j] = '\0';

    printf("Input string: %s\n", input);
    printf("Compressed string: %s\n", output);

    return 0;
}

int decompress(const char *input, char *output) {
    return 0;
}
