#include "test_string.h"

START_TEST(s21_strncat_one) {
  char temp_one[100] = "delim -> k <- delim ";
  char temp_two[100] = "delim -> k <- delim ";

  const char *res_s21_strncat = s21_strncat(temp_one, "hi, I'm strncat", 15);
  const char *res_orig_strncat = strncat(temp_two, "hi, I'm strncat", 15);

  ck_assert_str_eq(res_s21_strncat, res_orig_strncat);
}
END_TEST

START_TEST(s21_strncat_two) {
  char temp_one[100] = "kek \0 ckeck";
  char temp_two[100] = "kek \0 check";

  const char *res_s21_strncat = s21_strncat(temp_one, "hi, I'm strncat", 0);
  const char *res_orig_strncat = strncat(temp_two, "hi, I'm strncat", 0);

  ck_assert_str_eq(res_s21_strncat, res_orig_strncat);
}
END_TEST

START_TEST(s21_strncat_three) {
  char temp_one[100] = "NULL delim -> k <- delim ";
  char temp_two[100] = "NULL delim -> k <- delim ";

  const char *res_s21_strncat = s21_strncat(temp_one, "\0\0\0", 15);
  const char *res_orig_strncat = strncat(temp_two, "\0\0\0", 15);

  ck_assert_str_eq(res_s21_strncat, res_orig_strncat);
}
END_TEST

START_TEST(s21_strncat_four) {
  char temp_one[6] = "lol";
  char temp_two[6] = "lol";

  const char *res_s21_strncat = s21_strncat(temp_one, "k\0", 100);
  const char *res_orig_strncat = strncat(temp_two, "k\0", 100);

  ck_assert_str_eq(res_s21_strncat, res_orig_strncat);
}
END_TEST

START_TEST(s21_strncat_five) {
  char temp_one[154] = "lol";
  char temp_two[154] = "lol";

  const char *res_s21_strncat =
      s21_strncat(temp_one, "/////04908r9i-ripekwo;fllm\0\0", 10000000);
  const char *res_orig_strncat =
      strncat(temp_two, "/////04908r9i-ripekwo;fllm\0\0", 10000000);

  ck_assert_str_eq(res_s21_strncat, res_orig_strncat);
}
END_TEST

START_TEST(s21_strncat_six) {
  char temp_one[6] = "1";
  char temp_two[6] = "1";

  const char *res_s21_strncat = s21_strncat(temp_one, "kjqq", 4);
  const char *res_orig_strncat = strncat(temp_two, "kjqq", 4);

  ck_assert_str_eq(res_s21_strncat, res_orig_strncat);
}
END_TEST
Suite *strncat_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strncat_one);
  tcase_add_test(tc_core, s21_strncat_two);
  tcase_add_test(tc_core, s21_strncat_three);
  tcase_add_test(tc_core, s21_strncat_four);
  tcase_add_test(tc_core, s21_strncat_five);
  tcase_add_test(tc_core, s21_strncat_six);
  suite_add_tcase(s, tc_core);

  return s;
}