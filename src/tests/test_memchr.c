#include "test_string.h"

START_TEST(s21_memchr_one) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, 100, 100), memchr(temp, 100, 100));
}
END_TEST

START_TEST(s21_memchr_two) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, -5, 1), memchr(temp, -5, 1));
}
END_TEST

START_TEST(s21_memchr_three) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, 105, 100), memchr(temp, 105, 100));
}
END_TEST

START_TEST(s21_memchr_four) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, 105, 2), memchr(temp, 105, 2));
}
END_TEST

START_TEST(s21_memchr_five) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, 100, 0), memchr(temp, 100, 0));
}
END_TEST

START_TEST(s21_memchr_six) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, -4587, 99 - 5), memchr(temp, -4587, 99 - 5));
}
END_TEST

START_TEST(s21_memchr_seven) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, 0, 0), memchr(temp, 0, 0));
}
END_TEST

START_TEST(s21_memchr_eight) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_ptr_eq(s21_memchr(temp, '9', 0), memchr(temp, '9', 0));
}
END_TEST

Suite *memchr_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memchr");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_memchr_one);
   tcase_add_test(tc_core, s21_memchr_two);
   tcase_add_test(tc_core, s21_memchr_three);
   tcase_add_test(tc_core, s21_memchr_four);
   tcase_add_test(tc_core, s21_memchr_five);
   tcase_add_test(tc_core, s21_memchr_six);
   tcase_add_test(tc_core, s21_memchr_seven);
   tcase_add_test(tc_core, s21_memchr_eight);
   suite_add_tcase(s, tc_core);

    return s;
}