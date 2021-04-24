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
 *   - Mouhammad Haisam Atif (14065181)
 *   - Larissa Al Youssef (14267102)
 *   - Sumanyu Khemlani (13056092)
 *
 * Date of submission:
 *
 *   2021-XX-XX
 *
 * Compiling instructions:
 *
 *   To build, run and test the program, open the terminal and type in one of
 *   the following commands:
 *
 *       $ make         # Compile the program
 *       $ make run     # Compile and run the program
 *       $ make test    # Test the program
 *
 *   As you can tell, this program uses `make` to compile the program. Make sure
 *   sure have it installed if you want to compile it on your own computer.
 *
 * A brief statement on what you could achieve (less than 50 words):
 *
 *   Before next week we need to write an outline describing what we plan to do
 *   and how we plan to do it. We also need to write out all the main functions
 *   we plain to implament into our program as well as more or less finish one
 *   or two of them.
 *
 * A brief statement on what you could NOT achieve (less than 50 words):
 *
 *   TODO
 *
 * Refer to `README.md` for more information about this program in general.
 *
 ******************************************************************************/

/*******************************************************************************
 * Text encryption, decryption and compression program!
 *
 * References:
 *
 * http://www.trytoprogram.com/c-examples/c-program-to-encrypt-and-decrypt-string
 * https://en.wikipedia.org/wiki/Salt_(cryptography)
 * http://rosettacode.org/wiki/Run-length_encoding#C
 * https://www.geeksforgeeks.org/rsa-algorithm-cryptography
 *
 ******************************************************************************/

#include "encrypter.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * Main function
 ******************************************************************************/
int main(void) {
    print_message("Hello, world!");
    return 0;
}
