#pragma once 

#define s21_size_t unsigned long long 
#define s21_NULL (void*)0

#include <stdio.h>
#include <string.h>

#include "s21_errors.h"

s21_size_t s21_strlen(char *string);
<<<<<<< HEAD
void s21_strcmp(char *str_one, char *str_two);
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 006930ffad820ad7b14d461d3aa6dba9e7b70be7
void s21_strtok(char *string, char *delim);
char s21_strcat(char *str_change, char *str_add);
void s21_strncat(char *restrict s1, char *restrict s2, s21_size_t n);
char s21_strerror(int errnum); 
>>>>>>> test
void *s21_memchr(void const *str, int c, size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
<<<<<<< HEAD
int enum_delim(char str, const char *delim); 
char *s21_strtok(char *str, const char *delim);
char *s21_strcat(char *str_change, char *str_add);
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) ;
char *s21_strerror(int errnum);
=======
<<<<<<< HEAD
=======
char s21_strtok(char *string, char *delim); 
char *s21_strcat(char *str_change, char *str_add);
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) ;
char *s21_strerror(int errnum); 
int s21_strcmp(char *str_one, char *str_two);
>>>>>>> vlad
=======
char *s21_strtok(char *string, char *delim); 
char *s21_strcat(char *str_change, char *str_add);
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) ;
char *s21_strerror(int errnum); 
>>>>>>> vlad
=======
 
int s21_memcmp(void *str1, void *str2, size_t n);  // Сравнивает первые n байтов str1 и str2. | 

int s21_strcmp(char *str1, char *str2);  /* Сравнивает строку, на которую указывает str1, 
                                                        со строкой, на которую указывает str2. */
                                                        
int s21_strncmp(char *str1, char *str2, size_t n);  // Сравнивает не более первых n байтов str1 и str2. |

>>>>>>> 006930ffad820ad7b14d461d3aa6dba9e7b70be7
>>>>>>> test
