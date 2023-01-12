#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *s21_case_change(const char *str, int ot, int d0, int shift) {
  char *ptr = NULL;
  if (str) {
    ptr = calloc(strlen(str) + 1, sizeof(char));
    if (ptr) {
      strcpy(ptr, str);

      for (int i = 0; i < strlen(str); i++) {
        if (ptr[i] >= ot && ptr[i] <= d0) {
          ptr[i] += shift;
        }
      }
    }
  }
  return ptr;
}

void *s21_to_lower(const char *str) { return s21_case_change(str, 65, 90, 32); }

// переводит str в верхний регистр
void *s21_to_upper(const char *str) {
  return s21_case_change(str, 97, 122, -32);
}

// вставляет str в src на позицию start_index при условии, что
// start_index <= длины src
void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *ptr = NULL;
  size_t lenSrc = strlen(src);
  size_t lenStr = strlen(str);
  if (str && start_index <= lenSrc) {
    ptr = calloc(lenSrc + lenStr + 1, sizeof(char));
    if (ptr) {
      strcpy(ptr, src);
      memmove(ptr + start_index + lenStr, ptr + start_index,
              lenSrc - start_index);
      memmove(ptr + start_index, str, lenStr);
    }
  }
  return ptr;
}
char *s21_End(char *ptr, const char *trim_chars) {
  size_t lenPtr = strlen(ptr);
  size_t lenTrim = strlen(trim_chars);
  for (size_t i = lenPtr - 1; i; i--) {
    int count = 0;
    for (size_t j = 0; j < lenTrim; j++) {
      if (ptr[i] == trim_chars[j]) {
        count++;
        break;
      }
    }
    if (count) {
      ptr[i] = '\0';
    } else {
      break;
    }
  }
  return ptr;
}
// удаляет с обеих сторон src trim_chars
void *s21_trim(const char *src, const char *trim_chars) {
  char *ptr = NULL;
  if (src) {
    ptr = calloc(strlen(src) + 1, sizeof(char));
    if (ptr) {
      src += strspn(src, trim_chars);
      strcpy(ptr, src);
      if (strlen(ptr) > 0) {
        s21_End(ptr, trim_chars);
      }
    }
  }
  return ptr;
}

void main() {
  char s[] =
      "govno zalupa penis xer davlka xui blyadina. GOLOVKA SHLYUXA JOPA CHLEN "
      "EBLAN PETUX MUDILA  ";
  char *s1;
  s1 = s21_to_lower(s);
  printf("%s\n", s1);
  s1 = s21_to_upper(s);
  printf("%s\n", s1);
  char charsToTrim2[] = "1";
  char s2[] = "*123xyz********c******c";
  s1 = s21_trim(s2, charsToTrim2);
  printf("%s", s1);
}
