#include "test_string.h"

START_TEST(s21_sscanf_test1) {
#line 2108
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test2) {
#line 2115
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0x12fA bB09", "%x%x", &x1, &x2),
                   s21_sscanf("0x12fA bB09", "%x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test3) {
#line 2122
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0xff01 -96 05678", "%i%i", &x1, &x2),
                   s21_sscanf("0xff01 -96 05678", "%i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test4) {
#line 2129
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0567 +101 ", "%i%i", &x1, &x2),
                   s21_sscanf("0567 +101 ", "%i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test5) {
#line 2136
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0567 +101 ", "%o%3o", &x1, &x2),
                   s21_sscanf("0567 +101 ", "%o%3o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test6) {
#line 2143
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("3452 -99", "%u%u", &x1, &x2),
                   s21_sscanf("3452 -99", "%u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test7) {
#line 2150
  unsigned int x1, x2, y1, y2;
  ck_assert_uint_eq(sscanf("3452 -99", "%u%u", &x1, &x2),
                    s21_sscanf("3452 -99", "%u%u", &y1, &y2));
  ck_assert_uint_eq(x1, y1);
  ck_assert_uint_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test8) {
#line 2157
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("3452-99", "%i%n", &x1, &x2),
                   s21_sscanf("3452-99", "%i%n", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test9) {
#line 2164
  char x1[10] = "\0", x2[10] = "\0", y1[10] = "\0", y2[10] = "\0";
  ck_assert_int_eq(sscanf("hi fry slow", "%9sfry%9s", x1, x2),
                   s21_sscanf("hi fry slow", "%9sfry%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test10) {
#line 2171
  int x1, y1;
  ck_assert_int_eq(sscanf("12%", "%d%%", &x1), s21_sscanf("12%", "%d%%", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test11) {
#line 2176
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("-11-  %", "%d%%", &x1),
                   s21_sscanf("-11-  %", "%d%%", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test12) {
#line 2182
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  ck_assert_int_eq(sscanf("-11  % 4", "%d%%%d", &x1, &x2),
                   s21_sscanf("-11  % 4", "%d%%%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test13) {
#line 2189
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(
      sscanf("0x12fAaaaaaaaaaaaaaaaaaa bB09", "%x%x", &x1, &x2),
      s21_sscanf("0x12fAaaaaaaaaaaaaaaaaaa bB09", "%x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test14) {
#line 2196
  unsigned short int x1, y1;
  ck_assert_int_eq(sscanf("12", "%hu", &x1), s21_sscanf("12", "%hu", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test16) {
#line 2201
  char x1[20] = {0}, x2[20] = {0}, y1[20] = {0}, y2[20] = {0};
  ck_assert_int_eq(sscanf("  ya", "%9s   %9s", x1, x2),
                   s21_sscanf("  ya", "%9s   %9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test17) {
#line 2208
  long x1, y1;
  short x2, y2;
  ck_assert_int_eq(sscanf("12 45", "%ld%hd", &x1, &x2),
                   s21_sscanf("12 45", "%ld%hd", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test18) {
#line 2216
  char x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0 a", "%c%c", &x1, &x2),
                   s21_sscanf("0 a", "%c%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test19) {
#line 2223
  long unsigned int x1, y1;
  unsigned int x2, y2;
  ck_assert_uint_eq(sscanf("3452 -99", "%lu%u", &x1, &x2),
                    s21_sscanf("3452 -99", "%lu%u", &y1, &y2));
  ck_assert_uint_eq(x1, y1);
  ck_assert_uint_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test20) {
#line 2231
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("  g  ", "%i", &x1), s21_sscanf("  g  ", "%i", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test21) {
#line 2236
  unsigned int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("  g  ", "%u", &x1), s21_sscanf("  g  ", "%u", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test22) {
#line 2241
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("V123", "%d", &x1), s21_sscanf("V123", "%d", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test23) {
#line 2246
  wchar_t x1[10], y1[10];
  ck_assert_int_eq(sscanf("qwerty 12345", "%1ls", x1),
                   s21_sscanf("qwerty 12345", "%1ls", y1));
  ck_assert_int_eq(*x1, *y1);
}
END_TEST

START_TEST(s21_sscanf_test24) {
#line 2252
  wchar_t x1, y1;
  char x2, y2;
  ck_assert_int_eq(sscanf("ass", "%lc%c", &x1, &x2),
                   s21_sscanf("ass", "%lc%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test25) {
#line 2260
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("123456 654321", "  %00004d  %6d", &x1, &x2),
                   s21_sscanf("123456 654321", "  %00004d  %6d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test26) {
#line 2267
  long double x1, y1;
  float x2, y2;
  ck_assert_int_eq(sscanf("0.9045010    0.023", "%Le%4f", &x1, &x2),
                   s21_sscanf("0.9045010    0.023", "%Le%4f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test27) {
#line 2275
  float x1, y1, x2, y2;
  ck_assert_int_eq(sscanf("2.17e2 0.4e-3", "%G %g", &x1, &x2),
                   s21_sscanf("2.17e2 0.4e-3", "%G %g", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test28) {
#line 2282
  float x1, y1, x2, y2;
  ck_assert_int_eq(sscanf("2.17e2 0.4e+3", "%E%f", &x1, &x2),
                   s21_sscanf("2.17e2 0.4e+3", "%E%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test29) {
#line 2289
  char x1[30] = {0}, y1[30] = {0};
  float x2, y2;
  unsigned int x3 = 0, y3 = 0;
  ck_assert_int_eq(
      sscanf("qwerty -12.0345007", "%6s%f    %o", x1, &x2, &x3),
      s21_sscanf("qwerty -12.0345007", "%6s%f    %o", y1, &y2, &y3));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq(x3, y3);
}
END_TEST

START_TEST(s21_sscanf_test30) {
#line 2299
  char x1[30] = {0}, y1[30] = {0};
  float x2, y2;
  unsigned int x3 = 0, y3 = 0;
  ck_assert_int_eq(sscanf("qwerty -12.0345007", "%9s%f%2o", x1, &x2, &x3),
                   s21_sscanf("qwerty -12.0345007", "%9s%f%2o", y1, &y2, &y3));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq(x3, y3);
}
END_TEST

START_TEST(s21_sscanf_test31) {
#line 2309
  unsigned int x1, y1;
  char s1[30], s2[30];
  ck_assert_int_eq(sscanf("0xE00A4DOG", "%6x%*d%3s", &x1, s1),
                   s21_sscanf("0xE00A4DOG", "%6x%*d%3s", &y1, s2));
  ck_assert_int_eq(x1, y1);
  ck_assert_str_eq(s1, s2);
}
END_TEST

Suite *sscanf_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sscanf");
  tc_core = tcase_create("Core");

tcase_add_test(tc_core, s21_sscanf_test1);
  tcase_add_test(tc_core, s21_sscanf_test2);
  tcase_add_test(tc_core, s21_sscanf_test3);
  tcase_add_test(tc_core, s21_sscanf_test4);
  tcase_add_test(tc_core, s21_sscanf_test5);
  tcase_add_test(tc_core, s21_sscanf_test6);
  tcase_add_test(tc_core, s21_sscanf_test7);
  tcase_add_test(tc_core, s21_sscanf_test8);
  tcase_add_test(tc_core, s21_sscanf_test9);
  tcase_add_test(tc_core, s21_sscanf_test10);
  tcase_add_test(tc_core, s21_sscanf_test11);
  tcase_add_test(tc_core, s21_sscanf_test12);
  tcase_add_test(tc_core, s21_sscanf_test13);
  tcase_add_test(tc_core, s21_sscanf_test14);
  tcase_add_test(tc_core, s21_sscanf_test16);
  tcase_add_test(tc_core, s21_sscanf_test17);
  tcase_add_test(tc_core, s21_sscanf_test18);
  tcase_add_test(tc_core, s21_sscanf_test19);
  tcase_add_test(tc_core, s21_sscanf_test20);
  tcase_add_test(tc_core, s21_sscanf_test21);
  tcase_add_test(tc_core, s21_sscanf_test22);
  tcase_add_test(tc_core, s21_sscanf_test23);
  tcase_add_test(tc_core, s21_sscanf_test24);
  tcase_add_test(tc_core, s21_sscanf_test25);
  tcase_add_test(tc_core, s21_sscanf_test26);
  tcase_add_test(tc_core, s21_sscanf_test27);
  tcase_add_test(tc_core, s21_sscanf_test28);
  tcase_add_test(tc_core, s21_sscanf_test29);
  tcase_add_test(tc_core, s21_sscanf_test30);
  tcase_add_test(tc_core, s21_sscanf_test31);

  suite_add_tcase(s, tc_core);

  return s;
}