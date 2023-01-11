#include "test_string.h"

START_TEST(s21_strstr_one) {
    char temp[] = "del deli delim";
    char search[] = "delim";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

START_TEST(s21_strstr_two) {
    char temp[] = "del deli delim";
    char search[] = "/0";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

START_TEST(s21_strstr_three) {
    char temp[] = "del deli delim";
    char search[] = "";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

START_TEST(s21_strstr_four) {
    char temp[] = "";
    char search[] = "kek";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

START_TEST(s21_strstr_five) {
    char temp[] = "  ";
    char search[] = " ";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

START_TEST(s21_strstr_six) {
    char temp[] = "kek";
    char search[] = "ke k";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

START_TEST(s21_strstr_seven) {
    char temp[] = "";
    char search[] = "";
    ck_assert_pstr_eq(s21_strstr(temp, search), strstr(temp, search));
}
END_TEST

Suite *strstr_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strstr");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strstr_one);
   tcase_add_test(tc_core, s21_strstr_two);
   tcase_add_test(tc_core, s21_strstr_three);
   tcase_add_test(tc_core, s21_strstr_four);
   tcase_add_test(tc_core, s21_strstr_five);
   tcase_add_test(tc_core, s21_strstr_six);
   tcase_add_test(tc_core, s21_strstr_seven);
   suite_add_tcase(s, tc_core);

    return s;
}