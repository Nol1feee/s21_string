#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_size_t unsigned long
#define s21_NULL (void *)0

#include <limits.h>
#include <math.h>  //sscanf
#include <stdarg.h>
#include <stdbool.h>  //sscanf
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0  // for errors
#define ER 1  //
#define SPACE 32

/* for specifiers */
enum {
  spec_c = 1 << 0,
  spec_d = 1 << 1,
  spec_i = 1 << 2,
  spec_e = 1 << 3,
  spec_E = 1 << 4,
  spec_f = 1 << 5,
  spec_g = 1 << 6,
  spec_G = 1 << 7,
  spec_o = 1 << 8,
  spec_s = 1 << 9,
  spec_u = 1 << 10,
  spec_x = 1 << 11,
  spec_X = 1 << 12,
  spec_p = 1 << 13,
  spec_n = 1 << 14,
  spec_percent = 1 << 15
};

/* for shifts */
enum {
  SHIFT_zero = 48, /* code of 0 in ASCII */
  SHIFT_HEX = 55,  /* code of A - 10 in ASCII */
  SHIFT_hex = 87,  /* code of a - 10 in ASCII */
  SHIFT_case = 32  /* difference between A(65) and a(97)*/
};

/* common funcs */
bool is_digit(char ch);
bool is_whitespace(char ch);
bool isnt_whitespace(char ch);
bool isnt_end(char ch);
int skip(const char **string,
         bool (*skip_cond)(
             char));  // skips the characters that the skip_cond defines
long str_to_dec(const char **string, int width, int sign, int count, int *err);
int set_specs(const char **format, _Bool *ass_supress, int *width, int *length,
              int *err);

s21_size_t s21_strlen(const char *string);          // done
char *s21_strcat(char *str_change, char *str_add);  // done
int enum_delim(char str, const char *delim);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);                                          // done
char *s21_strncat(char *str_change, const char *str_add, s21_size_t n);  // done
void *s21_memchr(const void *str, int c, size_t n);                      // done
char *s21_strchr(const char *str, int c);                                // done
char *s21_strpbrk(const char *str1, const char *str2);                   // done
char *s21_strrchr(const char *str, int c);                               // done
int s21_memcmp(void *str1, void *str2, size_t n);
int s21_strcmp(char *str1, char *str2);
int s21_strncmp(char *str1, char *str2, size_t n);
s21_size_t s21_strspn(const char *string1, const char *string2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strstr(char *haystack, char *needle);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, size_t n);
void *s21_memset(void *dest, int fill, size_t n);
char *s21_strcpy(char *restrict dst, const char *restrict src);
char *s21_strncpy(char *restrict dst, const char *restrict src, size_t n);

void *s21_case_change(const char *str, int ot, int d0, int shift);

void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);

int s21_sprintf(char *buf, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

#endif  // SRC_S21_STRING_H_
