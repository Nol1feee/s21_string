#include "s21_string.h"

s21_size_t s21_strspn(const char *string1, const char *string2) {
  s21_size_t count = 0;
  for (const char *a = string1; *a; a++) {
    int fl = 0;
    for (const char *b = string2; *b; b++) {
      if (*a == *b) {
        count++;
        fl = 1;
        break;
      }
    }
    if (!fl) break;
  }
  return count;
}