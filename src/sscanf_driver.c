/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main() {
  const char *src = "10.5";
  //char dst[20];
  //char dst2[20];
  //char test_dst[20];
  //char test_dst2[20];
  float num = 0.0;
  float test_num = 0.0;
  puts("===sscanf===");
  sscanf(src, "%f", &num); 
  printf("num: %f\n", num);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%f", &test_num); 
  printf("test_num: %f\n", test_num);
  return 0;
}
