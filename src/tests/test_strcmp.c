#include "test_string.h"

START_TEST(s21_strcmp_one) {
    char str1[50] = "1";
    char str2[50] = "1";
    ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

Suite *strcmp_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strcmp");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strcmp_one);
//   tcase_add_test(tc_core, s21_strtok_two);
//    tcase_add_test(tc_core, s21_strtok_three);
//    tcase_add_test(tc_core, s21_strtok_four);
   suite_add_tcase(s, tc_core);

    return s;
}