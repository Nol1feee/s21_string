#include "s21_string.h"

char *s21_strncpy(char *restrict dst, const char *restrict src, size_t n) {
  char *res = dst;
  while (*src && n--) {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = 0;
  return res;
}
