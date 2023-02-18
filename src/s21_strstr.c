#include "s21_string.h"

char *s21_strstr(char *haystack, char *needle) {
  char *str = haystack;

  if (*needle == '\0') return str;

  char *p_1 = str;
  char *p_2 = needle;

  for (; *str != '\0'; str++) {
    if (*str == *p_2) {
      p_1 = str;
      while (*p_1 == *p_2) {
        if (*p_2 == '\0') break;
        p_1++;
        p_2++;
      }
      if (*p_2 == '\0')
        return str;
      else {
        p_2 = needle;
      }
    }
  }

  return s21_NULL;
}