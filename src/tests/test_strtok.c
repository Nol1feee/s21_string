#include "test_string.h"

START_TEST(s21_strtok_one) {
    char temp_one[] = "delim -> k <- delim";
    char temp_two[] = "delim -> k <- delim";
    char delim[] = "k";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_two) {
    char temp_one[] = "delim -> \0 k <- delim";
    char temp_two[] = "delim -> \0 k <- delim";
    char delim[] = "k";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_three) {
    char temp_one[] = "delim -> \0 k <- delim";
    char temp_two[] = "delim -> \0 k <- delim";
    char delim[] = "q";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_four) {
    char temp_one[] = "delim -> \0 k <- delim";
    char temp_two[] = "delim -> \0 k <- delim";
    char delim[] = "";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_five) {
    char temp_one[] = "delim -> \0 k <- delim";
    char temp_two[] = "delim -> \0 k <- delim";
    char delim[] = " ";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_six) {
    char temp_one[] = "wow, are you crazy?";
    char temp_two[] = "wow, are you crazy?";
    char delim[] = "?\0";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_seven) {
    char temp_one[] = "wow, are you crazy?";
    char temp_two[] = "wow, are you crazy?";
    char delim[] = "\0";
    char *one = s21_strtok(temp_one, delim);
    char *two = strtok(temp_two, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_eight) {
    char delim[] = "\0";
    char *one = s21_strtok(NULL, delim);
    char *two = strtok(NULL, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_nine) {
    char delim[] = "kwk ";
    char *one = s21_strtok(NULL, delim);
    char *two = strtok(NULL, delim);
    ck_assert_pstr_eq(one, two);
}
END_TEST

START_TEST(s21_strtok_ten) {
    char one_str[][30] = {"wow, are, you, crazy?", "kek \0 ckeck", "NULL, poka, cheb ' ' ", "poke chek"};
    char two_str[][30] = {"wow, are, you, crazy?", "kek \0 ckeck", "NULL, poka,  cheb ' ' ", "poke chek"};
    char del[][15] = {"a, q, c, /0", "\0", "k, e, k", "q"};
    for(int i = 0; i < 4; i++) {
        char *tok = s21_strtok(one_str[i], del[i]);
        char *tok_two = strtok(two_str[i], del[i]);
        while(tok && tok_two) {
            ck_assert_pstr_eq(tok, tok_two);
            tok = s21_strtok(NULL, del[i]);
            tok_two = strtok(NULL, del[i]);
        }
    }
}
END_TEST

// START_TEST() {
//     char temp_one[] = "";
//     char temp_two[] = "";
//     char delim[] = "";
//     char *str
// char str_test[][30] = {"a   b c\0", "a,b,c\0", "a b,c\0"};
//   char delimeters[][30] = {" ", ",", " ,"};
//   for (int i = 0; i < 3; i++) {
//     printf("%s\n", str_test[i]);
//     printf("%s\n", delimeters[i]);
//     char *tok = s21_strtok(str_test[i], delimeters[i]);
//     char check[10] = {""};
//     while (tok) {
//       s21_strcat(check, tok);
//       tok = s21_strtok(NULL, delimeters[i]);
//     }
//     printf("%s\n", check);
//     if (s21_strcmp(check, "abc") == 0) {
//       printf("SUCCESS\n");
//     } else {
//       printf("FAIl\n");
//     }
//   }
// }
// END_TEST
Suite *strtok_s21() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strtok");
    tc_core = tcase_create("Core");

   tcase_add_test(tc_core, s21_strtok_one);
   tcase_add_test(tc_core, s21_strtok_two);
    tcase_add_test(tc_core, s21_strtok_three);
    tcase_add_test(tc_core, s21_strtok_four);
    tcase_add_test(tc_core, s21_strtok_five);
    tcase_add_test(tc_core, s21_strtok_six);
    tcase_add_test(tc_core, s21_strtok_seven);
    tcase_add_test(tc_core, s21_strtok_eight);
    tcase_add_test(tc_core, s21_strtok_nine);
    tcase_add_test(tc_core, s21_strtok_ten);
   suite_add_tcase(s, tc_core);

    return s;
}
// char str_test[][30] = {"a   b c\0", "a,b,c\0", "a b,c\0"};
//   char delimeters[][30] = {" ", ",", " ,"};
//   for (int i = 0; i < 3; i++) {
//     printf("%s\n", str_test[i]);
//     printf("%s\n", delimeters[i]);
//     char *tok = s21_strtok(str_test[i], delimeters[i]);
//     char check[10] = {""};
//     while (tok) {
//       s21_strcat(check, tok);
//       tok = s21_strtok(NULL, delimeters[i]);
//     }
//     printf("%s\n", check);
//     if (s21_strcmp(check, "abc") == 0) {
//       printf("SUCCESS\n");
//     } else {
//       printf("FAIl\n");
//     }
//   }}