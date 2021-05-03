#include "test.h"

static test_result_t test_one_equals_one(void) {
    assert(1 == 1);
    return TEST_PASS;
}

static test_result_t test_one_not_equals_two(void) {
    assert(1 != 2);
    return TEST_PASS;
}

TEST_SUITE = {
    { "it finds that one equals one", test_one_equals_one },
    { "it finds that one doesn't equal to two", test_one_not_equals_two },
    { NULL, NULL }
};
