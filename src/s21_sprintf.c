#include "s21_sprintf.h"                                               

/* reset values in structures */
static void reset(Wid_prec_len* wpl, Flags* flag) {
  wpl->width = 0;
  wpl->precision = 0;
  wpl->length = 0;
  s21_memset(flag, 0, sizeof(Flags));  // reset flag
}

/* check if it's a flag */
static bool is_flag(const char ch) {
  return (ch == '-' || ch == '+' || ch == ' ' || ch == '#' || ch == '0')
             ? true
             : false;
}

/* check if it's a length */
static bool is_length(char ch) {
  return (ch == 'h' || ch == 'l' || ch == 'L') ? true : false;
}

/*
get flags from format string for current argument
stops at the first ch after flags
*/
void get_flags(const char** format, Flags* flag) {
  while (is_flag(**format)) {
    switch (**format) {
      case '-':
        flag->fill_left = true;
        break;
      case '+':
        flag->show_sign = true;
        break;
      case ' ':
        flag->hide_sign = true;
        break;
      case '#':
        flag->oxefg_format = true;
        break;
      case '0':
        flag->zero_fill = true;
        break;
    }
    (*format)++;
  }
  return;
}

/* git specifier from format string */
static int set_specs_printf(const char** format, int* err) {
  int specs = 0;
  switch (**format) {
    case 'c':
      specs |= spec_c;
      break;
    case 'd':
      specs |= spec_d;
      break;
    case 'i':
      specs |= spec_i;
      break;
    case 'e':
      specs |= spec_e;
      break;
    case 'E':
      specs |= spec_E;
      break;
    case 'f':
      specs |= spec_f;
      break;
    case 'g':
      specs |= spec_g;
      break;
    case 'G':
      specs |= spec_G;
      break;
    case 'o':
      specs |= spec_o;
      break;
    case 's':
      specs |= spec_s;
      break;
    case 'u':
      specs |= spec_u;
      break;
    case 'x':
      specs |= spec_x;
      break;
    case 'X':
      specs |= spec_X;
      break;
    case 'p':
      specs |= spec_p;
      break;
    case 'n':
      specs |= spec_n;
      break;
    case '%':
      specs |= spec_percent;
      break;

    default:
      // TODO:handle an error and delete this huety
      fprintf(stderr, "Incorrect specifier %c\n", **format);
      *err = ER;
  }
  (*format)++;
  return specs;
}

/* add ch into the buf and '\0' after it */
static void add_to_buf(char* buf, char ch, int* counter) {
  buf[*counter] = ch;
  (*counter)++;
  buf[*counter] = '\0';
}

/* put spaces for justification */
static int fill_width(char* buf, int width, int ch, int* counter) {
  int i = 0;
  for (i = 0; i < width; i++) {
    add_to_buf(buf, ch, counter);
  }
  return i;
}

/* handling %c */
static void print_c(char* buf, Flags* flag, Wid_prec_len* wpl, char ch,
                    int* counter, int* err) {
  if (wpl->width) {
    if (flag->fill_left) {
      add_to_buf(buf, ch, counter);
      fill_width(buf, wpl->width - 1, SPACE, counter);
    } else {
      fill_width(buf, wpl->width - 1, SPACE, counter);
      add_to_buf(buf, ch, counter);
    }
  } else {
    add_to_buf(buf, ch, counter);
  }
  // TODO handle errors
  if (*err) {
    //
  }
  reset(wpl, flag);
}

/* count digits in the number */
static int count_digits(long num) {
  int res = 0;
  if (!num) {
    res = 1;
  } else {
    while (num > 0) {
      num /= 10;
      res++;
    }
  }
  return res;
}

