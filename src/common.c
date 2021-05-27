#include "common.h"

void print_error_message(error_code_t error_code) {
    puts("Oops! Something wrong has happened.");
    puts("Please contact the development team with the following error code:");
    puts("");

    switch (error_code) {
    case ERROR_INSUFFICIENT_OUTPUT_CAPACITY:
        printf("  %d ERROR_INSUFFICIENT_OUTPUT_CAPACITY\n", error_code);
        break;
    case ERROR_UNHANDLED_OVERFLOW:
        printf("  %d ERROR_UNHANDLED_OVERFLOW\n", error_code);
        break;
    case ERROR_UNKNOWN: /* FALLTHROUGH */
    default:
        printf("  %d ERROR_UNKNOWN\n", error_code);
        break;
    }

    puts("");
    puts("We apologise for any inconvenience this may have caused.");
}
