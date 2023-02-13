/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20];
  //char dst2[20];
  char test_dst[20];
  //char test_dst2[20];
  //int num = 0.0;
  //double  num2 = 0.0;
  //int test_num = 0.0;
  //float test_num2 = 0.0;
  long double *p = NULL;
  long double *test_p = NULL;
  void *src = "0x11abch 111";
  puts("===sscanf===");
  sscanf(src, "%p %s", &p, dst); 
  printf("p: %p\n", p);
  printf("remain: %s\n", dst);
  //printf("num2: %f\n", num2);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%p %s", &test_p, test_dst); 
  printf("test_p: %p\n", p);
  printf("test_remain: %s\n", test_dst);
  return 0;
}