/* add decimal integer into output buffer */
static void add_dec(char* buf, long num, int* counter, int digits, int* err) {
  if (*err != VOID_PRECISION || num != 0) {
    for (int pow10 = digits - 1; pow10 > 0; pow10--) {
      add_to_buf(buf, num / (long)pow(10, pow10) + SHIFT_zero, counter);
      num %= (long)pow(10, pow10);
    }
    if (*err == LONG_MIN_CASE) {
      add_to_buf(buf, num + 1 + SHIFT_zero, counter);
    } else {
      add_to_buf(buf, num + SHIFT_zero, counter);
    }
  } 
}

/* add sign into output buffer */
static int add_sign(char* buf, Flags* flag, int sign, int* counter) {
  if (sign == MINUS) {
    add_to_buf(buf, sign, counter);
  }
  if (flag->show_sign && ((sign == MINUS && *buf != MINUS) || sign == PLUS)) {
    add_to_buf(buf, sign, counter);
  }
  if (flag->hide_sign && sign == PLUS) {
    add_to_buf(buf, SPACE, counter);
  }
  return 1;
}

/* get the sign and make the number positive */
static int int_sign_check(long *num) {
  int sign = MINUS;
  if (*num < 0) {
    *num *= -1;
  } else {
    sign = PLUS;
  }
  return sign;
}

/* add an integer with left alignment */
static void left_int_addition(char *buf, Wid_prec_len *wpl, Flags *flag, 
                              long num, int sign, int digits, int *zeros, 
                              int *counter, int *err) {
  add_sign(buf, flag, sign, counter); /* add sign into buf */
  /* fill the buf by zeros if needed */
  *zeros = fill_width(buf, wpl->precision - digits, ZERO, counter);
  /* add decimal number into the buf */
  add_dec(buf, num, counter, digits, err);
  /* determine if we need to add or remove space for sign */
  int sign_ch = (flag->hide_sign) ? 1 : (sign == MINUS) ? 1 : 0;
  /* fill remain width by whitespaces */
  fill_width(buf, wpl->width - digits - sign_ch - *zeros, SPACE, counter);
}

/* add an integer with right alignment */
static void right_int_addition(char *buf, Wid_prec_len *wpl, Flags *flag, 
                              long num, int sign, int digits, 
                              int *counter, int *err) {
  /* if there is zero_fill flag then add sign before the zeroes
   * else add sign after spaces */
  if (flag->zero_fill) {
    add_sign(buf, flag, sign, counter);
  }
  /* choose the aggregate */
  int aggregate = (flag->zero_fill) ? ZERO : SPACE;
  /* fill the buf before the number */
  fill_width(buf, wpl->width - digits - wpl->precision - ((sign == MINUS) ? 1 : 0), 
               aggregate, counter);
  /* if there was a sign then we don't need to add this one again
   * else we need to add sign */
  if (!flag->zero_fill) {
    add_sign(buf, flag, sign, counter);
  }
  /* if precision has been added fill the remain width before 
   * the number by zeros */
  fill_width(buf, wpl->precision - digits, ZERO, counter);
  /* add number into the buf */
  add_dec(buf, num, counter, digits, err);
}

/* handling %d and %i */
static void handle_di(char* buf, Wid_prec_len* wpl, Flags* flag, long num,
                     int* counter, int* err) {
  /* check for the LONG_MIN */
  if (num == LONG_MIN) {
    num++; /* increase by 1 to make it positive */
    *err = LONG_MIN_CASE; /* note that LONG_MIN */
  }
  /* count the number of digits */
  int digits = count_digits((num < 0) ? num * -1 : num);
  /* if we have void precision and num ==0 then we won't add 0 into the buf */
  digits = (*err == VOID_PRECISION && num == 0) ? 0 : digits;
  /* get the sign and make the number positive */
  int sign = int_sign_check(&num); 
  int zeros = 0; /* keeps the number of zeros that had added into the buf */
  if (wpl->width) { /* if a width has been entered */
    if (flag->fill_left) { /* if a '-' flag has been entered */
      left_int_addition(buf, wpl, flag, num, sign, digits, &zeros, counter, err);
    } else {
      right_int_addition(buf, wpl, flag, num, sign, digits, counter, err);
    }
  } else {
    right_int_addition(buf, wpl, flag, num, sign, digits, counter, err);
  }
  if (*err) {
  // TODO handle errors
  }
  reset(wpl, flag);
}


