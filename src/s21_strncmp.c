#include "s21_string.h"

// Сравнивает строку, на которую указывает str1,
// со строкой, на которую указывает str2
int s21_strncmp(char *str1, char *str2, size_t n) {
  int result = 0;
  // у двух чаров убрал ансигнед, тк ругался чек.. Влад
  char *p_1 = str1;
  char *p_2 = str2;

  while (p_1 && p_2 && n > 0) {
    n--;
    if (*p_1 != *p_2) {
      result = (*p_1) - (*p_2);
      break;
    }
    p_1++;
    p_2++;
  }
  if (!p_2) {
    result = *p_1;
  } else if (!p_1) {
    result = -(*p_2);
  }
  return result;
}