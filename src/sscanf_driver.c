/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char rem[100] = {'0'};
  //char inter[20] = {'0'};
  //char dst3[20] = {'0'};
  char test_rem[100] = {'0'};
  //char test_inter[20] = {'0'};
  //char test_dst3[20] = {'0'};
  //int num = 0, test_num = 0;
  short a1 = 0, a2 = 0; 
  int b1 = 555, b2 = 555, c1 = 0, c2 = 555, d1 = 555, d2 = 555;
  const char *src = "-0xFFFFF -0x0666 0x 0xABCDEF";
  const char *format = "%hi%*i%2i %i";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &b1, &c1, &d1, rem); 
  printf("sscanf output: %d %d %d %d\n", a1, b1, c1, d1);
  printf("rem: %s\n", rem);
  //printf("inter: %s\n", inter);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, &b2, &c2, &d2, test_rem); 
  printf("s21_sscanf output: %d %d %d %d\n", a2, b2, c2, d2);
  printf("test_rem: %s\n", test_rem);
  //printf("test_inter: %s\n", test_inter);
  printf("test_res: %d\n", test_res);
  return 0;
}