/*char* handler_flag_e(long double num, int floating, char format, s21* sh21) {
  int point = (floating == -1) ? 6 : floating;
  int count_e = 0;
  if ((int)num == 0) {
    while ((int)num == 0) {
      num *= 10;
      count_e--;
    }
  } else {
    while ((int)num > 9) {
      num /= 10;
      count_e++;
    }
  }
  char* str = s21_float_to_string(num, point, sh21->need_prefix);
  if (count_e < 0 && format == 'e') s21_strcat(str, "e-");
  if (count_e < 0 && format == 'E') s21_strcat(str, "E-");
  if (count_e > 0 && format == 'e') s21_strcat(str, "e+");
  if (count_e > 0 && format == 'E') s21_strcat(str, "E+");
  if (count_e < 0) count_e *= -1;
  if (count_e < 10) s21_strcat(str, "0");
  char* clean = s21_int_to_string(count_e, floating);
  s21_strcat(str, clean);
  free(clean);
  return str;
}*/

/* returns current digit in num */
static int get_digit(long double *num) {
  int digit = (int)(*num);
  *num -= digit;
  *num *= 10;
  return digit;
}

/* rounded num that had added into the buf */
static void round_buf(char *buf, int counter) {
  if (buf[counter - 1] < 9) {
    buf[counter - 1]++;
  } else {
    printf("last_buf = %c\n", buf[counter - 1]);
    round_buf(buf, counter - 1);
    buf[counter - 1] = ZERO;
  }
}

/* returns current digit in num after rounding */
static int get_round_digit(char *buf, long double *num, int *counter) {
  int cur_digit = get_digit(num);
  int next_digit = get_digit(num);
  if (next_digit >= 5) {
    cur_digit++;
  }
  if (cur_digit == 10) {
    // RECURSIVE ???? change last digit in buf
    round_buf(buf, *counter);
    cur_digit = 0;
  }
  return cur_digit;
}
/* handles the %e specifier */
static void handle_e(char* buf, Wid_prec_len* wpl, Flags* flag, long double num,
                     int* counter, int* err) {
  int sign = 0; // keeps the sign
  int exp = 0; // keeps the exponent
  // remember sign and make the number positive
  if (num < 0) {
    sign = MINUS;
    num *= -1;
  } else {
    sign = PLUS;
  }
  add_sign(buf, flag, sign, counter);
  // determine where we will move the point
  if (num < 1) {
    //then move to the right while num < 1
    while (num < 1) {
      num *= 10;
      exp--;
    }
    //print first digit into the buf
    add_to_buf(buf, get_digit(&num) + SHIFT_zero, counter);
    //print '.' into the buf
    add_to_buf(buf, DOT, counter);
    //print remain digits of the number into the buf
    int digits = 0;
    //if width not given then set it in standard width (6)
    wpl->width = (wpl->width) ? wpl->width : 6;
    while(digits < wpl->width || !wpl->width) {
      // if pre-last digit then we need to round number
      if (digits == wpl->width - 1) {
        add_to_buf(buf, get_round_digit(buf, &num, counter) + SHIFT_zero, counter);
      } else {
        (num > 0) ? add_to_buf(buf, get_digit(&num) + SHIFT_zero, counter) : 
                    add_to_buf(buf, ZERO, counter);
      }
      digits++;
    }

    
  } else {
    //then move to the left
  }
  // what if num == 1 ???
  if (*err == ER) {
    // handle the error
  }

  // old 
  /*temp = handler_flag_e(f, s21->floating, format, s21);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));

  result = s21_add_sign(result, temp, s21->signed_conversion,
                        s21->space_signed_conversion, f);
  insert_and_free(s21, temp, buf, result);*/
}

