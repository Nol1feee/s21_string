#define s21_size_t unsigned long long 
#define s21_NULL (void*)0

#include <stdio.h>
#include <string.h>
#include "s21_errors.h"

s21_size_t s21_strlen(char *string);
void s21_strcmp(char *str_one, char *str_two);
void *s21_memchr(void const *str, int c, size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
int enum_delim(char str, const char *delim); 
char *s21_strtok(char *str, const char *delim);
char *s21_strcat(char *str_change, char *str_add);
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) ;
char *s21_strerror(int errnum);