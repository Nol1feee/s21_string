/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  //char dst[20];
  //char test_dst[20];
  int n, n_first = 0;
  int test_n, test_n_first = 0;
  //void *p = NULL;
  //void *test_p = NULL;
  void *src = "55 10";
  puts("===sscanf===");
  sscanf(src, " %o %o", &n_first, &n); 
  printf("n_first: %d\n", n_first);
  printf("n: %d\n", n);
  //printf("remain: %s\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, " %o %o", &test_n_first, &test_n); 
  printf("test_n_first: %d\n", test_n_first);
  printf("test_n: %d\n", test_n);
  //printf("test_remain: %s\n", test_dst);
  return 0;
}
