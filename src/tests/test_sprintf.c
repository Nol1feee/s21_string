#include "test_string.h"

START_TEST(s21_sprintf_one) {
  char buf[100];

  ck_assert_int_eq(s21_sprintf(buf, "asdfggsdd sad %s %6.5d %6.5i %c %lf %%",
                               "ssss", 6, 5, 'c', 6.5),
                   sprintf(buf, "asdfggsdd sad %s %6.5d %6.5i %c %lf %%",
                           "ssss", 6, 5, 'c', 6.5));
}
END_TEST

START_TEST(s21_sprintf_2) {
  char buf[100];

  ck_assert_int_eq(
      s21_sprintf(buf, "asdfggsdd sad %s %ld %hi %hd %ld %f %lf %u", "ssss",
                  2147L, 4, 5, 6555L, 7.7, 6.5, 6),
      sprintf(buf, "asdfggsdd sad %s %ld %hi %hd %ld %f %lf %u", "ssss", 2147L,
              4, 5, 6555L, 7.7, 6.5, 6));
}
END_TEST

START_TEST(s21_sprintf_3) {
  char buf[100];

  ck_assert_int_eq(
      s21_sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5),
      sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5));
}
END_TEST
START_TEST(s21_sprintf_4) {
  char buf[100];

  ck_assert_int_eq(
      s21_sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5),
      sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5));
}
END_TEST
START_TEST(s21_sprintf_5) {
  char buf[100];

  ck_assert_int_eq(
      s21_sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5),
      sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5));
}
END_TEST
START_TEST(s21_sprintf_6) {
  char buf[100];

  ck_assert_int_eq(
      s21_sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5),
      sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5));
}
END_TEST
START_TEST(s21_sprintf_7) {
  char buf[100];

  ck_assert_int_eq(
      s21_sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5),
      sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5));
}
END_TEST
Suite *sprintf_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_sprintf_one);
  tcase_add_test(tc_core, s21_sprintf_2);
  tcase_add_test(tc_core, s21_sprintf_3);
  tcase_add_test(tc_core, s21_sprintf_4);
  tcase_add_test(tc_core, s21_sprintf_5);
  tcase_add_test(tc_core, s21_sprintf_6);
  tcase_add_test(tc_core, s21_sprintf_7);

  suite_add_tcase(s, tc_core);

  return s;
}