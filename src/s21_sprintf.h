#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

<<<<<<< HEAD
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
=======
#include "s21_string.h"

>>>>>>> vlad
typedef struct s21 {
  int format;     // флаг для повторного символа %
  int fill_left;  // выравнивание по левому краю
  int signed_conversion;  // указываем знак для любых чтсел
  int space_signed_conversion;  // если число положительное, и мы не указали,
                                // что нам нужно явно указать знак,то у
                                // положительных чисел на месте знака будет
                                // пробел
  int width;     // ширина
  int floating;  // точность
  int h_flag;    // шорт инт
  int l_flag;    // лонг инт
<<<<<<< HEAD
  int need_prefix; // нужно для не десятичной залупы
  //  char* pointer;
  // int fillnull;  // Влад, посмотри
} s21;

int s21_sprintf(char* buf, const char* format, ...);
=======
<<<<<<< HEAD
  int L_flag;
=======
  int L_flag;    // long double
  //  char* pointer;
>>>>>>> 9e2a956527c52d98bd19e428f9c94c2adb0d5107
  // int fillnull;  // Влад, посмотри
} s21;

>>>>>>> vlad
void flag_i_d(s21* sh21, char* temp, char* buf, char* result, long int d);
void flag_f(s21* sh21, char* temp, char* buf, char* result, long double f);
void flag_c(s21* sh21, char* buf, char* result, wchar_t symbol);
void flag_s(s21* sh21, char* string, char* buf, char* result);
void flag_u(s21* sh21, char* temp, char* buf, char* result, uint64_t u);
char* revers(char* str, int i);
char* s21_int_to_string(long int number, long int floating);
char* s21_add_sign(char* dest, char* src, int signed_conversion,
                   int space_signed_conversion, long int number);
char* s21_add_zero(char* dest, char* src, int floating);
int s21_pow(int x, int y);
int s21_round(double y);
<<<<<<< HEAD
char* s21_float_to_string(long double number, int floating, int need_prefix);
=======
char* s21_float_to_string(long double number, int floating);
>>>>>>> vlad
char* s21_uint_to_string(unsigned long long number, long int floating);
void s21_reset_struct(s21* sh21);
void fill_result(char* buf, char* result, s21* sh21);
void numbers(const char* line, s21* sh21);
void insert_and_free(s21* sh21, char* temp, char* buf, char* result);
char* s21_add_spaces(char* line, s21* sh21);
<<<<<<< HEAD
=======

char* handler_flag_g(long double num, s21* s21, char line);
void flag_g(s21 *sh21, char *temp, char *buf, char *result, long double f, char line);

void flag_e(s21 *s21, char* temp, char* buf, char* result, long double f, char line);
char* handler_flag_e(long double num, int floating, char line);

>>>>>>> vlad
#endif  // SRC_S21_SPRINTF_H_