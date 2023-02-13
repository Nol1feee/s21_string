/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20];
  char test_dst[20];
  char *p = NULL;
  unsigned long *test_p = NULL;
  void *src = "0x11abch 111";
  puts("===sscanf===");
  printf("p: %p\n", &p);
  sscanf(src, "%p %s", &p, dst); 
  printf("remain: %s\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%p %s", &test_p, test_dst); 
  printf("test_p: %p\n", test_p);
  printf("test_remain: %s\n", test_dst);
  return 0;
}
