/* driver for s21_sscanf.c */

#include <stdio.h>
#include <stdlib.h>


int s21_sscanf(const char *str, const char *format, ...);

int main(void) {
  wchar_t dst[20] = {'0'};
  wchar_t test_dst[20] = {'0'};
  char *src = "test";
  puts("===sscanf===");
  sscanf(src, "%ls", dst); 
  printf("dst: %ls\n", dst);
  puts("===s21_sscanf===");
  s21_sscanf(src, "%ls", test_dst); 
  printf("test_dst: %ls\n", test_dst);
  puts("===wchar_t tests===");
  char *wtest = "тa";
  char *cwtest = (char*)malloc(strlen(wtest) * sizeof(char));
  strcpy(cwtest, wtest);
  wchar_t wd_test[4];
  wchar_t wd_test2[4];
  mbtowc(wd_test, cwtest, 4);
  mbtowc(wd_test2, cwtest + 1, 4);
  printf("wd_test: %ls\n", wd_test);
  printf("wd_test2: %ls\n", wd_test2);
  return 0;
}
