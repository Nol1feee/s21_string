#include "test_string.h"

START_TEST(s21_strcpy_one) {
  char temp_one[50] = "1";
  char temp_two[50] = "1";
  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

START_TEST(s21_strcpy_two) {
  char temp_one[50] = "";
  char temp_two[50] = "";
  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

START_TEST(s21_strcpy_three) {
  char temp_one[50] = " ";
  char temp_two[50] = " ";
  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

START_TEST(s21_strcpy_four) {
  char temp_one[50] = "\0 kek jk";
  char temp_two[50] = "\0 kek kj";
  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

START_TEST(s21_strcpy_five) {
  char temp_one[50] = "NULL kek \0 lol ";
  char temp_two[50] = "NULL kek \0 lol";
  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

START_TEST(s21_strcpy_six) {
  char temp_one[50] =
      "kek, ke, "
      " ";
  char temp_two[50] =
      "kek "
      " ke "
      " ";

  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

START_TEST(s21_strcpy_seven) {
  char temp_one[] = {"   "};
  char temp_two[] = {"   "};
  ck_assert_pstr_eq(strcpy(temp_one, temp_two), s21_strcpy(temp_one, temp_two));
}
END_TEST

Suite *strcpy_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strcpy_one);
  tcase_add_test(tc_core, s21_strcpy_two);
  tcase_add_test(tc_core, s21_strcpy_three);
  tcase_add_test(tc_core, s21_strcpy_four);
  tcase_add_test(tc_core, s21_strcpy_five);
  tcase_add_test(tc_core, s21_strcpy_six);
  tcase_add_test(tc_core, s21_strcpy_seven);
  suite_add_tcase(s, tc_core);

  return s;
}
