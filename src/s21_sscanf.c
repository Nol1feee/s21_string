/*sscanf implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> /* for strlen, strcpy (then delete) */
#include <stdbool.h>
#include <stdarg.h>
#include <math.h> /* for pow*/

#define SHIFT 48 /* code of 0 in ASCII */

/* for specifiers */
enum {
  spec_c = 1 << 0, 
  spec_d = 1 << 1,
  spec_i = 1 << 2,
  spec_e = 1 << 3,
  spec_E = 1 << 4,
  spec_f = 1 << 5,
  spec_g = 1 << 6,
  spec_G = 1 << 7,
  spec_o = 1 << 8,
  spec_s = 1 << 9,
  spec_u = 1 << 10,
  spec_x = 1 << 11,
  spec_X = 1 << 12,
  spec_p = 1 << 13,
  spec_n = 1 << 14,
  spec_percent = 1 << 15
};

/* check white-space characters */
static _Bool is_whitespace(char ch) {
  return (ch == ' ' || ch == '\t' || ch == '\n') ? true : false;
}

/* skip white-space chatacters */
static void skip_whitespaces(char **string) {
  while (is_whitespace(**string)) {
    (*string)++;
  }
}

/* sets the format_buf pointer to the character after the % */
static void get_specifier(char **str_buf, char **format_buf, _Bool *outsider_ch) {
  skip_whitespaces(format_buf);
  while (**format_buf != '%') { /* skip all regular characters*/
    if (**format_buf != **str_buf) {
      *outsider_ch = true;
    }
    (*format_buf)++;
    (*str_buf)++;  
  }
  /* stoped at % */
  ++(*format_buf);
}

/* check character if it's a digit*/
static _Bool is_digit(char ch) {
  return ((ch >= '0') && (ch <= '9')) ? true : false;
}

/* width from string to number (return pointer format_buf into the last digit) */
static int get_number(char **format_buf) {
  int number = **format_buf - SHIFT; /* get the first digit */
  (*format_buf)++;
  while (is_digit(**format_buf)) {
    number = number * 10 + (**format_buf - SHIFT);
    (*format_buf)++;
  }
  (*format_buf)--;
  return number;
}

/* check character if it's a length*/
static _Bool is_correct_length(char **format_buf) {
  _Bool res = false;
  char next_ch = *((*format_buf) + 1);
  if (((**format_buf == 'l') || (**format_buf == 'L')) && (next_ch = 'f')) {
    res = true;
  }
  return res;
}

/* set the specs in an integer number according to enum */
static int set_specs(char **format_buf, _Bool *ass_supress, int *width, int *length) {
  int specs = 0;
  while ((**format_buf) && !is_whitespace(**format_buf) && (!specs)) {
    switch (**format_buf) {
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
      case '*':
        *ass_supress = true;
        break;

      default:
        if (is_digit(**format_buf) && (**format_buf > '0')) {
          *width = get_number(format_buf); /* get width */
        } else if (is_correct_length(format_buf)) {
          *length = **format_buf;
        } else {
          fprintf(stderr, "Incorrect specifier\n");
          /* handle an error*/
        }
    }
    (*format_buf)++;
  }
  return specs;
}

/* put string from source string to another agrument of sscanf */
static void scan_string(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width) {
  skip_whitespaces(str_buf);
  char *tmp = *str_buf; /* save start of string */
  int count = 0; /* number of characters */
  if (width) {
    while (**str_buf && !is_whitespace(**str_buf) && (count < width)) {
      (*str_buf)++; /* go to end of string */
      count++;
    }
  } else {
    while (**str_buf && !is_whitespace(**str_buf)) {
      (*str_buf)++; /* go to end of string */
      count++;
    }
  }
  if (!ass_supress) {
    char *dst_string = va_arg(*argp, char*); /* take argument address */
    if (outsider_ch) {
      strcpy(dst_string, "\0"); /* put empty string into argument */
    } else {
      strncpy(dst_string, tmp, count); /* put string into argument */
      strncpy(dst_string + count, "\0", 1); /* cut extra garbage */
    }
  }
}

/* check specs if it's a e/E/f/g/G */
static _Bool is_efg(int specs) {
  return ((specs & spec_e) || (specs & spec_E) || (specs & spec_f) || (specs & spec_g) || (specs & spec_G)) ? true : false;
}

/* puts floating point number into another vararg*/
static void fpnum_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch, int length, int specs, long double res) {
  if (!ass_supress && !outsider_ch) {
    if (is_efg(specs) && (length == 'L')) {
      long double *dst_num = va_arg(*argp, long double*); /* take argument address */
      *dst_num = res;
    } else if (is_efg(specs) && (length == 'l')) {
      double *dst_num = va_arg(*argp, double*);
      *dst_num = res;
    } else {
      float *dst_num = va_arg(*argp, float*);
      *dst_num = res;
    }
  }
}

/* multiplies  the res by a power of 10 from the exponent */
static long double get_exp(long double res, char **str_buf) {
  (*str_buf)++; /* go to the next char, must be a '-' or '+' */
  char next_ch = *((*str_buf) + 1); /* must be a digit */
  int power10 = 0, sign = 1;
  if (((**str_buf == '-') || (**str_buf == '+')) && is_digit(next_ch)) {
    sign = (**str_buf == '-') ? -1 : 1;
    (*str_buf)++; /* go to digit */
    power10 = get_number(str_buf); /* str_buf on the last digit */
  } else if (is_digit(**str_buf)) {
    power10 = get_number(str_buf);
  }
  res = res * pow(10, power10 * sign);
  return res;
}

/* skip the whole string */
static void skip_all(char **string) {
  while (**string) {
    (*string)++;
  }
}

