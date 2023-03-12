/* driver for s21_sscanf.c */

#include <stdio.h>
//#include <math.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
  int n1 = 500, n2 = 10000;
  const char src[] = "123123%SkipMePlease!!!!123";
  const char *format = "%d%%SkipMePlease!!!!%d %n";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &a3, &n1); 
  printf("sscanf output: a1 = %d  a3 = %d  n1 = %d\n", a1, a3, n1);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, &a4, &n2); 
  printf("s21_sscanf output: a2 = %d  a4 = %d  n2 = %d\n", a2, a4, n2);
  printf("test_res: %d\n", test_res);
  return 0;
}
