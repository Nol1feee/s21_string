#include "test_string.h"

START_TEST(s21_strtok_one) {
    char temp_one[] = "delim -> k <- delim";
    char temp_two[] = "delim -> k <- delim";
    char delim[] = "k";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_str_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_two) {
    char temp_one[] = "delim -> \0 k <- delim";
    char temp_two[] = "delim -> \0 k <- delim";
    char delim[] = "k";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_str_eq(one, two);
}
END_TEST

// start_test(s21_strtok_three) {
//     char temp_one[] = "delim -> k <- delim";
//     char temp_two[] = "delim -> k <- delim";
//     char delim[] = "\0";
//     char *one = s21_strtok(temp_one, delim);
//     char *two = strtok(temp_two, delim);
//     ck_assert_str_eq(one, two);
// }
// END_TEST

// start_test(s21_strtok_four) {
// //    char temp_one[] = "delim -> k <- delim";
// //   char temp_two[] = "delim -> k <- delim";
//     char delim[] = "k";
//     char *one = s21_strtok(NULL, delim);
//     char *two = strtok(NULL, delim);
//     ck_assert_str_eq(one, two);
// }
// END_TEST

Suite *strtok_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strtok");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strtok_one);
   tcase_add_test(tc_core, s21_strtok_two);
//    tcase_add_test(tc_core, s21_strtok_three);
//    tcase_add_test(tc_core, s21_strtok_four);
   suite_add_tcase(s, tc_core);

    return s;
}