/*sscanf implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> /* for strlen, strcpy (then delete) */
#include <stdbool.h>
#include <stdarg.h>
#include <math.h> /* for pow*/

#define SHIFT 48 /* code of 0 in ASCII */

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
  if (ch == ' ' || ch == '\t' || ch == '\n') {
    return true;
  } else {
    return false;
  }
}

/* sets the format_buf pointer to the character after the % */
static void get_specifier(char **str_buf, char **format_buf, _Bool *outsider_ch) {
  while (is_whitespace(**format_buf)) { /* skip all spaces*/
    (*format_buf)++;
  }
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
  _Bool res = ((ch >= '0') && (ch <= '9')) ? true : false;
  return res;
}

/* width from string to number */
static int get_width(char **format_buf) {
  int width = **format_buf - SHIFT; /* get the first digit */
  (*format_buf)++;
  while (is_digit(**format_buf)) {
    width = width * 10 + (**format_buf - SHIFT);
    (*format_buf)++;
  }
  (*format_buf)--;
  return width;
}

/* set the specs in an integer number according to enum */
static int set_specs(char **format_buf, _Bool *ass_supress, int *width) {
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
          *width = get_width(format_buf);
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
  while (is_whitespace(**str_buf)) { /* skip all white-spaces */
    (*str_buf)++;
  }
  char *tmp = *str_buf; /* save start of string */
  int length = 0;
  if (width) {
    while (**str_buf && !is_whitespace(**str_buf) && (length < width)) {
      (*str_buf)++; /* go to end of string */
      length++;
    }
  } else {
    while (**str_buf && !is_whitespace(**str_buf)) {
      (*str_buf)++; /* go to end of string */
      length++;
    }
  }
  if (!ass_supress) {
    char *dst_string = va_arg(*argp, char*); /* take argument address */
    if (outsider_ch) {
      strcpy(dst_string, "\0"); /* put empty string into argument */
    } else {
      strncpy(dst_string, tmp, length); /* put string into argument */
      strncpy(dst_string + length, "\0", 1); /* cut extra garbage */
    }
  }
}

/* put number from source string to another agrument of sscanf */
static void scan_efg(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width) {
  while (is_whitespace(**str_buf)) { /* skip all white-spaces */
    (*str_buf)++;
  }
  float res = 0;
  int power10 = 0; /* for power of 10 */
  char next_ch = *((*str_buf) + 1);
  if (is_digit(**str_buf)) {
    res = **str_buf - SHIFT;
    (*str_buf)++;
  } else if ((**str_buf == '.') && (is_digit(next_ch))){
    power10++;
    (*str_buf)++;
  } else {
    // hanlde error
  }
  int length = 1;
  while ((length < width) && **str_buf && !is_whitespace(**str_buf) && (is_digit(**str_buf) || (**str_buf == '.'))) {
    if (is_digit(**str_buf) && (!power10)) {
      res = res * 10 + (**str_buf - SHIFT);
    } else if (is_digit(**str_buf) && power10) {
      res = res + (float)(**str_buf - SHIFT) / pow(10, power10++);
    } else if ((**str_buf == '.') && (!power10)) {
      power10++;
    } else {
      // handle error
      break;
    }
    (*str_buf)++; 
    length++;
  }
  if (!ass_supress) {
    float *dst_num = va_arg(*argp, float*); /* take argument address */
    if (outsider_ch) {
      // handle outsider_ch
    } else {
      *dst_num = res;
    }
  }
}

/* scan processing*/
static void scan_proc(char **str_buf, int specs, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width) {
  if (specs & spec_s) { /* scan strings */
    scan_string(str_buf, argp, ass_supress, outsider_ch, width);
  }
  if ((specs & spec_e) || (specs & spec_E) || (specs & spec_f) || (specs & spec_g) || (specs & spec_G)) { /* scan decimal numbers with floating point or scientific notation */
    scan_efg(str_buf, argp, ass_supress, outsider_ch, width);
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
    int width = 0;
    int specs = set_specs(&format_buf, &ass_supress, &width); /* fill the specs number */
    printf("width = %d\n", width);
    if (specs & spec_f) {
      printf("ok\n");
    }
    scan_proc(&str_buf, specs, &argp, ass_supress, outsider_ch, width);
    //str_buf++;
    //format_buf++;
    //break;
  }
  va_end(argp);
  //puts(buffer);
  
  return 0;
}
