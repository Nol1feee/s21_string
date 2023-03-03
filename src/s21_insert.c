#include "s21_string.h"

// вставляет str в src на позицию start_index при условии, что
// start_index <= длины src
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *ptr = NULL;
  size_t lenSrc = s21_strlen(src);
  size_t lenStr = s21_strlen(str);
  if (str && start_index <= lenSrc) {
    ptr = calloc(lenSrc + lenStr + 1, sizeof(char));
    if (ptr) {
      s21_strcpy(ptr, src);
      s21_memmove(ptr + start_index + lenStr, ptr + start_index,
                  lenSrc - start_index);
      s21_memmove(ptr + start_index, str, lenStr);
    }
  }
  return ptr;
}