/* processes the source string according to the specifiers */
static void print_processing(char* buf, int specs, int* counter, va_list* param,
                      Wid_prec_len* wpl, Flags* flag, int* err) {
  long num;  // for %d %i
  long double fnum;        // for %e
  char ch;   // for %c
  // char* string;         // TODO for what?
  // uint64_t u;           // TODO for what?
  if ((specs & spec_d) || (specs & spec_i)) {
    if (wpl->length == 'h') {
      num = (short)va_arg(*param, int);
    } else if (wpl->length == 'l') {
      num = va_arg(*param, long);
    } else {
      num = va_arg(*param, int);
    }
    handle_di(buf, wpl, flag, num, counter, err);
  } else if (specs & spec_c) {
    ch = (char)va_arg(*param, int);
    print_c(buf, flag, wpl, ch, counter, err);
  } else if (specs & spec_e) {
    if (wpl->length == 'l') {
      fnum = va_arg(*param, long double);
    } else {
      fnum = va_arg(*param, double);
      handle_e(buf, wpl, flag, fnum, counter, err);
    }
  } else {
    *err = ER;
  }
  /*} else if ((specs & spec_x) || (specs & spec_X)) {  // 16-ричное число инт
    d = va_arg(*param, uint64_t);
    flag_x(sh21, temp, buf, result, d, 'x' - *format);
  } else if ((specs & spec_p)) {
    d = va_arg(*param, uint64_t);
    flag_p(sh21, temp, buf, result, d);
  } else if ((specs & spec_o)) {  // 8-ричное число инт
    d = (unsigned int)va_arg(*param, uint64_t);
    flag_o(sh21, temp, buf, result, d);
  } else if ((specs & spec_c)) {
    d = va_arg(*param, int);
    flag_i_d(sh21, temp, buf, result, d);
  } else if ((specs & spec_f)) {
    if (sh21->L_flag) {
      f = va_arg(*param, long double);
    } else {
      f = va_arg(*param, double);
    }
    flag_f(sh21, temp, buf, result, f);
  }  else if ((specs & spec_s)) {
    string = va_arg(*param, char*);
    flag_s(sh21, string, buf, result);
  } else if ((specs & spec_u)) {
    u = va_arg(*param, uint64_t);
    flag_u(sh21, temp, buf, result, u);
  } else if ((specs & spec_g) || (specs & spec_G)) {
    if (sh21->L_flag == 1) {
      f = va_arg(*param, long double);
    } else {
      f = va_arg(*param, double);
      flag_g(sh21, temp, buf, result, f, *format);
    }
  } else if ((specs & spec_n)) {
    int* count = va_arg(*param, int*);
    *count = *count_char;
    fill_result(buf, result, sh21);
  }*/
}

/*
get width and precision from format string for current arg
stops at the first ch after width or precision
*/
static void get_width_precision(const char** format, va_list* param,
                                int* num_value, int* err, int opt) {
  if (**format == '*') {
    (*format)++;
    *num_value = va_arg(*param, int);
  } else {
    /* get width (str, width, sign, count, err);*/
    *num_value = str_to_dec(format, 0, 1, 0, err); 
  }
  if ((opt == PRECISION) && !(*num_value)) {
    *err = VOID_PRECISION;
  }
}

/*
get length
stops at the first ch after length character
*/
static char get_length(const char** format) {
  char res = 0;
  if (is_length(**format)) {
    res = **format;
    (*format)++;
  }
  return res;
}

