/* driver for s21_sscanf.c */

#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  char dst[20] = {'0'};
  char test_dst[20] = {'0'};
  char *src = "test";
  puts("===sscanf===");
  sscanf(src, "%s", dst); 
  printf("dst: %s\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%s", test_dst); 
  printf("test_dst: %s\n", test_dst);
  /*puts("===wchar_t tests===");
  char *wtest = "षा1";
  wchar_t pw[2];
  int byte = mbtowc(pw, wtest, 4);
  printf("byte: %d\n", byte);
  wchar_t wd_test[8];
  mbstowcs(wd_test, wtest, strlen(wtest));
  printf("wd_test: %ls\n", wd_test);
  printf("pw: %ls\n", pw);
  printf("strlen: %lu\n", strlen(wtest));
  printf("size of pw: %lu\n", sizeof(pw));*/
  return 0;
}
