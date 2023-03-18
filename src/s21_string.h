#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_size_t unsigned long
#define s21_NULL (void *)0

#include <math.h>  //sscanf
#include <stdarg.h>
#include <stdbool.h>  //sscanf
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0  // for errors
#define ER 1  //

/* common funcs */
bool is_digit(char ch);
bool is_whitespace(char ch);
bool isnt_whitespace(char ch);
bool isnt_end(char ch);
int skip(const char **string,
         bool (*skip_cond)(
             char));  // skips the characters that the skip_cond defines
long str_to_dec(const char **string, int width, int sign, int count, int *err);


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
