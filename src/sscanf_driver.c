/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char rem[20] = {'0'};
  //char inter[20] = {'0'};
  //char dst3[20] = {'0'};
  char test_rem[20] = {'0'};
  //char test_inter[20] = {'0'};
  //char test_dst3[20] = {'0'};
  //int num = 0, test_num = 0;
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  const char *src = "5555621 0669 0x777 0x888";
  const char *format = "%8d %10d %d %d%s";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &a2, &a3, &a4, rem); 
  printf("a1 - a2: %d %d %d %d\n", a1, a2, a3, a4);
  printf("rem: %s\n", rem);
  //printf("inter: %s\n", inter);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &b1, &b2, &b3, &b4, test_rem); 
  printf("b1 - b2: %d %d %d %d\n", b1, b2, b3, b4);
  printf("test_rem: %s\n", test_rem);
  //printf("test_inter: %s\n", test_inter);
  printf("test_res: %d\n", test_res);
  return 0;
}
