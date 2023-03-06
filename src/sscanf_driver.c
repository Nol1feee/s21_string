/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  //char dst1[20] = {'0'};
  //char dst2[20] = {'0'};
  //char dst3[20] = {'0'};
  //char test_dst1[20] = {'0'};
  //char test_dst2[20] = {'0'};
  //char test_dst3[20] = {'0'};
  //int num = 0, test_num = 0;
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  const char *src = "5555621 0666 0x777 0X888";
  const char *format = "%8i %10i %i %d";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, format, &a1, &a2, &a3, &a4); 
  printf("a1 - a2: %d %d %d %d\n", a1, a2, a3, a4);
  //printf("dst2: %s\n", dst2);
  //printf("dst3: %s\n", dst3);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, format, &b1, &b2, &b3, &b4); 
  printf("b1 - b2: %d %d %d %d\n", b1, b2, b3, b4);
  //printf("test_dst2: %s\n", test_dst2);
  //printf("test_dst3: %s\n", test_dst3);
  printf("test_res: %d\n", test_res);
  return 0;
}
