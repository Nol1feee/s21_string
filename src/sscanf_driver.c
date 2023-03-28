/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char str[] = "   a     b c d";
  char *fstr = "%c %c %c %c";
  int a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(str, fstr, &a1, &b1, &c1, &d1);
  printf("%c %c %c %c\n", a1, b1, c1, d1);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(str, fstr, &a2, &b2, &c2, &d2);
  printf("%c %c %c %c\n", a2, b2, c2, d2);
  printf("test_res: %d\n", test_res);
  return 0;
}
