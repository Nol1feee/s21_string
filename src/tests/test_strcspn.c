#include "test_string.h"

START_TEST(s21_strcspn_one) {
  char temp[100] = "delim -> k <- delim ";
  char temp_two[100] = "delim kek check";
  ck_assert_int_eq(s21_strcspn(temp, temp_two), strcspn(temp, temp_two));
}
END_TEST

Suite *strcspn_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strcspn_one);
  //   tcase_add_test(tc_core, s21_strtok_two);
  //    tcase_add_test(tc_core, s21_strtok_three);
  //    tcase_add_test(tc_core, s21_strtok_four);
  suite_add_tcase(s, tc_core);

  return s;
}