/* */
static int sign_check(char **str_buf) {
  int sign = 1;
  char next_ch = *((*str_buf) + 1);
  if ((is_sign(**str_buf)) && (is_sign(next_ch))) {
    sign = 0;
    skip_all(str_buf);
  } else if (**str_buf == '-') {
    sign = -1;
    (*str_buf)++;
  } else if (**str_buf == '+') {
    (*str_buf)++;
  }
  return sign;
}

/* put floating-point number from source string to another agrument of sscanf */
static void scan_efg(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length, int specs) {
  skip_whitespaces(str_buf);
  int sign = 1;
  if (**str_buf == '-') {
    sign = -1;
    (*str_buf)++;
  } else if (**str_buf == '+') {
    (*str_buf)++;
  }
  long double res = 0;
  int power10 = 0; /* for power of 10 */
  char next_ch = *((*str_buf) + 1);
  if (is_digit(**str_buf)) {
    res = (**str_buf - SHIFT) * sign;
    (*str_buf)++;
  } else if ((**str_buf == '.') && (is_digit(next_ch))){
    power10++;
    (*str_buf)++;
  } else {
    // hanlde error
  }
  int count = 1; /* number of characters (digits or .) */
  while (((count < width) || !width) && **str_buf && !is_whitespace(**str_buf) && (is_digit(**str_buf) || (**str_buf == '.') || (**str_buf == 'e') || (**str_buf == 'E'))) {
    if (is_digit(**str_buf) && (!power10)) {
      res = res * 10 + (**str_buf - SHIFT) * sign;
    } else if (is_digit(**str_buf) && power10) {
      res = res + ((long double)(**str_buf - SHIFT) / pow(10, power10++)) * sign;
    } else if ((**str_buf == '.') && (!power10)) {
      power10++;
    } else if ((**str_buf == 'e') || (**str_buf == 'E')) { 
      res = get_exp(res, str_buf);
    } else {
      // handle error
      break;
    }
    (*str_buf)++; 
    count++;
  }
  
  fpnum_into_arg(argp, ass_supress, outsider_ch, length, specs, res);

}

/* put unsigned hexadecimal integer from source string to another agrument of sscanf */
static void scan_hex(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length, int specs) {
  skip_whitespaces(str_buf);
  int sign = 1;
  if (**str_buf == '-') { // TODO check "--1A3", "++1A3"
    sign = -1;
    (*str_buf)++;
  } else if (**str_buf == '+') {
    (*str_buf)++;
  }
  long double res = 0;
  int power10 = 0; /* for power of 10 */
  char next_ch = *((*str_buf) + 1);
  if (is_digit(**str_buf)) {
    res = (**str_buf - SHIFT) * sign;
    (*str_buf)++;
  } else if ((**str_buf == '.') && (is_digit(next_ch))){
    power10++;
    (*str_buf)++;
  } else {
    // hanlde error
  }
  int count = 1; /* number of characters (digits or .) */
  while (((count < width) || !width) && **str_buf && !is_whitespace(**str_buf) && (is_digit(**str_buf) || (**str_buf == '.') || (**str_buf == 'e') || (**str_buf == 'E'))) {
    if (is_digit(**str_buf) && (!power10)) {
      res = res * 10 + (**str_buf - SHIFT) * sign;
    } else if (is_digit(**str_buf) && power10) {
      res = res + ((long double)(**str_buf - SHIFT) / pow(10, power10++)) * sign;
    } else if ((**str_buf == '.') && (!power10)) {
      power10++;
    } else if ((**str_buf == 'e') || (**str_buf == 'E')) { 
      res = get_exp(res, str_buf);
    } else {
      // handle error
      break;
    }
    (*str_buf)++; 
    count++;
  }
  
  fpnum_into_arg(argp, ass_supress, outsider_ch, length, specs, res);

}

/* scan processing*/
static void scan_proc(char **str_buf, int specs, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length) {
  if (specs & spec_s) { /* scan strings */
    scan_string(str_buf, argp, ass_supress, outsider_ch, width);
  }
  if (is_efg(specs)) { /* scan decimal numbers with floating point or scientific notation */
    scan_efg(str_buf, argp, ass_supress, outsider_ch, width, length, specs);
  }
  if ((specs & spec_x) || (specs & spec_X)) { /* scan unsigned hexadecimal integers */
    scan_hex(str_buf, argp, ass_supress, outsider_ch, width, length, specs); 
  }
}

/* main sscanf function */
int s21_sscanf(const char *str, const char *format, ...) {
  char *str_buf = (char *)malloc(strlen(str) * sizeof(char));
  char *format_buf = (char *)malloc(strlen(format) * sizeof(char));
  strcpy(str_buf, str);
  strcpy(format_buf, format);
  printf("str:%s\n", str_buf);
  printf("format:%s\n", format_buf);
  va_list argp;
  va_start(argp, format);
  _Bool outsider_ch = false; /* for outsider characters in the format string*/
  while (*str_buf && *format_buf) {
    get_specifier(&str_buf, &format_buf, &outsider_ch); /* set format_buf to the start of specifier*/
    printf("str:%s\n", str_buf);
    printf("format:%s\n", format_buf);
    _Bool ass_supress = false; /* supress assignment (*) */
    int width = 0, length = 0;
    int specs = set_specs(&format_buf, &ass_supress, &width, &length); /* fill the specs number */
    printf("width = %d, length = %c = %d\n", width, length, length);
    if (specs & spec_f) {
      printf("ok\n");
    }
    scan_proc(&str_buf, specs, &argp, ass_supress, outsider_ch, width, length);
  }
  va_end(argp);
  return 0;
}
