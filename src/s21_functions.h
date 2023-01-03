#pragma once 

#define s21_size_t unsigned long long 
#define s21_NULL (void*)0

#include <stdio.h>
#include <string.h>

#include "s21_errors.h"

s21_size_t s21_strlen(char *string);
char *s21_strtok(char *string, char *delim); 
char *s21_strcat(char *str_change, char *str_add);
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) ;
char *s21_strerror(int errnum); 
int s21_strcmp(char *str_one, char *str_two);
