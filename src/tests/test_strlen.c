#include "test_string.h"

START_TEST(s21_strlen_test) {
    char temp[] = "privet, eto nash pervii test";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

Suite *test_strlen(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("string test");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strlen_test);
    suite_add_tcase(s, tc_core);

    return s;
}