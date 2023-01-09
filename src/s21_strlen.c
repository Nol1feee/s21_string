#include "s21_string.h"

//возвращает длину строки без '\0'
s21_size_t s21_strlen(char *string) {
  s21_size_t len = 0;
  while (*(string + len)) {
    len++;
  }
  return len;
}