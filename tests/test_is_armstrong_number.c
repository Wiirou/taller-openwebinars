/* Includes necesarios para el funcionamiento de cmocka */
# include <stddef.h>
# include <setjmp.h>
# include <stdarg.h>
# include <cmocka.h>

# include "../armstrong.h"

/* tests */

void test_is_armstrong_number_returns_true(void **state)
{
    (void) state; /* unused */
    int ret;

    ret = is_armstrong_number(6);
    assert_int_equal(1, ret);
}

void test_is_armstrong_number_returns_false(void **state)
{
    (void) state; /* unused */
    int ret;

    ret = is_armstrong_number(100);
    assert_int_equal(0, ret);
}

const struct CMUnitTest is_armstrong_number_tests[] = {
    cmocka_unit_test(test_is_armstrong_number_returns_true),
    cmocka_unit_test(test_is_armstrong_number_returns_false),
};


int main(void)
{
    return cmocka_run_group_tests(is_armstrong_number_tests, NULL, NULL);
}

