#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

/* bit field for flags */
typedef struct {
  bool fill_left : 1;     //-
  bool show_sign : 1;     // +
  bool hide_sign : 1;     // space
  bool oxefg_format : 1;  // #
  bool zero_fill : 1;     // 0
} Flags;

typedef struct {
  int width;
  int precision;
  bool arg_width;      // for * width in additiona argument
  bool arg_precision;  // for .* precision in additiona argument
  char length;
} Wid_prec_len;

int s21_sprintf(char* buf, const char* format, ...);

// void flag_x(s21* sh21, char* temp, char* buf, char* result, unsigned int d,
//             int shift);
// void flag_o(s21* sh21, char* temp, char* buf, char* result, long int d);
// void flag_p(s21* sh21, char* temp, char* buf, char* result, long int d);
// void flag_f(s21* sh21, char* temp, char* buf, char* result, long double f);
// void flag_c(s21* sh21, char* buf, char* result, wchar_t symbol);
// void flag_s(s21* sh21, char* string, char* buf, char* result);
// void flag_u(s21* sh21, char* temp, char* buf, char* result, uint64_t u);
// int s21_pow(int x, int y);
// int s21_round(double y);
// char* s21_float_to_string(long double number, int floating, int need_prefix);
// char* s21_uint_to_string(unsigned long long number, long int floating);
// void numbers(const char* line, s21* sh21); //TODO detele?

// char* s21_hexadecimal_to_string(long int number, long int floating, int
// shift,
//                                 int need_prefix);
// char* s21_octal_to_string(long int number, long int floating, int
// need_prefix);

// char* handler_flag_g(long double num, s21* s21, char line);
// void flag_g(s21* sh21, char* temp, char* buf, char* result, long double f,
//             char line);

// void flag_e(s21* s21, char* temp, char* buf, char* result, long double f,
//             char line);
// char* handler_flag_e(long double num, int floating, char line, s21* sh21);

#endif  // SRC_S21_SPRINTF_H_
