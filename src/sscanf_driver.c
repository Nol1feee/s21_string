/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20];
  //char dst2[20];
  //char test_dst[20];
  //char test_dst2[20];
  int num = 0.0;
  //double  num2 = 0.0;
  int test_num = 0.0;
  //float test_num2 = 0.0;
  const char *src = "0277";
  puts("===sscanf===");
  sscanf(src, "%o", &num); 
  printf("num: %d\n", num);
  printf("remain: %s\n", dst);
  //printf("num2: %f\n", num2);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%o", &test_num); 
  printf("test_num: %d\n", test_num);
  //printf("test_num2: %f\n", test_num2);
  return 0;
}
