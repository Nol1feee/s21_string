#include "test_string.h"

START_TEST(s21_to_lower_one) {
  char str[][50] = {"kek LOL", "check", "123456", "kEk CHekc129;"};
  char res[][50] = {"kek lol", "check", "123456", "kek chekc129;"};
  for (int i = 0; i < 4; ++i) {
    ck_assert_str_eq(s21_to_lower(str[i]), res[i]);
  }
}
END_TEST

Suite *to_lower_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("to_lower");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_to_lower_one);
  suite_add_tcase(s, tc_core);

  return s;
}