/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  long a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char src[] = "12345 015 % -868";
  const char *format = "%3ld %o %% %u";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &b1, &c1);
  printf("sscanf output: %ld %o %% %u\n", a1, b1, c1);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, &b2, &c2);
  printf("s21_sscanf output: %ld %o %% %u\n", a2, b2, c2);
  printf("test_res: %d\n", test_res);
  return 0;
}
