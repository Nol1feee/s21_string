/* driver for s21_sscanf.c */

#include <stdio.h>
//#include <math.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char src[] = "-0xFFFF -0xAAAa vz7A2b3d 0xABCDEF";
  const char *format = "%p %p %p %p";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &b1, &c1, &d1); 
  printf("sscanf output: %p %p %p %p\n", a1, b1, c1, d1);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, &b2, &c2, &d2); 
  printf("s21_sscanf output: %p %p %p %p\n", a2, b2, c2, d2);
  printf("test_res: %d\n", test_res);
  return 0;
}
