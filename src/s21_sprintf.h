#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

/* bit field for flags */
/*typedef struct flags {
  unsigned int minus : 1; //int fill_left;  // выравнивание по левому краю
  unsigned int plus : 1;  //int signed_conversion;  // указываем знак для любых чтсел
  unsigned int space : 1;
  unsigned int sharp : 1;
  unsigned int zero : 1;
} Flags;*/


typedef struct s21 {
  int percent;     // флаг для повторного символа %
  int fill_left;  // выравнивание по левому краю
  int signed_conversion;  // указываем знак для любых чтсел
  int space_signed_conversion;  // если число положительное, и мы не указали,
                                // что нам нужно явно указать знак,то у
                                // положительных чисел на месте знака будет
                                // пробел
  int width;        // ширина
  int floating;     // точность
  int h_flag;       // шорт инт
  int l_flag;       // лонг инт
  int need_prefix;  // нужно для не десятичной
  int L_flag;
} s21;

int s21_sprintf(char* buf, const char* format, ...);

void flag_x(s21* sh21, char* temp, char* buf, char* result, unsigned int d,
            int shift);
void flag_o(s21* sh21, char* temp, char* buf, char* result, long int d);
void flag_p(s21* sh21, char* temp, char* buf, char* result, long int d);
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
char* s21_float_to_string(long double number, int floating, int need_prefix);
char* s21_uint_to_string(unsigned long long number, long int floating);
void s21_reset_struct(s21* sh21);
void fill_result(char* buf, char* result, s21* sh21);
void numbers(const char* line, s21* sh21);
void insert_and_free(s21* sh21, char* temp, char* buf, char* result);
char* s21_add_spaces(char* line, s21* sh21);

char* s21_hexadecimal_to_string(long int number, long int floating, int shift,
                                int need_prefix);
char* s21_octal_to_string(long int number, long int floating, int need_prefix);

char* handler_flag_g(long double num, s21* s21, char line);
void flag_g(s21* sh21, char* temp, char* buf, char* result, long double f,
            char line);

void flag_e(s21* s21, char* temp, char* buf, char* result, long double f,
            char line);
char* handler_flag_e(long double num, int floating, char line, s21* sh21);

#endif  // SRC_S21_SPRINTF_H_
