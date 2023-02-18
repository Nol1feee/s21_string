#include "s21_string.h"

// фун-ия для strtok
int enum_delim(char str, const char *delima) {
  int find = 0;
  while (*delima != '\0' && find == 0) {
    if (str == *delima) {
      find = 1;
    }
    delima++;
  }
  return find;
}

char *s21_strtok(char *restrict str, const char *restrict delim) {
  static char *buffer;
  char *res = NULL;
  if (str != NULL) {
    buffer = NULL;
  } else {
    str = buffer;
  }
  while (enum_delim(*str, delim) && *str != '\0') {
    str++;
  }

  if (*str != '\0') res = str;
  while (!enum_delim(*str, delim) && *str != '\0') {
    str++;
  }

  if (*str != '\0') {
    *str = '\0';
    buffer = str + 1;
  } else {
    buffer = str;
  }
  return res;
}