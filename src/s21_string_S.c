#include <stdio.h>
#include <string.h>
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *s21_memchr(void const *str, int c, size_t n) {
  char *res = NULL;
  while (n-- > 0) {
    if (*(char *)str == c) {
      res = (char *)str;
      break;
    }
    str++;
  }
  return res;
}
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
  for (; *str != '\0' && *str != c; ++str)
    ;

  return *str == c ? (char *)str : NULL;
}
// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  int pos, flag = 0;
  for (int i = 0; str2[i] != '\0'; i++) {
    for (int j = 0; str1[j] != '\0'; j++) {
      if (str2[i] == str1[j]) {
        pos = j;
        flag = 1;
        break;
      }
    }
  }

  return flag == 1 ? (char *)&str1[pos] : NULL;
}
// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  char *res = NULL;

  do {
    if (*str == c) res = (char *)str;
  } while (*str++);
  return (res);
}
void main() {
  printf("s21_strpbrk %s, strpbrk %s", s21_strpbrk("abcdertyui", "t"),
         strpbrk("abcdertyui", "t"));
}