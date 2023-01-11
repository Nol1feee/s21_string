#include "s21_functions.h"

// work great
//возвращает длину строки без '\0'
s21_size_t s21_strlen(char *string) {
  s21_size_t len = 0;
  while (*(string + len)) {
    len++;
  }
  return len;
}

//фун-ия для strtok
int enum_delim(char str, const char *delim) {
  int flag = 0;
  while (*delim && flag == 0) {
    if (str == *delim) {
      flag = 1;
    }
    delim++;
  }
return flag;
}
//делит строку на токены
char *s21_strtok(char *str, const char *delim) {
	char *res = NULL;
	static char *buf = NULL;
	if(str) {
		buf = NULL;
	} else {
		str = buf;
	}
	res = str;
	//переместить res = str, тк будет фейлить много тестов, но пока что я хз куда
	while(*str) {
		if(enum_delim(*str, delim)) {
			break;
		}	
		str++;
	}
	if(*str) {
		*str = '\0';
		buf = str + 1;
	} else {
		res = NULL;
		buf = NULL;
	}
	return res;
}

// work great
char *s21_strcat(char *str_change, char *str_add)
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
  for (; *str != '\0' && *str != c; ++str);
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
// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(void *str1, void *str2, size_t n) {
    int result = 0;
    unsigned char *p_1 = str1;
    unsigned char *p_2 = str2;

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
//don't work with NULL, otherwise work great
char *s21_strtok(char *string, char *delim) {
	s21_size_t len = s21_strlen(string);
	for(int i = 0; i < len; i++) {
		if(string[i] == *delim) 
			string[i] = '\0';
			break;
	}
	return string;
}

//фун-ия добавляет в конец str_change содержание str_add
char *s21_strcat(char *str_change, char *str_add) {
	return(s21_strncat(str_change, str_add, s21_strlen(str_change) + s21_strlen(str_add)));
}

//фун-ия добавляет в конец str_change содержание str_add не более n байт 
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) {
	size_t len_str_change = strlen(str_change);
	int i = 0;
	while(str_add[i] != '\0' && i < n) {
		str_change[len_str_change + i] = str_add[i]; 
		i++;
	}
	str_change[len_str_change + i] = '\0';
	return str_change;
}
//выводит сообщение об ошибке (для линукса и мак ос разные)
//заменить спринтф на с21_спринтф!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
char *s21_strerror(int errnum) { 
	static char res[50] = {0};
	if(errnum >= 0 && errnum < AMOUNT_ERRORS) {
		strcpy(res, errors[errnum]);
	} else {
		sprintf(res, "Unknown error: %d", errnum);
	}
	return res;
}
// Сравнивает строку, на которую указывает str1, 
//cо строкой, на которую указывает str2. 
int s21_strcmp(char *str1, char *str2) {
    int result = 0;
    char *p_1 = str1;
    char *p_2 = str2;

    while (*p_1 == *p_2) {
        p_1++;
        p_2++;
        if (*p_1 == '\0' || *p_2 == '\0') {
            break;
        }
    }
    if (*p_1 != '\0' && *p_2 != '\0') {
        result = *p_1 - *p_2;
    } else if (*p_1 == '\0') {
        result = -*p_2;
    } else if (*p_2 == '\0') {
        result = *p_1;
    }
    return result;
}
// Сравнивает строку, на которую указывает str1, 
//со строкой, на которую указывает str2
int s21_strncmp(char *str1, char *str2, size_t n) {
    int result = 0;
    unsigned char *p_1 = str1;
    unsigned char *p_2 = str2;

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

char *s21_strstr(char *haystack, char *needle) {
    char *str = haystack;

    if (*needle == '\0')
        return str;
    
    char *p_1 = str;
    char *p_2 = needle;

    for (; *str != '\0'; str++) {
        if (*str == *p_2) {
            p_1 = str;
            while (*p_1 == *p_2) {
                if (*p_2 == '\0')
                    break;
                p_1++; p_2++;
            }
            if (*p_2 == '\0')
                return str;
            else {
                p_2 = needle;
            }
        }
    }

    return NULL;
}
