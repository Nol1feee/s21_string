#include "s21_string.h"

// добавляет str_add в конец str_change
char *s21_strcat(char *str_change, char *str_add) {
  return (s21_strncat(str_change, str_add,
                      s21_strlen(str_change) + s21_strlen(str_add)));
}