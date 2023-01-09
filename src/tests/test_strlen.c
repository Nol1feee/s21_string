#include "test_string.h"

START_TEST(s21_strlen_one) {
    char temp[] = "privet, eto nash pervii test";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

START_TEST(s21_strlen_two) {
    char temp[] = "/0";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

START_TEST(s21_strlen_three) {
    char temp[] = "";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

START_TEST(s21_strlen_four) {
    char temp[5] = "kek/0";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

START_TEST(s21_strlen_five) {
    char temp[40] = "        NULL /0    . kjkj";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

START_TEST(s21_strlen_six) {
    char temp[50] = "1NULL";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

START_TEST(s21_strlen_seven) {
    char temp[3] = "kek";
    ck_assert_int_eq(s21_strlen(temp), strlen(temp));
}END_TEST

Suite *strlen_s21(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strlen");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strlen_one);
    tcase_add_test(tc_core, s21_strlen_two);
    tcase_add_test(tc_core, s21_strlen_three);
    tcase_add_test(tc_core, s21_strlen_four);
    tcase_add_test(tc_core, s21_strlen_five);
    tcase_add_test(tc_core, s21_strlen_six);
    tcase_add_test(tc_core, s21_strlen_seven);
    suite_add_tcase(s, tc_core);

    return s;
}
