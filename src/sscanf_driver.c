/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20];
  char test_dst[20];
  int n, n_first = 0;
  int test_n, test_n_first = 0;
  void *p = NULL;
  void *test_p = NULL;
  void *src = "   s0x11aaa  h 111";
  puts("===sscanf===");
  sscanf(src, " s%n %p %s %n", &n_first, &p, dst, &n); 
  printf("read_first: %d\n", n_first);
  printf("read: %d\n", n);
  printf("p: %p\n", p);
  printf("remain: %s\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, " s%n %p %s %n", &test_n_first, &test_p, test_dst, &test_n); 
  printf("test_n_first: %d\n", test_n_first);
  printf("test_p: %p\n", test_p);
  printf("test_n: %d\n", test_n);
  printf("test_remain: %s\n", test_dst);
  return 0;
}
