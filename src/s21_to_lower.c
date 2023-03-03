#include "s21_string.h"

void *s21_to_lower(const char *str) { return s21_case_change(str, 65, 90, 32); }
