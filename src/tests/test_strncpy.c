#include "test_string.h"

START_TEST(s21_strncpy_one) {
    char temp_one[50] = "1";
    char temp_two[50] = "1";
    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 20), s21_strncpy(temp_one, temp_two, 20));
}
END_TEST

START_TEST(s21_strncpy_two) {
    char temp_one[50] = "";
    char temp_two[50] = "";
    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 10), s21_strncpy(temp_one, temp_two, 10));
}
END_TEST

START_TEST(s21_strncpy_three) {
    char temp_one[50] = " ";
    char temp_two[50] = " ";
    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 0), s21_strncpy(temp_one, temp_two, 0));
}
END_TEST

START_TEST(s21_strncpy_four) {
    char temp_one[50] = "\0 kek jk";
    char temp_two[50] = "\0 kek kj";
    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 50), s21_strncpy(temp_one, temp_two, 50));
}
END_TEST

START_TEST(s21_strncpy_five) {
    char temp_one[50] = "NULL kek \0 lol ";
    char temp_two[50] = "NULL kek \0 lol";
    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 14), s21_strncpy(temp_one, temp_two, 14));
}
END_TEST

START_TEST(s21_strncpy_six) {
    char temp_one[50] = "kek, ke, "" ";
    char temp_two[50] = "kek "" ke "" ";

    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 50), s21_strncpy(temp_one, temp_two, 50));
}
END_TEST

START_TEST(s21_strncpy_seven) {
    char temp_one[] = {"   "};
    char temp_two[] = {"   "};
    ck_assert_pstr_eq(strncpy(temp_one, temp_two, 1), s21_strncpy(temp_one, temp_two, 1));
}
END_TEST


Suite *strncpy_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strncpy");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strncpy_one);
   tcase_add_test(tc_core, s21_strncpy_two);
   tcase_add_test(tc_core, s21_strncpy_three);
   tcase_add_test(tc_core, s21_strncpy_four);
   tcase_add_test(tc_core, s21_strncpy_five);
   tcase_add_test(tc_core, s21_strncpy_six);
   tcase_add_test(tc_core, s21_strncpy_seven);
   suite_add_tcase(s, tc_core);

    return s;
}