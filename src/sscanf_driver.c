/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20] = {'0'};
  char test_dst[20] = {'0'};
  char *src = "test";
  puts("===sscanf===");
  sscanf(src, "a%s", dst); 
  printf("dst: %s\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, "a%*s", test_dst); 
  printf("test_dst: %s\n", test_dst);
  return 0;
}
