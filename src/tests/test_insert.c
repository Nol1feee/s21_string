#include "test_string.h"

START_TEST(s21_insert_one) {
  char to_change[50] = "delim -> k <- delim";
  char to_add[50] = " ";
  s21_size_t forward = 5;
  ck_assert_str_eq(s21_insert(to_change, to_add, forward),
                   "delim  -> k <- delim");
}
END_TEST

START_TEST(s21_insert_two) {
  char to_change[50] = "delim -> k <- delim";
  char to_add[50] = " ";
  s21_size_t forward = 100;
  ck_assert_pstr_eq(s21_insert(to_change, to_add, forward), s21_NULL);
}
END_TEST

START_TEST(s21_insert_three) {
  char to_change[50] = "delim -> k <- delim";
  char to_add[50] = " ";
  s21_size_t forward = -1;
  ck_assert_pstr_eq(s21_insert(to_change, to_add, forward), s21_NULL);
}
END_TEST

START_TEST(s21_insert_four) {
  char to_change[50] = " .         delim -> k <- delim";
  char to_add[50] = " kek_ya tyt";
  s21_size_t forward = 20;
  ck_assert_str_eq(s21_insert(to_change, to_add, forward),
                   " .         delim ->  kek_ya tytk <- delim");
}
END_TEST

START_TEST(s21_insert_five) {
  char to_change[55] = "/0 NULL .         delim -> k <- delim";
  char to_add[55] = " kek_ya tyt";
  s21_size_t forward = 20;
  ck_assert_str_eq(s21_insert(to_change, to_add, forward),
                   "/0 NULL .         de kek_ya tytlim -> k <- delim");
}
END_TEST

START_TEST(s21_insert_six) {
  char to_change[55] = "\0 NULL .         delim -> k <- delim";
  char to_add[55] = " kek_ya tyt";
  s21_size_t forward = 20;
  ck_assert_pstr_eq(s21_insert(to_change, to_add, forward), s21_NULL);
}
END_TEST

Suite *insert_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("insert");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_insert_one);
  tcase_add_test(tc_core, s21_insert_two);
  tcase_add_test(tc_core, s21_insert_three);
  tcase_add_test(tc_core, s21_insert_four);
  tcase_add_test(tc_core, s21_insert_five);
  tcase_add_test(tc_core, s21_insert_six);
  suite_add_tcase(s, tc_core);

  return s;
}