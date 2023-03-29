/* driver for s21_sprintf.c */

#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(void) {
  int res = 0, test_res = 0;
  char str1[100];
  char str2[100];
  char *str3 = "%*d Test %-*d Test %*.*d TEST %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;  
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;

  printf("\n===sprintf===\n");
  res = sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  printf("\nstr1: %s\n", str1);
  printf("res: %d\n", res);
  printf("\n===s21_sprintf===\n");
  test_res = s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  printf("\nstr2: %s\n", str2);
  printf("test_res: %d\n", test_res);
  return 0;
}
