#include "test_string.h"

START_TEST(s21_strncmp_one) {
    char str1[50] = "1";
    char str2[50] = "1";
    ck_assert_int_eq(strncmp(str1, str2, 10), s21_strncmp(str1, str2, 10));
}
END_TEST

Suite *strncmp_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strncmp");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strncmp_one);
//   tcase_add_test(tc_core, s21_strtok_two);
//    tcase_add_test(tc_core, s21_strtok_three);
//    tcase_add_test(tc_core, s21_strtok_four);
   suite_add_tcase(s, tc_core);

    return s;
}