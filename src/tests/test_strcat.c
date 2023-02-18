#include "test_string.h"

START_TEST(s21_strcat_one) {
  char temp_one[100] = "delim -> k <- delim ";
  char temp_two[100] = "delim -> k <- delim ";

  const char *res_s21_strcat = s21_strcat(temp_one, "hi, I'm strncat");
  const char *res_orig_strcat = strcat(temp_two, "hi, I'm strncat");

  ck_assert_str_eq(res_s21_strcat, res_orig_strcat);
}
END_TEST

START_TEST(s21_strcat_two) {
  char temp_one[100] = "kek \0 ckeck";
  char temp_two[100] = "kek \0 check";

  const char *res_s21_strcat = s21_strcat(temp_one, "hi, I'm strncat");
  const char *res_orig_strcat = strcat(temp_two, "hi, I'm strncat");

  ck_assert_str_eq(res_s21_strcat, res_orig_strcat);
}
END_TEST

START_TEST(s21_strcat_three) {
  char temp_one[100] = "NULL delim -> k <- delim ";
  char temp_two[100] = "NULL delim -> k <- delim ";

  const char *res_s21_strcat = s21_strcat(temp_one, "\0\0\0");
  const char *res_orig_strcat = strcat(temp_two, "\0\0\0");

  ck_assert_str_eq(res_s21_strcat, res_orig_strcat);
}
END_TEST

START_TEST(s21_strcat_four) {
  char temp_one[6] = "lol";
  char temp_two[6] = "lol";

  const char *res_s21_strcat = s21_strcat(temp_one, "k\0");
  const char *res_orig_strcat = strcat(temp_two, "k\0");

  ck_assert_str_eq(res_s21_strcat, res_orig_strcat);
}
END_TEST

START_TEST(s21_strcat_five) {
  char temp_one[154] = "lol";
  char temp_two[154] = "lol";

  const char *res_s21_strcat =
      s21_strcat(temp_one, "/////04908r9i-ripekwo;fllm\0\0");
  const char *res_orig_strcat =
      strcat(temp_two, "/////04908r9i-ripekwo;fllm\0\0");

  ck_assert_str_eq(res_s21_strcat, res_orig_strcat);
}
END_TEST

START_TEST(s21_strcat_six) {
  char temp_one[6] = "1";
  char temp_two[6] = "1";

  const char *res_s21_strcat = s21_strcat(temp_one, "kjqq");
  const char *res_orig_strcat = strcat(temp_two, "kjqq");

  ck_assert_str_eq(res_s21_strcat, res_orig_strcat);
}
END_TEST

Suite *strcat_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strcat_one);
  tcase_add_test(tc_core, s21_strcat_two);
  tcase_add_test(tc_core, s21_strcat_three);
  tcase_add_test(tc_core, s21_strcat_four);
  tcase_add_test(tc_core, s21_strcat_five);
  tcase_add_test(tc_core, s21_strcat_six);
  suite_add_tcase(s, tc_core);

  return s;
}