/* driver for s21_sprintf.c */

#include <stdio.h>
// #include <math.h>

int s21_sprintf(char* buf, const char* format, ...);

int main(void) {
  int res = 0, test_res = 0;
  char str1[100];
  char str2[100];
  char* str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  printf("\n===sprintf===\n");
  res = sprintf(str1, str3, a, b, c, d, e);
  printf("\nstr1: %s\n", str1);
  printf("res: %d\n", res);
  printf("\n===s21_sprintf===\n");
  test_res = s21_sprintf(str2, str3, a, b, c, d, e);
  printf("\nstr2: %s\n", str2);
  printf("test_res: %d\n", test_res);
  return 0;
}
