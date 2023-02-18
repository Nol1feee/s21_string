#include "test_string.h"

START_TEST(s21_strerror_one) {
  ck_assert_int_eq(strcmp(s21_strerror(150), strerror(150)), 0);
}
END_TEST

START_TEST(s21_strerror_two) {
  ck_assert_int_eq(strcmp(s21_strerror(50), strerror(50)), 0);
}
END_TEST

START_TEST(s21_strerror_three) {
  ck_assert_int_eq(strcmp(s21_strerror(0), strerror(0)), 0);
}
END_TEST

START_TEST(s21_strerror_four) {
  ck_assert_int_eq(strcmp(s21_strerror('5'), strerror('5')), 0);
}
END_TEST

START_TEST(s21_strerror_five) {
  ck_assert_int_eq(strcmp(s21_strerror(-14875875), strerror(-14875875)), 0);
}
END_TEST

Suite *strerror_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strerror_one);
  tcase_add_test(tc_core, s21_strerror_two);
  tcase_add_test(tc_core, s21_strerror_three);
  tcase_add_test(tc_core, s21_strerror_four);
  tcase_add_test(tc_core, s21_strerror_five);
  suite_add_tcase(s, tc_core);

  return s;
}