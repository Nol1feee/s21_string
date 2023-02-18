#include "test_string.h"

START_TEST(s21_trim_one) {
  char str[][50] = {"kek LOL",     "check",       "123456",
                    "eee eee EEE", "eee eee EEE", "kkk ccc ckckck"};
  char del[][50] = {"kek", "ch", "11111", "E", "e", "c k "};
  char res[][50] = {" LOL", "eck", "23456", "eee eee ", " eee EEE", ""};
  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_trim(str[i], del[i]), res[i]);
  }
}
END_TEST

Suite *trim_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("trim");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_trim_one);
  suite_add_tcase(s, tc_core);

  return s;
}