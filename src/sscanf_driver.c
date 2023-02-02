/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main() {
  const char *src = "test";
  char dst[20];
  char test_dst[20];
  sscanf(src, "%s", dst); 
  s21_sscanf(src, "t1%s", test_dst); 
  //puts(dst);
  return 0;
}
