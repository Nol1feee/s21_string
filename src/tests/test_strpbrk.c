#include "test_string.h"

START_TEST(s21_strpbrk_one) {
    char temp[100] = "delim -> k <- delim ";
    char temp_two[100] = "oiu";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_two) {
    char temp[] = "/0";
    char temp_two[] = "/0";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_three) {
    char temp[100] = "/0 delim -> k <- delim ";
    char temp_two[100] = "lokki";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_four) {
    char temp[5] = "char";
    char temp_two[5] = "ogo";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_five) {
    char temp[100-50] = "100-50";
    char temp_two[100-50] = "ooo /0";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_six) {
    char temp[100] = "NULL kek d ";
    char temp_two[100] = "/0 '100'";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_seven) {
    char temp[15] = "d";
    char temp_two[15] = "101-1";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

START_TEST(s21_strpbrk_eight) {
    char temp[] = "delim -> k <- delim ";
    char temp_two[] = "->";
    ck_assert_str_eq(s21_strpbrk(temp, temp_two), strpbrk(temp, temp_two));
}
END_TEST

Suite *strpbrk_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strpbrk");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strpbrk_one);
   tcase_add_test(tc_core, s21_strpbrk_two);
   tcase_add_test(tc_core, s21_strpbrk_three);
   tcase_add_test(tc_core, s21_strpbrk_four);
   tcase_add_test(tc_core, s21_strpbrk_five);
   tcase_add_test(tc_core, s21_strpbrk_six);
   tcase_add_test(tc_core, s21_strpbrk_seven);
   tcase_add_test(tc_core, s21_strpbrk_eight);
   suite_add_tcase(s, tc_core);

    return s;
}