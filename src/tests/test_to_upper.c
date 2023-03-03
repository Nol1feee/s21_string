#include "test_string.h"

START_TEST(s21_to_upper_one) {
  char str[][50] = {"kek LOL", "check", "123456", "kEk CHekc129;"};
  char res[][50] = {"KEK LOL", "CHECK", "123456", "KEK CHEKC129;"};
  for (int i = 0; i < 4; ++i) {
    ck_assert_str_eq(s21_to_upper(str[i]), res[i]);
  }
}
END_TEST

Suite *to_upper_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("to_upper");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_to_upper_one);
  suite_add_tcase(s, tc_core);

  return s;
}