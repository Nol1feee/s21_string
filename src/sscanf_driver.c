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
  unsigned int a1 = 1, a2 = 1, b1 = 1, b2 = 1, c1 = 1, c2 = 1, d1 = 1, d2 = 1;
  //const char src[] = "\n \t+0178392 \t\n -5628\t\n 01576 +0Z";
  const char src[] = "\n \t+0178392 \t\n +0178392\t\n 01576 +0Z";
  const char *format = "%o %o %*o %";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &b1, &c1, &d1, rem); 
  printf("sscanf output: %o %o %o %o\n", a1, b1, c1, d1);
  printf("rem: %s\n", rem);
  //printf("inter: %s\n", inter);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &a2, &b2, &c2, &d2, test_rem); 
  printf("s21_sscanf output: %o %o %o %o\n", a2, b2, c2, d2);
  printf("test_rem: %s\n", test_rem);
  //printf("test_inter: %s\n", test_inter);
  printf("test_res: %d\n", test_res);
  return 0;
}
