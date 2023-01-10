#include "test_string.h"

START_TEST(s21_strrchr_one) {
    char temp[100] = "delim -> k <- delim ";
    ck_assert_pstr_eq(s21_strrchr(temp, '1'), strrchr(temp, '1'));
}
END_TEST

START_TEST(s21_strrchr_two) {
    char temp[100] = "privet, and you? ";
    ck_assert_pstr_eq(s21_strrchr(temp, 32), strrchr(temp, 32));
}
END_TEST

START_TEST(s21_strrchr_three) {
    char temp[] = " .      /0 d  ";
    ck_assert_pstr_eq(s21_strrchr(temp, 100), strrchr(temp, 100));
}
END_TEST

START_TEST(s21_strrchr_four) {
    char temp[100] = "elim -> k <- delim ";
    ck_assert_pstr_eq(s21_strrchr(temp, 100), strrchr(temp, 100));
}
END_TEST

START_TEST(s21_strrchr_five) {
    char temp[100] = "/0 elim -> k <- delim ";
    ck_assert_pstr_eq(s21_strrchr(temp, 100), strrchr(temp, 100));
}
END_TEST

START_TEST(s21_strrchr_six) {
    char temp[100] = "NULL \\\\\0";
    ck_assert_pstr_eq(s21_strrchr(temp, 0), strrchr(temp, 0));
}
END_TEST

START_TEST(s21_strrchr_seven) {
    char temp[100] = "elim -> k <- delim ";
    ck_assert_pstr_eq(s21_strrchr(temp, 33), strrchr(temp, 33));
}
END_TEST

Suite *strrchr_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strrchr");
    tc_core = tcase_create("Core");
   tcase_add_test(tc_core, s21_strrchr_one);
   tcase_add_test(tc_core, s21_strrchr_two);
   tcase_add_test(tc_core, s21_strrchr_three);
   tcase_add_test(tc_core, s21_strrchr_four);
   tcase_add_test(tc_core, s21_strrchr_five);
   tcase_add_test(tc_core, s21_strrchr_six);
   tcase_add_test(tc_core, s21_strrchr_seven);
   suite_add_tcase(s, tc_core);

    return s;
}