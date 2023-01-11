#include "s21_string.h"

void *s21_memset(void *dst, int fill, size_t n) {
  char *char_dst = (char*)dst;
  while(n--) { 
    *char_dst++ = fill;
  }
  return dst;
}
