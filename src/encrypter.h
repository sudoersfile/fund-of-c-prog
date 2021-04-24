#ifndef ENCRYPTER_H
#define ENCRYPTER_H

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

/*******************************************************************************
 * An example function for demonstration purposes that prints a given message to
 * stdout.
 *
 * Inputs:
 *   message - The message to print to the terminal via stdout.
 ******************************************************************************/
void print_message(const char *message);

int encrypt(const char *input, const char *salt, char *output);
int decrypt(const char *input, const char *salt, char *output);

#endif /* ENCRYPTER_H */
