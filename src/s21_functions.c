#include "s21_functions.h"

// work great
s21_size_t s21_strlen(char *string) {
  s21_size_t len = 0;
  while (*(string + len)) {
    len++;
  }
  return len;
}

// don't work with NULL, otherwise work great
char s21_strtok(char *string, char *delim) {
  s21_size_t len = s21_strlen(string);
  for (int i = 0; i < len; i++) {
    if (string[i] == *delim) string[i] = '\0';
    break;
  }
  return string[i];
}

// work great
char *s21_strcat(char *str_change, char *str_add);
{
  return (s21_strncat(str_change, str_add,
                      s21_strlen(str_change) + s21_strlen(str_add)));
}

// work great
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) {
  size_t len_str_change = strlen(str_change);
  int i = 0;
  while (str_add[i] != '\0' && i < n) {
    str_change[len_str_change + i] = str_add[i];
    i++;
  }
  str_change[len_str_change + i] = '\0';
  return str_change;
}

char *s21_strerror(int errnum) {
  // ошибка без static - address of stack memory associated with local variable
  // 'res' returned [-Wreturn-stack-address]
  static char res[50] = {0};
  if (errnum >= 0 && errnum < AMOUNT_ERRORS) {
    strcpy(res, errors[errnum]);
  }  // else {
  //	printf("Unknown error: %d", errnum);
  //}
  return res;
}

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
// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  char *res = NULL;

  do {
    if (*str == c) res = (char *)str;
  } while (*str++);
  return (res);
=======
  // work great
  int s21_strcmp(char *str_one, char *str_two) {
    while (*str_one && *str_one == *str_two) {
      str_one++;
      str_two++;
    }
    return *str_one - *str_two;
>>>>>>> vlad
  }
