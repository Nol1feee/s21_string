#include "test_string.h"

START_TEST(s21_memcpy_one) {
    char dst[100] = "delim -> k <- delim ";
    char src[100] = "delim kek";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 50), memcpy(dst, src, 50));
}
END_TEST

START_TEST(s21_memcpy_two) {
    char dst[20] = "delim";
    char src[20] = "delim";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST

START_TEST(s21_memcpy_three) {
    char dst[20] = "delim";
    char src[20] = "delim";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 0), memcpy(dst, src, 0));
}
END_TEST

START_TEST(s21_memcpy_four) {
    char dst[20] = "delim";
    char src[] = "";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST

START_TEST(s21_memcpy_five) {
    char dst[20] = "";
    char src[] = "src";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST

START_TEST(s21_memcpy_six) {
    char dst[20] = "";
    char src[] = "src";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST

START_TEST(s21_memcpy_seven) {
    char dst[20] = "   ";
    char src[] = "/0";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST

START_TEST(s21_memcpy_eight) {
    char dst[20] = "\0   ";
    char src[] = "\0";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST

START_TEST(s21_memcpy_nine) {
    char dst[20] = "1112223333   ";
    char src[] = "111222";

    ck_assert_pstr_eq(s21_memcpy(dst, src, 20), memcpy(dst, src, 20));
}
END_TEST


Suite *memcpy_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memcpy");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_memcpy_one);
   tcase_add_test(tc_core, s21_memcpy_two);  
   tcase_add_test(tc_core, s21_memcpy_three);
   tcase_add_test(tc_core, s21_memcpy_four);
   tcase_add_test(tc_core, s21_memcpy_five);
   tcase_add_test(tc_core, s21_memcpy_six);
   tcase_add_test(tc_core, s21_memcpy_seven);
   tcase_add_test(tc_core, s21_memcpy_eight);
   tcase_add_test(tc_core, s21_memcpy_nine);

   suite_add_tcase(s, tc_core);

    return s;
}