/* the main sprintf function */
int s21_sprintf(char* buf, const char* format, ...) {
  *buf = 0;
  int err = OK;  // for errors
  va_list param;
  va_start(param, format);
  int counter = 0;             // for %n
  bool is_spec_start = false;  // for tracking start of specifiers (%)
  Flags flag;
  Wid_prec_len wpl;
  reset(&wpl, &flag);

  while (*format) {
    if (!is_spec_start && *format != '%') {  // if we met a regular ch
      add_to_buf(buf, *format, &counter);    // add current character into buf
      format++;
      // if we met % for the first time
    } else if (!is_spec_start && *format == '%') {
      is_spec_start = true;  // treats current '%' as start of format specifier
      format++;
    } else if (is_spec_start) {  // start specificator processing
      get_flags(&format, &flag);
      get_width_precision(&format, &param, &wpl.width, &err, WIDTH);
      printf("width = %d\n", wpl.width);
      // may be add hiding for this with get_precision() ?
      if (*format == '.') {
        format++;
        get_width_precision(&format, &param, &wpl.precision, &err, PRECISION);
        printf("precision = %d\n", wpl.precision);
      }
      wpl.length = get_length(&format);
      int specs = set_specs_printf(&format, &err); /* fill the specs number */
      print_processing(buf, specs, &counter, &param, &wpl, &flag, &err);
      reset(&wpl, &flag);
      is_spec_start = false;
    }
  }
  va_end(param);
  return counter;
}

/*
void flag_g(s21* sh21, char* temp, char* buf, char* result, long double f,
            char format) {
  temp = handler_flag_g(f, sh21, format);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_sign(result, temp, sh21->signed_conversion,
                        sh21->space_signed_conversion, f);
  insert_and_free(sh21, temp, buf, result);
}

char* handler_flag_g(long double num, s21* s21, char format) {
  int point = (s21->floating != -1) ? s21->floating : 6;
  int count_e = 0;
  long double copy = num;
  if ((int)num == 0) {
    while ((int)num == 0) {
      num *= 10;
      count_e--;
    }
  } else {
    while ((int)num > 9) {
      num /= 10;
      count_e++;
    }
  }
  char* str = s21_float_to_string(num, point - 1, s21->need_prefix);
  if ((count_e > 0) ? (count_e) : (count_e * -1) > point) {
    if (!s21->need_prefix) {
      for (int i = s21_strlen(str); str[i - 1] == '0'; i--) str[i - 1] = '\0';
    }
    for (int i = s21_strlen(str); str[i - 1] == '0'; i--) str[i - 1] = '\0';
    if (count_e < 0 && format == 'g') s21_strcat(str, "e-");
    if (count_e < 0 && format == 'G') s21_strcat(str, "E-");
    if (count_e > 0 && format == 'g') s21_strcat(str, "e+");
    if (count_e > 0 && format == 'G') s21_strcat(str, "E+");
    if (count_e < 10) s21_strcat(str, "0");
    char* clear = s21_int_to_string(count_e, s21->floating);
    s21_strcat(str, clear);
    free(clear);
  } else {
    str = s21_float_to_string(
        copy, point - (count_e < 0 ? (1 + count_e * -1) : 1 + count_e),
        s21->need_prefix);
    for (int i = s21_strlen(str); str[i - 1] == '0'; i--) str[i - 1] = '\0';
  }
  return str;
}

void flag_x(s21* sh21, char* temp, char* buf, char* result, unsigned int d,
            int shift) {
  temp = s21_hexadecimal_to_string(d, sh21->floating, shift,
sh21->need_prefix); result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, sh21->floating);
  insert_and_free(sh21, temp, buf, result);
}

void flag_o(s21* sh21, char* temp, char* buf, char* result, long int d) {
  temp = s21_octal_to_string(d, sh21->floating, sh21->need_prefix);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, sh21->floating);
  insert_and_free(sh21, temp, buf, result);
}

void flag_p(s21* sh21, char* temp, char* buf, char* result, long int d) {
  temp = s21_hexadecimal_to_string(d, sh21->floating, 0, 1);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, sh21->floating);
  insert_and_free(sh21, temp, buf, result);
}

void flag_f(s21* sh21, char* temp, char* buf, char* result, long double f) {
  temp = s21_float_to_string(f, sh21->floating, sh21->need_prefix);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));

  result = s21_add_sign(result, temp, sh21->signed_conversion,
                        sh21->space_signed_conversion, f);
  insert_and_free(sh21, temp, buf, result);
}*/

