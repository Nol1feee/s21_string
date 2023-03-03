#include "s21_string.h"

char *s21_Right(char *line, const char *trim_chars) {
  s21_size_t len_line = s21_strlen(line);
  s21_size_t len_trim_chars = s21_strlen(trim_chars);
  for (s21_size_t i = len_line - 1; i; i--) {
    int count = 0;
    for (s21_size_t j = 0; j < len_trim_chars; j++) {
      if (line[i] == trim_chars[j]) {
        count++;
        break;
      }
    }
    if (count) {
      line[i] = '\0';
    } else {
      break;
    }
  }
  return line;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *ptr = NULL;
  if (src) {
    ptr = calloc(s21_strlen(src) + 1, sizeof(char));
    if (ptr) {
      src += s21_strspn(src, trim_chars);
      s21_strcpy(ptr, src);
      if (s21_strlen(ptr) > 0) {
        s21_Right(ptr, trim_chars);
      }
    }
  }
  return ptr;
}