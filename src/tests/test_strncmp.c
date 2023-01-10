#include "test_string.h"

START_TEST(s21_strncmp_one) {
    char temp_one[50] = "1";
    char temp_two[50] = "1";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 1), s21_strncmp(temp_one, temp_two, 1));
}
END_TEST

START_TEST(s21_strncmp_two) {
    char temp_one[50] = "";
    char temp_two[50] = "";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 50), s21_strncmp(temp_one, temp_two, 50));
}
END_TEST

START_TEST(s21_strncmp_three) {
    char temp_one[50] = " ";
    char temp_two[50] = " ";
    ck_assert_int_eq(strncmp(temp_one, temp_two, -5+10), s21_strncmp(temp_one, temp_two, -5+10));
}
END_TEST

START_TEST(s21_strncmp_four) {
    char temp_one[50] = "\0 kek jk";
    char temp_two[50] = "\0 kek kj";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 4), s21_strncmp(temp_one, temp_two, 4));
}
END_TEST

START_TEST(s21_strncmp_five) {
    char temp_one[50] = "NULL kek '\0' lol ";
    char temp_two[50] = "NULL kek '\0' lol";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 50), s21_strncmp(temp_one, temp_two, 50));
}
END_TEST

START_TEST(s21_strncmp_six) {
    char temp_one[50] = "kek, ke, "" ";
    char temp_two[50] = "kek "" ke "" ";

    ck_assert_int_eq(strncmp(temp_one, temp_two, 11), s21_strncmp(temp_one, temp_two, 11));
}
END_TEST

START_TEST(s21_strncmp_seven) {
    char temp_one[] = {"   "};
    char temp_two[] = {"   "};
    ck_assert_int_eq(strncmp(temp_one, temp_two, 4), s21_strncmp(temp_one, temp_two, 4));
}
END_TEST

START_TEST(s21_strncmp_eight) {
    char temp_one[50] = "kek, ke, "" ";
    char temp_two[50] = "kek "" ke "" ";

    ck_assert_int_eq(strncmp(temp_one, temp_two, 0), s21_strncmp(temp_one, temp_two, 0));
}
END_TEST

START_TEST(s21_strncmp_nine) {
    char temp_one[50] = "kek, ke, "" ";

    ck_assert_int_eq(strncmp(temp_one, "", 0), s21_strncmp(temp_one, "", 0));
}
END_TEST

START_TEST(s21_strncmp_ten) {
    char temp_one[50] = "kek, ke, "" ";

    ck_assert_int_eq(strncmp(temp_one, "", 10), s21_strncmp(temp_one, "", 10));
}
END_TEST

START_TEST(s21_strncmp_elleven) {
    char temp_two[50] = "kek, ke, "" ";
    char temp_one[50] = "qqq iii ...";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 50), s21_strncmp(temp_one, temp_two, 50));
}
END_TEST

START_TEST(s21_strncmp_twelve) {
    char temp_one[50] = "kek, ke, "" ";
    char temp_two[50] = "qqq iii ...";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 50), s21_strncmp(temp_one, temp_two, 50));
}
END_TEST

START_TEST(s21_strncmp_13) {
    char temp_one[5] = "55";
    char temp_two[50] = "privet poika";
    ck_assert_int_eq(strncmp(temp_one, temp_two, 1), s21_strncmp(temp_one, temp_two, 1));
}
END_TEST

Suite *strncmp_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strncmp");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strncmp_one);
   tcase_add_test(tc_core, s21_strncmp_two);
   tcase_add_test(tc_core, s21_strncmp_three);
   tcase_add_test(tc_core, s21_strncmp_four);
   tcase_add_test(tc_core, s21_strncmp_five);
   tcase_add_test(tc_core, s21_strncmp_six);
   tcase_add_test(tc_core, s21_strncmp_seven);
   tcase_add_test(tc_core, s21_strncmp_eight);
   tcase_add_test(tc_core, s21_strncmp_nine);
   tcase_add_test(tc_core, s21_strncmp_ten);
   tcase_add_test(tc_core, s21_strncmp_elleven);
   tcase_add_test(tc_core, s21_strncmp_twelve);
   tcase_add_test(tc_core, s21_strncmp_13);
   suite_add_tcase(s, tc_core);

    return s;
}