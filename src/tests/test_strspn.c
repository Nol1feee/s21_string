#include "test_string.h"

START_TEST(s21_strspn_one) {
  char temp[100] = "delim -> k <- delim ";
  char temp_two[100] = "delim kek check";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

START_TEST(s21_strspn_two) {
  char temp[100] = "delim ";
  char temp_two[100] = "delim ";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

START_TEST(s21_strspn_three) {
  char temp[100] = "elim -> k <- delim ";
  char temp_two[100] = "delim kek check";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

START_TEST(s21_strspn_four) {
  char temp[100] = "ogo   ";
  char temp_two[100] = "net,poka";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

START_TEST(s21_strspn_five) {
  char temp[100] = "\0 kek";
  char temp_two[100] = "\0 kek";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

START_TEST(s21_strspn_six) {
  char temp[100] =
      "  "
      "  ";
  char temp_two[100] =
      "  "
      "  "
      " ";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

START_TEST(s21_strspn_seven) {
  char temp[100] = "delim -> k <- delim ";
  //    char temp_two[100] = "delim kek check";
  ck_assert_int_eq(s21_strspn(temp, ""), strspn(temp, ""));
}
END_TEST

START_TEST(s21_strspn_eight) {
  char temp[100] =
      "''  "
      " ";
  char temp_two[100] =
      "''  "
      " ";
  ck_assert_int_eq(s21_strspn(temp, temp_two), strspn(temp, temp_two));
}
END_TEST

Suite *strspn_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strspn_one);
  tcase_add_test(tc_core, s21_strspn_two);
  tcase_add_test(tc_core, s21_strspn_three);
  tcase_add_test(tc_core, s21_strspn_four);
  tcase_add_test(tc_core, s21_strspn_five);
  tcase_add_test(tc_core, s21_strspn_six);
  tcase_add_test(tc_core, s21_strspn_seven);
  tcase_add_test(tc_core, s21_strspn_eight);
  suite_add_tcase(s, tc_core);

  return s;
}