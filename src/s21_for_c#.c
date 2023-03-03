#include "s21_string.h"

void *s21_case_change(const char *str, int ot, int d0, int shift) {
  char *ptr = NULL;
  if (str) {
    ptr = calloc(s21_strlen(str) + 1, sizeof(char));
    if (ptr) {
      s21_strcpy(ptr, str);

      for (size_t i = 0; i < s21_strlen(str); i++) {
        if (ptr[i] >= ot && ptr[i] <= d0) {
          ptr[i] += shift;
        }
      }
    }
  }
  return ptr;
}