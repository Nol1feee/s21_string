#include "s21_sprintf.h"

void reset(Wid_prec_len* wpl, Flags* flag) {
  wpl->width = 0;
  wpl->precision = 0;
  wpl->arg_width = false;
  wpl->arg_precision = false;
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

static char* s21_add_spaces(char* format, Flags* flag, int width) {
  int str_len = s21_strlen(format);
  if (str_len < width) {
    char* temp = calloc(width + 1, sizeof(char));
    int padding_len = width - str_len;
    char* spc_ptr = calloc(padding_len + 1, sizeof(char));
    spc_ptr[padding_len] = 0;  // Влад, посмотри
    if (flag->fill_left) {
      s21_strcat(temp, format);
      s21_strcat(temp, spc_ptr);
    } else {
      s21_strcat(temp, spc_ptr);
      s21_strcat(temp, format);
    }
    free(spc_ptr);
    free(format);
    format = temp;
  }
  return format;
}

/* modification of strnctar which doesn't remove last \0 */
static void sp_strncat(char *str_change, const char *str_add, s21_size_t n, int counter) {
  //s21_size_t len_str_change = s21_strlen(str_change);
  int len_str_change = counter;
  int i = 1;
  while (str_add[i] != '\0' && i < (int)n) {
    str_change[len_str_change + i] = str_add[i];
    i++;
  }
  str_change[len_str_change + i] = '\0';
  //return str_change;
}

/*char *sp_strcat(char *str_change, char *str_add) {
  if (!str_change[s21_strlen(str_change)] &&  !str_change[s21_strlen(str_change) - 1]) {
  return (sp_strncat(str_change, str_add,
                      s21_strlen(str_change) + s21_strlen(str_add)));
  } else {
  return (s21_strncat(str_change, str_add,
                      s21_strlen(str_change) + s21_strlen(str_add)));
  }
}*/

/* 
add new characters into buf
*/
static void add_to_buf(char *buf, const char *format, int bytes, int counter) {
  if (!buf[counter] &&  !buf[counter - 1]) {
    sp_strncat(buf, format, bytes, counter);  // add current character into buf
  } else {
    s21_strncat(buf, format, bytes);  // add current character into buf
  }
}

static void fill_result(char* buf, char* result, int *counter) {
  if (result[0] == '\0') {
    buf[*counter] = '\0'; 
  } else {
    s21_strcat(buf, result);
  }
  free(result);
}

static void insert_and_free(Wid_prec_len* wpl, Flags* flag, char* temp,
                            char* buf, char* result, int *counter) {
  s21_strcat(result, temp);
  free(temp);
  result = s21_add_spaces(result, flag, wpl->width);
  fill_result(buf, result, counter);
  //TODO reser structs
}

static char* revers(char* str, int i) {
  str[i] = '\0';
  for (int j = 0, k = s21_strlen(str) - 1, format; j < k; j++, k--) {
    format = str[j];
    str[j] = str[k];
    str[k] = format;
  }
  return str;
}

static char* s21_int_to_string(long int number, int precision) {
  int i = 0;
  // why 32?
  char* str =
      calloc(32, sizeof(char));  // TODO free!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // TODO protect calloc
  if (number < 0) number *= -1;  // make positive
  if (number != 0) {
    while (number > 0) {
      str[i++] = (number % 10) + SHIFT_zero;
      number /= 10;
    }
  } else if (precision != 0) {
    str[i] = '0';
  }
  return revers(str, i);
}

static char* s21_add_zero(char* dest, char* src, int floating) {
  if ((int)floating > (int)s21_strlen(src)) {
    size_t k = s21_strlen(dest);
    if (s21_strlen(dest)) floating++;
    dest = realloc(dest, (floating + 1) * sizeof(char));
    for (; k < (floating - s21_strlen(src)); k++) s21_strcat(dest, "0");
    dest[k] = '\0';
  }
  return dest;
}

static char* s21_add_sign(char* dest, char* src, int signed_conversion,
                          int space_signed_conversion, long int number) {
  if (number < 0 || (int)signed_conversion == 1) {
    dest = realloc(dest, s21_strlen(src) + 2);
    if (number < 0) {
      dest[0] = '-';
    } else {
      dest[0] = '+';
    }
    dest[1] = '\0';
  } else if (space_signed_conversion == 1) {
    dest = realloc(dest, s21_strlen(src) + 2);

    dest[0] = ' ';

    dest[1] = '\0';
  }
  return dest;
}

static void flag_i_d(Wid_prec_len* wpl, Flags* flag, char* temp, char* buf, long int d) {
  temp = s21_int_to_string(d, wpl->precision);  // get string with number
  //TODO protect calloc 
  char *result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_sign(result, temp, flag->show_sign, flag->hide_sign, d);
  result = s21_add_zero(result, temp, wpl->precision);
  insert_and_free(wpl, flag, temp, buf, result, 0);
}

/* */
static char* put_c (char *result, char symbol, int number, int *counter) {
  if (NULL != (result = calloc(number, sizeof(char)))) {
    for (int i = 0; i < number; i++) {
      result[i] = symbol;
      (*counter)++; // TODO delete?
    }
  }
  return result;
}

/* right justification within the given field width */
static char* right_justify(char *buf, char *result, Wid_prec_len *wpl, int symbol, int *counter) {
    result = put_c(result, ' ', wpl->width - 1, counter);
    if (result) {
      fill_result(buf, result, counter);
    }
    result = put_c(result, symbol, 1, counter);
    return result;
}

/* left justification within the given field width */
static char* left_justify(char *buf, char *result, Wid_prec_len *wpl, int symbol, int *counter) {
    result = put_c(result, symbol, 1, counter);
    if (result) {
      fill_result(buf, result, counter);
    }
    result = put_c(result, ' ', wpl->width - 1, counter);
    return result;
}

void flag_c(char* buf, Flags *flag, Wid_prec_len *wpl, char symbol, int *counter, int *err) {
  char *result = NULL;
  if (!wpl->arg_width && wpl->width) {
    if (flag->fill_left) {
      result = left_justify(buf, result, wpl, symbol, counter);
    } else {
      result = right_justify(buf, result, wpl, symbol, counter);
    }
  } else if (wpl->arg_width) {
    // handle getting width from the another arg
  } else {
    result = put_c(result, symbol, 1, counter);
  }
  if (result) {
    fill_result(buf, result, counter);
  } else {
    *err = ER;
  }
  reset(wpl, flag);
}

// count_char for %n
void print_processing(char* buf, int specs, int *counter, va_list* param,
                      Wid_prec_len* wpl, Flags* flag, int* err) {
  long int d;  // TODO for what?
  // long double f;        // TODO for what?
  char symbol;          // for %c
  // char* string;         // TODO for what?
  // uint64_t u;           // TODO for what?
  char* temp = NULL;    // TODO for what?
  if ((specs & spec_d) || (specs & spec_i)) {
    if (wpl->length == 'h') {
      d = (short int)va_arg(*param, int);
    } else if (wpl->length == 'l') {
      d = va_arg(*param, long int);
    } else {
      d = va_arg(*param, int);
    }
    flag_i_d(wpl, flag, temp, buf, d);
  } else if ((specs & spec_c)) {
    symbol = (char)va_arg(*param, int);
    flag_c(buf, flag, wpl, symbol, counter, err);
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
  } else if ((specs & spec_c)) {
    symbol = (char)va_arg(*param, int);
    flag_c(sh21, buf, result, symbol);
  } else if ((specs & spec_s)) {
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
  } else if ((specs & spec_e) || (specs & spec_E)) {
    if (sh21->L_flag == 1) {
      f = va_arg(*param, long double);
    } else {
      f = va_arg(*param, double);
      flag_e(sh21, temp, buf, result, f, *format);
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
static void get_width_precision(const char** format, int* num_value,
                                bool* bool_value, int* err) {
  if (**format == '*') {
    *bool_value = true;
    (*format)++;
  } else {
    *num_value = str_to_dec(format, 0, 1, 0,
                            err); /* get width (str, width, sign, count, err);*/
  }
  return;
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





int s21_sprintf(char* buf, const char* format, ...) {
  *buf = 0;
  int err = OK;  // for errors
  va_list param;
  va_start(param, format);
  int counter = 0;          // for %n
  bool is_spec_start = false;  // for tracking start of specifiers (%)
  Flags flag;
  Wid_prec_len wpl;
  reset(&wpl, &flag);

  while (*format) {
    if (!is_spec_start && *format != '%') {  // if we met a regular ch
      add_to_buf(buf, format, 1, counter);  // add current character into buf
      counter++;
      format++;
      // if we met % for the first time
    } else if (!is_spec_start && *format == '%') {
      is_spec_start = true;  // treats current '%' as start of format specifier
      format++;
    } else  if (is_spec_start) {  // start specificator processing
      get_flags(&format, &flag);
      get_width_precision(&format, &wpl.width, &wpl.arg_width, &err);
      // may be add hiding for this with get_precision() ?
      if (*format == '.') {
        format++;
        get_width_precision(&format, &wpl.precision, &wpl.arg_precision, &err);
      }
      wpl.length = get_length(&format);
      int specs = set_specs_printf(&format, &err); /* fill the specs number */
      print_processing(buf, specs, &counter, &param, &wpl, &flag, &err);
      reset(&wpl, &flag);
      is_spec_start = false;
    }
    //format++;
  }
  va_end(param);
  printf("counter = %d\n", counter);
  //return s21_strlen(buf);
  return counter;
}

/*void flag_e(s21* s21, char* temp, char* buf, char* result, long double f,
            char format) {
  temp = handler_flag_e(f, s21->floating, format, s21);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));

  result = s21_add_sign(result, temp, s21->signed_conversion,
                        s21->space_signed_conversion, f);
  insert_and_free(s21, temp, buf, result);
}

char* handler_flag_e(long double num, int floating, char format, s21* sh21) {
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
}

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
