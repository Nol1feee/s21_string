/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main() {
  //char dst[20];
  //char dst2[20];
  //char test_dst[20];
  //char test_dst2[20];
  long double num = 0.0;
  //double  num2 = 0.0;
  long double test_num = 0.0;
  //float test_num2 = 0.0;
  const char *src = "11.1";
  puts("===sscanf===");
  sscanf(src, "%Lf", &num); 
  printf("num: %Lf\n", num);
  //printf("num2: %f\n", num2);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%Lg", &test_num); 
  printf("test_num: %Lf\n", test_num);
  //printf("test_num2: %f\n", test_num2);
  return 0;
}
