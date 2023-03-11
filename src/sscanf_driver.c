/* driver for s21_sscanf.c */

#include <stdio.h>
//#include <math.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char rem[100] = {'0'};
  //char inter[20] = {'0'};
  //char dst3[20] = {'0'};
  char test_rem[100] = {'0'};
  //char test_inter[20] = {'0'};
  //char test_dst3[20] = {'0'};
  //int num = 0, test_num = 0;
  //printf("!!!test: %e %e\n", +inf, NAN);
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char src[] = "0.115e-3 -iNf +inF nAn ";
  const char *format = "%e %f %G %E";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &b1, &c1, &d1, rem); 
  printf("sscanf output: %e %f %G %E\n", a1, b1, c1, d1);
  printf("rem: %s\n", rem);
  //printf("inter: %s\n", inter);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, &b2, &c2, &d2, test_rem); 
  printf("s21_sscanf output: %e %f %G %E\n", a2, b2, c2, d2);
  printf("test_rem: %s\n", test_rem);
  //printf("test_inter: %s\n", test_inter);
  printf("test_res: %d\n", test_res);
  return 0;
}
