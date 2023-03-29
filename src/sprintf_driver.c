/* driver for s21_sprintf.c */

#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(void) {
  int res = 0, test_res = 0;
  char str1[100];
  char str2[100];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -2939;

  printf("\n===sprintf===\n");
  res = sprintf(str1, str3, a, b, c, d);
  printf("\nstr1: %s\n", str1);
  printf("res: %d\n", res);
  printf("\n===s21_sprintf===\n");
  test_res = s21_sprintf(str2, str3, a, b, c, d);
  printf("\nstr2: %s\n", str2);
  printf("test_res: %d\n", test_res);
  return 0;
}
