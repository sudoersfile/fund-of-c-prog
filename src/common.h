#ifndef COMMON_H
#define COMMON_H

#include "stdio.h" /* printf, puts */

/*******************************************************************************
 * LIST PREPROCESSING DIRECTIVES
 ******************************************************************************/

/** Determines if program is in DEBUG mode. */
#define DEBUG_MODE 1

/** The current version of this program. */
#define PROGRAM_VERSION "v1.0"

/** The maximum length of the input for compression and encryption. */
#define INPUT_MAX_LEN 300

/*******************************************************************************
 * USER-DEFINED TYPES
 ******************************************************************************/

/*******************************************************************************
 * A enumeration of all the possible errors that may be returned during the
 * compression and encryption processes.
 ******************************************************************************/
typedef enum error_code {
    ERROR_INSUFFICIENT_OUTPUT_CAPACITY = 100,
    ERROR_UNHANDLED_OVERFLOW = 200,
    ERROR_UNKNOWN = 900,
} error_code_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 * Author: Ta-Seen
 *
 * Prints a helpful error message suitable to be displayed to users.
 *
 * Inputs:
 *   - error_code   The error code to print a description of.
 *
 * Output:
 *   None
 ******************************************************************************/
void print_error_message(error_code_t error_code);

#endif /* COMMON_H */
