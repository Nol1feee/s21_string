#include "test_string.h"

START_TEST(s21_memset_one) {
    char dst[100] = "delim -> k <- delim ";
    char src = '5';

    ck_assert_str_eq(s21_memset(dst, src, 50), memset(dst, src, 50));
}
END_TEST

START_TEST(s21_memset_two) {
    char dst[2] = "";
    char src = '\0';

    ck_assert_pstr_eq(s21_memset(dst, src, 1), memset(dst, src, 1));
}
END_TEST

START_TEST(s21_memset_three) {
    char dst[20] = "delim";

    ck_assert_pstr_eq(s21_memset(dst, 199, 15), memset(dst, 199, 15));
}
END_TEST

START_TEST(s21_memset_four) {
    char dst[20] = "delim";

    ck_assert_pstr_eq(s21_memset(dst, 187, 20), memset(dst, 187, 20));
}
END_TEST

START_TEST(s21_memset_six) {
    char dst[5] = "";

    ck_assert_pstr_eq(s21_memset(dst, ' ', 4), memset(dst, ' ', 4));
}
END_TEST

START_TEST(s21_memset_seven) {
    char dst[20] = "\0";

    ck_assert_pstr_eq(s21_memset(dst, '1', 20), memset(dst, '1', 20));
}
END_TEST

START_TEST(s21_memset_eight) {
    char dst[20] = "\0   ";
    char src = ' ';

    ck_assert_pstr_eq(s21_memset(dst, src, 4), memset(dst, src, 4));
}
END_TEST

START_TEST(s21_memset_nine) {
    char dst[20] = "";
    char src = '1';

    ck_assert_pstr_eq(s21_memset(dst, src, 20), memset(dst, src, 20));
}
END_TEST


Suite *memset_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memset");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_memset_one);
   tcase_add_test(tc_core, s21_memset_two);  
   tcase_add_test(tc_core, s21_memset_three);
   tcase_add_test(tc_core, s21_memset_four);
   tcase_add_test(tc_core, s21_memset_six);
   tcase_add_test(tc_core, s21_memset_seven);
   tcase_add_test(tc_core, s21_memset_eight);
   tcase_add_test(tc_core, s21_memset_nine);

   suite_add_tcase(s, tc_core);

    return s;
}