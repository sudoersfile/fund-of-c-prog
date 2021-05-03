/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 *
 * Lab Number: 03 4pm-6pm Monday
 * Group Number: 03
 *
 * Name and student ID:
 *
 *   - Hugh Hannan (13193204)
 *   - Mohammed Ta-Seen Islam (13215660)
 *   - Muhammad Haisam Atif (14065181)
 *   - Larissa Al Youssef (14267102)
 *   - Sumanyu Khemlani (13056092)
 *
 * Date of submission:
 *
 *   2021-XX-XX
 *
 * Please refer to `README.md` in the root of this project for compiling
 * instructions and a list of what we could and couldn't achieve.
 *
 ******************************************************************************/

#include "common.h"
#include "compression.h"
#include "encryption.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * User-defined types.
 ******************************************************************************/

enum {
    CHOICE_ENCRYPT = 1,
    CHOICE_DECRYPT,
    CHOICE_EXIT,
};

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

void print_menu(void);

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

void print_menu(void) {
    printf("1. Compress and encrypt text\n"
           "2. Decompress and decrypt text\n"
           "3. Exit the program\n");
}
