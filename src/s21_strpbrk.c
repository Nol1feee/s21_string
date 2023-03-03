#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  int i, j, pos, flag = 0;
  for (i = 0; str1[i] != '\0'; i++)
    ;
  pos = i;
  for (i = 0; str2[i] != '\0'; i++) {
    for (j = 0; str1[j] != '\0'; j++) {
      if (str2[i] == str1[j]) {
        if (j <= pos) {
          pos = j;
          flag = 1;
        }
      }
    }
  }
  return flag == 1 ? (char *)&str1[pos] : NULL;
}