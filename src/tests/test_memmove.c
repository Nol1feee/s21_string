#include "test_string.h"

START_TEST(s21_memmove_one) {
  char dst[100] = "delim -> k <- delim ";
  char src[100] = "delim kek";

  ck_assert_pstr_eq(s21_memmove(dst, src, 50), memmove(dst, src, 50));
}
END_TEST

START_TEST(s21_memmove_two) {
  char dst[20] = "delim";
  char src[20] = "delim";

  ck_assert_pstr_eq(s21_memmove(dst, src, 20), memmove(dst, src, 20));
}
END_TEST

START_TEST(s21_memmove_three) {
  char dst[20] = "delim";
  char src[20] = "delim";

  ck_assert_pstr_eq(s21_memmove(dst, src, 0), memmove(dst, src, 0));
}
END_TEST

START_TEST(s21_memmove_four) {
  char dst[20] = "delim";
  char src[5] = "";

  ck_assert_pstr_eq(s21_memmove(dst, src, 5), memmove(dst, src, 5));
}
END_TEST

START_TEST(s21_memmove_five) {
  char dst[20] = "";
  char src[9] = "src";

  ck_assert_pstr_eq(s21_memmove(dst, src, 9), memmove(dst, src, 9));
}
END_TEST

START_TEST(s21_memmove_six) {
  char dst[20] = "";
  char src[11] = "src";

  ck_assert_pstr_eq(s21_memmove(dst, src, 0), memmove(dst, src, 0));
}
END_TEST

START_TEST(s21_memmove_seven) {
  char dst[20] = "   ";
  char src[20] = "/0";

  ck_assert_pstr_eq(s21_memmove(dst, src, 20), memmove(dst, src, 20));
}
END_TEST

START_TEST(s21_memmove_eight) {
  char dst[20] = "\0   ";
  char src[4] = "\0";

  ck_assert_pstr_eq(s21_memmove(dst, src, 4), memmove(dst, src, 4));
}
END_TEST

START_TEST(s21_memmove_nine) {
  char dst[20] = "1112223333   ";
  char src[] = "111222";

  ck_assert_pstr_eq(s21_memmove(dst, src, 5), memmove(dst, src, 5));
}
END_TEST

START_TEST(s21_memmove_ten) {
  char dst[20] = "123456789";

  ck_assert_pstr_eq(s21_memmove(&dst[3], &dst[5], 2),
                    memmove(&dst[3], &dst[5], 2));
}
END_TEST

Suite *memmove_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memmove");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_memmove_one);
  tcase_add_test(tc_core, s21_memmove_two);
  tcase_add_test(tc_core, s21_memmove_three);
  tcase_add_test(tc_core, s21_memmove_four);
  tcase_add_test(tc_core, s21_memmove_five);
  tcase_add_test(tc_core, s21_memmove_six);
  tcase_add_test(tc_core, s21_memmove_seven);
  tcase_add_test(tc_core, s21_memmove_eight);
  tcase_add_test(tc_core, s21_memmove_nine);
  tcase_add_test(tc_core, s21_memmove_ten);
  suite_add_tcase(s, tc_core);

  return s;
}