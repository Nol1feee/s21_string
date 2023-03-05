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
  int num = 0, test_num = 0;
  char *src = "";
  int res = 0, test_res = 0;
  puts("===sscanf===");
  res = sscanf(src, "%d", &num); 
  printf("dst1: %d\n", num);
  //printf("dst2: %s\n", dst2);
  //printf("dst3: %s\n", dst3);
  printf("res: %d\n", res);
  puts("===s21_sscanf===");
  test_res = s21_sscanf(src, "%d", &test_num); 
  printf("test_dst1: %d\n", test_num);
  //printf("test_dst2: %s\n", test_dst2);
  //printf("test_dst3: %s\n", test_dst3);
  printf("test_res: %d\n", test_res);
  return 0;
}
