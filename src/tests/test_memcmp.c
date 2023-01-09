#include "test_string.h"

START_TEST(s21_memcmp_one) {
    char temp[100] = "delim -> k <- delim ";
    char temp_two[100] = "delim kek";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, 50), memcmp(temp,temp_two, 50));
}
END_TEST

START_TEST(s21_memcmp_two) {
    char temp[100] = " .   NULL ";
    char temp_two[100] = " .  /0";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, 50), memcmp(temp,temp_two, 50));
}
END_TEST

START_TEST(s21_memcmp_three) {
    char temp[100] = " .    NULL";
    char temp_two[100] = " .    NULL";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, 2), memcmp(temp,temp_two, 2));
}
END_TEST

START_TEST(s21_memcmp_four) {
    char temp[100] = "delim -> k <- delim ";
    char temp_two[100] = "delim kek";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, 0), memcmp(temp,temp_two, 0));
}
END_TEST

START_TEST(s21_memcmp_five) {
    char temp[100] = "delim -> k <- delim ";
    char temp_two[100] = "delim kek";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, (10*5)/2), memcmp(temp,temp_two, (10*5)/2));
}
END_TEST

START_TEST(s21_memcmp_six) {
    char temp[100] = "";
    char temp_two[100] = "";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, 50), memcmp(temp,temp_two, 50));
}
END_TEST

START_TEST(s21_memcmp_seven) {
    char temp[5] = "kjk ";
    char temp_two[5] = "kjk ";

    ck_assert_int_eq(s21_memcmp(temp, temp_two, 111-107), memcmp(temp,temp_two, 111-107));
}
END_TEST

Suite *memcmp_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memcmp");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_memcmp_one);
   tcase_add_test(tc_core, s21_memcmp_two);  
   tcase_add_test(tc_core, s21_memcmp_three);
   tcase_add_test(tc_core, s21_memcmp_four);
   tcase_add_test(tc_core, s21_memcmp_five);
   tcase_add_test(tc_core, s21_memcmp_six);
   tcase_add_test(tc_core, s21_memcmp_seven);
   suite_add_tcase(s, tc_core);

    return s;
}