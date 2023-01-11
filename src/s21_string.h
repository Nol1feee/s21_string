#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_size_t unsigned long   
#define s21_NULL (void*)0

#include <stdio.h>
// DELETE LATER ->
#include <string.h>
s21_size_t s21_strlen(char *string); //done
char *s21_strcat(char *str_change, char *str_add);//done
int enum_delim(char str, const char *delim); 
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);//done
char *s21_strncat(char *str_change, char *str_add, s21_size_t n);//done
void *s21_memchr(const void *str, int c, size_t n);//done
char *s21_strchr(const char *str, int c);//done
char *s21_strpbrk(const char *str1, const char *str2);//done
char *s21_strrchr(const char *str, int c);//done
int s21_memcmp(void *str1, void *str2, size_t n);
int s21_strcmp(char *str1, char *str2);
int s21_strncmp(char *str1, char *str2, size_t n);
s21_size_t s21_strspn(const char *string1, const char *string2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strstr(char *haystack, char *needle);
//функции Егора
#endif  // SRC_S21_STRING_H_