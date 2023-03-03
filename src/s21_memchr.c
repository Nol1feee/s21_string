#include "s21_string.h"

// ищет первое вхождение чара c в str не более n байт..
//  возвращаемое значение -- символ найден - указатель на символ, нет - NULL
void *s21_memchr(const void *str, int c, size_t n) {
  char *res = NULL;
  while (n-- > 0) {
    if (*(char *)str == c) {
      res = (char *)str;
      break;
    }
    str++;
  }
  return res;
}