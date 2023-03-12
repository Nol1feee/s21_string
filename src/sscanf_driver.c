/* driver for s21_sscanf.c */

#include <stdio.h>
//#include <math.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20] = {'0'};
  char test_dst[20] = {'0'};
  int a1 = 0, a2 = 0;
  const char src[] = "1 % fum";
  const char *format = "%d %% %s";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, dst); 
  printf("sscanf output: %d %s\n", a1, dst);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, test_dst); 
  printf("s21_sscanf output: %d %s\n", a2, test_dst);
  printf("test_res: %d\n", test_res);
  return 0;
}
