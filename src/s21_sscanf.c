/*sscanf implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> /* for strlen, strcpy (then delete)*/
#include <stdbool.h>

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
  

/* check white-space characters*/
static _Bool is_whitespace(char ch) {
  if (ch == ' ' || ch == '\t' || ch == '\n') {
    return true;
  } else {
    return false;
  }
}

/* get specifier from format string */
static void get_specifier(char **str_buf, char **format_buf) {
  while (is_whitespace(**format_buf)) { /* skip all spaces*/
    (*format_buf)++;
  }
  while (**format_buf != '%') { /* skip all regular characters*/
    if (**format_buf == **str_buf) {
      (*format_buf)++;
      (*str_buf)++;      
    } else {
      fprintf(stderr, "format_buf: %c not equal to str_buf: %c\n", **format_buf, **str_buf);
      break;
    }
  }
  /* stoped at % */
  ++(*format_buf);
}

/* set the specs in an integer number according to enum */
static int set_specs(char **format_buf) {
  int specs = 0;
  while ((**format_buf) && !is_whitespace(**format_buf)) {
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

      default:
        fprintf(stderr, "Incorrect specifier\n");
        /* to handle an error*/
    }
    (*format_buf)++;
  }
  return specs;
}

int s21_sscanf(const char *str, const char *format, ...) {
  char *str_buf = (char *)malloc(strlen(str) * sizeof(char));
  char *format_buf = (char *)malloc(strlen(format) * sizeof(char));
  strcpy(str_buf, str);
  strcpy(format_buf, format);
  printf("str:%s\n", str_buf);
  printf("format:%s\n", format_buf);
  while (*str_buf && *format_buf) {
    get_specifier(&str_buf, &format_buf); /* set format_buf to the start of specifier*/
    printf("str:%s\n", str_buf);
    printf("format:%s\n", format_buf);
    int specs = set_specs(&format_buf); /* fill the specs number */
    if (specs & spec_s) {
      printf("ok\n");
    }
    //str_buf++;
    format_buf++;
    //break;
  }
  //puts(buffer);
  
  return 0;
}
