#include "s21_string.h"

void *s21_memcpy(void *dst, const void *src, size_t n) {
  char *char_dst = (char*)dst;
  const char *char_src = (char*)src;
  /*forward copy*/
  while(n--) { 
    *char_dst++ = *char_src++;
  }
  return dst;
}
