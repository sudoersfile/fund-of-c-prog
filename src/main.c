/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 *
 * Lab Number: 03 (4pm-6pm Monday)
 * Group Number: 03
 *
 * Name and student ID:
 *
 *   - Hugh James Seagrave Hannan (13193204)
 *   - Mohammed Ta-Seen Islam (13215660)
 *   - Muhammad Haisam Atif (14065181)
 *   - Larissa Al Youssef (14267102)
 *   - Sumanyu Khemlani (13056092)
 *
 * Date of submission:
 *
 *   2021-05-28
 *
 * Please refer to `README.md` in the root of this project for compiling
 * instructions and a list of what we could and couldn't achieve.
 *
 ******************************************************************************/

#include "common.h"
#include "compression.h"
#include "encryption.h"

#include <stdio.h> /* printf, puts, scanf */

#if DEBUG_MODE
#include <stdlib.h> /* free, malloc */
#include <string.h> /* strlen */
#endif

/*******************************************************************************
 * USER-DEFINED TYPES
 ******************************************************************************/

/*******************************************************************************
 * A enumeration of all the possible choices in the menu.
 ******************************************************************************/
enum {
    CHOICE_ENCRYPT = 1,
    CHOICE_DECRYPT,
    CHOICE_EXIT,
};

/*******************************************************************************
 * FUNCTIONS
 ******************************************************************************/

/*******************************************************************************
 * Author: Ta-Seen
 *
 * Prints a user-friendly menu describing all the possible actions this program
 * can perform.
 *
 * Inputs:
 *   None
 *
 * Output:
 *   None
 ******************************************************************************/
void print_menu(void) {
    printf("1. Compress and encrypt text\n"
           "2. Decompress and decrypt text\n"
           "3. Exit the program\n");
}

/*******************************************************************************
 * Main function
 ******************************************************************************/
int main(void) {
/* Set DEBUG_MODE to 1 if you want to test your function directly.
 * Set DEBUG_MODE to 0 if you want to test what the user will see.
 * (No need to return 0 as it is at the very end of the main function.) */
#if DEBUG_MODE
    char *input = "This is a sample unencrypted text.";
    char *key = "my-password-123";

    size_t input_len = strlen(input);
    char *output = (char *)malloc(input_len * 2);

    int error_code = encrypt(input, key, output);
    if (error_code) {
        print_error_message(ERROR_UNHANDLED_OVERFLOW);
        return error_code;
    } else {
        printf("Encrypted text: %s\n", output);
    }

    free(output);
#else
    puts("\nEncryption Program " PROGRAM_VERSION "\n");

    int choice;
    do {
        print_menu();
        printf("\nEnter your choice> ");
        scanf("%d", &choice);

        switch (choice) {
        case CHOICE_ENCRYPT:
            puts("Sorry, encryption is not available at the moment.");
            break;
        case CHOICE_DECRYPT:
            puts("Sorry, decryption is not available at the moment.");
            break;
        case CHOICE_EXIT:
            /* Exit the program */
            puts("Goodbye.");
            return 0;
        default:
            puts("Invalid choice. Please try again.");
            break;
        }

        /* Add a newline before the next menu */
        printf("\n");
    } while (choice != CHOICE_EXIT);
#endif

    return 0;
}
