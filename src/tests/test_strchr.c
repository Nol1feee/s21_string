#include "test_string.h"

START_TEST(s21_strchr_one) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_str_eq(s21_strchr(temp, '1'), strchr(temp, '1'));
}
END_TEST

START_TEST(s21_strchr_two) {
    char temp[100] = "privet, and you? ";
    ck_assert_str_eq(s21_strchr(temp, 32), strchr(temp, 32));
}
END_TEST

START_TEST(s21_strchr_three) {
    char temp[] = " .      /0 d  ";
    ck_assert_str_eq(s21_strchr(temp, 100), strchr(temp, 100));
}
END_TEST

START_TEST(s21_strchr_four) {
    char temp[100] = "elim -> k <- delim ";
    ck_assert_str_eq(s21_strchr(temp, 100), strchr(temp, 100));
}
END_TEST

START_TEST(s21_strchr_five) {
    char temp[100] = "/0 elim -> k <- delim ";
    ck_assert_str_eq(s21_strchr(temp, 100), strchr(temp, 100));
}
END_TEST

START_TEST(s21_strchr_six) {
    char temp[100] = "NULL \\\\\0";
    ck_assert_str_eq(s21_strchr(temp, 0), strchr(temp, 0));
}
END_TEST

START_TEST(s21_strchr_seven) {
    char temp[100] = "elim -> k <- delim ";
    ck_assert_str_eq(s21_strchr(temp, 33), strchr(temp, 33));
}
END_TEST

Suite *strchr_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strchr");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strchr_one);
   tcase_add_test(tc_core, s21_strchr_two);
   tcase_add_test(tc_core, s21_strchr_three);
   tcase_add_test(tc_core, s21_strchr_four);
   tcase_add_test(tc_core, s21_strchr_five);
   tcase_add_test(tc_core, s21_strchr_six);
   tcase_add_test(tc_core, s21_strchr_seven);
   suite_add_tcase(s, tc_core);

    return s;
}