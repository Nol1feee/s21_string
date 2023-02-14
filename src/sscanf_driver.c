/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20];
  char test_dst[20];
  int n, n_first = 0;
  void *p = NULL;
  void *test_p = NULL;
  void *src = "   ss0x11aaa  h 111";
  puts("===sscanf===");
  sscanf(src, "   ss%n %p %s %n", &n_first, &p, dst, &n); 
  printf("read_first: %d\n", n_first);
  printf("read: %d\n", n);
  printf("p: %p\n", p);
  printf("remain: %s\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%p %s", &test_p, test_dst); 
  printf("test_p: %p\n", test_p);
  printf("test_remain: %s\n", test_dst);
  return 0;
}
