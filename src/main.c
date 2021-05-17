/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 *
 * Lab Number: 03 4pm-6pm Monday
 * Group Number: 03
 *
 * Name and student ID:
 *
 *   - Hugh James Seagrave Hannan (13193204) [HH]
 *   - Mohammed Ta-Seen Islam (13215660) [TI]
 *   - Muhammad Haisam Atif (14065181) [MA]
 *   - Larissa Al Youssef (14267102) [LY]
 *   - Sumanyu Khemlani (13056092) [SK]
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
 * User-defined types
 ******************************************************************************/

enum {
    CHOICE_ENCRYPT = 1,
    CHOICE_DECRYPT,
    CHOICE_EXIT,
};

/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * Prints a user-friendly menu describing all the possible actions this program
 * can perform.
 */
void print_menu(void) {
    printf("1. Compress and encrypt text\n"
           "2. Decompress and decrypt text\n"
           "3. Exit the program\n");
}

/*******************************************************************************
 * Main function
 ******************************************************************************/

int main(void) {
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
            puts("Goodbye.");
            return 0;
        default:
            puts("Invalid choice. Please try again.");
            break;
        }

        /* Add a newline before the next menu */
        printf("\n");
    } while (choice != CHOICE_EXIT);

    return 0;
}

/*

    To test compress function
    char string[MAX_LENGTH];
    char sutput[MAX_LENGTH*2];

    printf("Enter string: ");
    scanf("[^\n]",string);

    int c = compress(string,sutput);


    char *input = "hello, world!";
    char *key = "asdfghjlicvbm";

    size_t input_len = strlen(input);
    char *output = (char *)malloc(input_len * 2);

    if (encrypt(input, key, output) == 0) {
        printf("'%s'\n", output);
    }

    free(output);

 */
