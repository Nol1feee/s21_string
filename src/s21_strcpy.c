#include "s21_string.h"

char *s21_strcpy(char *restrict dst, const char *restrict src) {
  char *res = dst;
  while (*src) {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = 0;
  return res;
}
