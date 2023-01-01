#include "s21_functions.h"

//возвращает длину строки, работает на 100%
s21_size_t s21_strlen(char *string) {
	s21_size_t len = 0;
	while(*(string + len)) {
		len++;
	}
	return len;
}

//don't work with NULL, otherwise work great
void s21_strtok(char *string, char *delim) {
	s21_size_t len = s21_strlen(string);
	for(int i = 0; i < len; i++) {
		if(string[i] == *delim) 
			string[i] = '\0';
	}
}

//abort, but i need trap + incorrect work, when i try to add one symbol with not enought memory 
char s21_strcat(char *str_change, char *str_add) {
	s21_size_t len = s21_strlen(str_change);
	s21_size_t len_str_add = s21_strlen(str_add);
	while(*str_add != '\0') {
		*(str_change + len) = *str_add;
		str_change++;
		str_add++;
	}
	//for(int i = len; *str_add != '\0'; str_change[i] = *str_add, i++, str_add++);
	str_change[len + len_str_add] = '\0';
	return *str_change;
}

//fix strcat, then i need 15 min. for strncat
void s21_strncat(char *restrict s1, char *restrict s2, s21_size_t n) {
}

//work witch %c, but i need use %s
char s21_strerror(int errnum) { 
	char res[50];
	if(errnum >= 0 && errnum < AMOUNT_ERRORS) {
		printf("%s", errors[errnum]); 
	} else {
		printf("Unknown error: %d", errnum);
	}
	return 0;
}

void s21_strcmp(char *str_one, char *str_two) {
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
}