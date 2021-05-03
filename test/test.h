#ifndef TEST_H
#define TEST_H

#include <stdio.h>

typedef enum test_result {
    TEST_PASS,
    TEST_FAIL,
} test_result_t;

typedef struct test_case {
    const char *name;
    void (*func)(void);
} test_case_t;

#define TEST_SUITE const test_case_t test_suite[]

#define assert(expression)                                                     \
    do {                                                                       \
        if (expression) {                                                      \
            fprintf(                                                           \
                stderr,                                                        \
                "%s:%d (%s): Assertion failed",                                \
                __FILE__,                                                      \
                __LINE__,                                                      \
                __func__);                                                     \
            return TEST_FAIL;                                                  \
        }                                                                      \
    } while (0);

void run_test_suite(test_case_t test_suite[]) {
    int i;
    const char *name;
    void (*func)(void);
    for (i = 0; (test_suite[i].name && test_suite[i].func); i++) {
        name = test_suite[i].name;
        func = test_suite[i].func;
        puts(name);
    }
}

int main(void) {
    run_test_suite(&test_suite);
}

#endif /* TEST_H */
