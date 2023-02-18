#include "s21_string.h"

// переводит str в верхний регистр
void *s21_to_upper(const char *str) {
  return s21_case_change(str, 97, 122, -32);
}