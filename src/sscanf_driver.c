/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main() {
  const char *src = "test1 test2";
  char dst[20];
  char dst2[20];
  char test_dst[20];
  char test_dst2[20];
  puts("===sscanf===");
  sscanf(src, "%*7s %s", dst2); 
  printf("dst: %s\n",dst);
  printf("dst2: %s\n",dst2);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%*7s %s", test_dst2); 
  printf("test_dst: %s\n",test_dst);
  printf("test_dst2: %s\n",test_dst2);
  return 0;
}
