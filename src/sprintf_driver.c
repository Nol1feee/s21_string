/* driver for s21_sprintf.c */

#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(void) {
  int res = 0, test_res = 0;
  char str1[100];
  char str2[100];
  int a = 70;
  unsigned long int b = 70;
  char *str3 = "%05c Test % 5c Test %lc Test";
  printf("\n===sprintf===\n");
  res = sprintf(str1, str3, a, a, b);
  printf("\nstr1: %s\n", str1);
  printf("res: %d\n", res);
  printf("\n===s21_sprintf===\n");
  test_res = s21_sprintf(str2, str3, a, a, b);
  printf("\nstr2: %s\n", str2);
  printf("test_res: %d\n", test_res);
  return 0;
}
