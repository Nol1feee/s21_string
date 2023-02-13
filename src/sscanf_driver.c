/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20];
  char test_dst[20];
  void *p = NULL;
  void *test_p = NULL;
  void *src = "0x11aaah 111";
  puts("===sscanf===");
  sscanf(src, "%p %s", &p, dst); 
  printf("remain: %s\n", dst);
  puts("===s21_sscanf===");
  printf("test_p: %p\n", &test_p);
  s21_sscanf(src, "%p %s", &test_p, test_dst); 
  printf("test_p: %p\n", test_p);
  printf("test_remain: %s\n", test_dst);
  return 0;
}