/*void flag_s(s21* sh21, char* string, char* buf, char* result) {
  int input_len = s21_strlen(string);
  if (sh21->floating < input_len && sh21->floating >= 0)
    input_len = sh21->floating;
  int output_len = sh21->width > input_len ? sh21->width : input_len;
  int padding_len = 0 > sh21->width - input_len ? 0 : sh21->width - input_len;
  result = calloc(output_len + 1, sizeof(char));
  result[output_len] = '\0';
  char* s_ptr;
  char* p_ptr;
  if (sh21->fill_left == 1) {
    s_ptr = &result[0];
    p_ptr = &result[input_len];
  } else {
    s_ptr = &result[padding_len];
    p_ptr = &result[0];
  }
  s21_memset(p_ptr, ' ', padding_len);
  s21_memcpy(s_ptr, string, input_len);
  fill_result(buf, result, sh21);
}*/

/*void flag_u(s21* sh21, char* temp, char* buf, char* result, uint64_t u) {
  if (sh21->h_flag) {
    u = (uint16_t)u;
  } else if (sh21->l_flag) {
    u = (uint64_t)u;
  } else {
    u = (uint32_t)u;
  }
  temp = s21_uint_to_string(u, sh21->floating);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, sh21->floating);
  insert_and_free(sh21, temp, buf, result);
}*/
/*
char* s21_hexadecimal_to_string(long int number, long int floating, int shift,
                                int need_prefix) {
  int i = 0;
  char* str = calloc(32, sizeof(char));
  if (number < 0) number *= -1;
  if (number != 0) {
    while (number > 0) {
      int c = number % 16;
      if (c >= 10) {
        c -= 10;
        c += 'a' - shift;
      } else {
        c += '0';
      }
      str[++i - 1] = c;
      number /= 16;
    }
    if (need_prefix) {
      str[i] = 'x' - shift;
      str[i + 1] = '0';
      i += 2;
    }
  } else if (floating != 0) {
    str[i] = '0';
    i += 1;
  }

  return revers(str, i);
}

char* s21_octal_to_string(long int number, long int floating, int need_prefix)
{ int i = 0; char* str = calloc(32, sizeof(char)); if (number < 0) number *=
-1; if (number != 0) { while (number > 0) { str[++i - 1] = (number % 8) + '0';
      number /= 8;
    }
    if (need_prefix) {
      str[i] = '0';
      i += 1;
    }
  } else if (floating != 0) {
    str[i] = '0';
    i += 1;
  }

  return revers(str, i);
}





int s21_pow(int x, int y) {
  int temp = x;
  for (int i = 1; i < y; i++) temp *= x;
  return temp;
}

int s21_round(double y) { return (int)(y + 0.5); }

char* s21_float_to_string(long double number, int floating, int need_prefix) {
  if (number < 0) number *= -1;
  int int_part = number;
  char* str = s21_int_to_string(int_part, 1);
  if (floating == 0) {
    const size_t offset = s21_strlen(str) - 1;
    if (int_part % 2 == 1)
      str[offset] = (((int)(number + 0.5) % 10) + '0');
    else
      str[offset] = (((int)number % 10) + '0');
    if (need_prefix) {
      str[offset + 1] = '.';
    }
  } else {
    number -= int_part;
    int f_len = (floating != -1) ? floating : 6;
    str[s21_strlen(str)] = '.';
    char* temp =
        s21_int_to_string(s21_round((1 + number) * s21_pow(10, f_len)), 1);
    for (int i = 0; i <= f_len - 1; i++) temp[i] = temp[i + 1];
    temp[f_len] = '\0';
    s21_strcat(str, temp);
    free(temp);
  }
  return str;
}

char* s21_uint_to_string(unsigned long long number, long int floating) {
  int i = 0;
  char* str = calloc(32, sizeof(char));
  if (number != 0) {
    while (number > 0) {
      str[i++] = (number % 10) + '0';
      number /= 10;
    }
  } else if (floating != 0) {
    str[i] = '0';
  }
  return revers(str, i + 1);
}*/
