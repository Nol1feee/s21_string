/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst1[20] = {'0'};
  char dst2[20] = {'0'};
  char dst3[20] = {'0'};
  char test_dst1[20] = {'0'};
  char test_dst2[20] = {'0'};
  char test_dst3[20] = {'0'};
  char *src = "one two three";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, "%s %s %s", dst1, dst2, dst3); 
  printf("dst1: %s\n", dst1);
  printf("dst2: %s\n", dst2);
  printf("dst3: %s\n", dst3);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, "%s %s %s", test_dst1, test_dst2, test_dst3); 
  printf("test_dst1: %s\n", test_dst1);
  printf("test_dst2: %s\n", test_dst2);
  printf("test_dst3: %s\n", test_dst3);
  printf("test_res: %d\n", test_res);
  return 0;
}
