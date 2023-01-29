/* driver for s21_sscanf.c */

#include <stdio.h>

int main() {
  const char *src = "test";
  char dst[20];
  //char test_dst[20];
  sscanf(src, "%s", dst); 
  //s21_sscanf(test_str, "%s", test_dst); 
  puts(dst);
  return 0;
}
