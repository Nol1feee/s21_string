/* driver for s21_sprintf.c */

#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(void) {
  int res = 0, test_res = 0;
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -1234;
  printf("\n===sprintf===\n");
  res = sprintf(str1, str3, val);
  printf("\nstr1: %s\n", str1);
  printf("res: %d\n", res);
  printf("\n===s21_sprintf===\n");
  test_res = s21_sprintf(str2, str3, val);
  printf("\nstr2: %s\n", str2);
  printf("test_res: %d\n", test_res);
  return 0;
}
