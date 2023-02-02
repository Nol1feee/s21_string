/*sscanf implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> /* for strlen, strcpy (then delete)*/
#include <stdbool.h>

/* check white-space characters*/
_Bool is_whitespace(char ch) {
  if (ch == ' ' || ch == '\t' || ch == '\n') {
    return true;
  } else {
    return false;
  }
}

/* get specifier from format string */
char *get_specifier(char **str_buf, char **format_buf) {
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
  char *specifier = ++(*format_buf);
  return specifier;
}

int s21_sscanf(const char *str, const char *format, ...) {
  char *str_buf = (char *)malloc(strlen(str) * sizeof(char));
  char *format_buf = (char *)malloc(strlen(format) * sizeof(char));
  strcpy(str_buf, str);
  strcpy(format_buf, format);
  printf("str:%s\n", str_buf);
  printf("format:%s\n", format_buf);
  while (*str_buf && *format_buf) {
    char *specifier = get_specifier(&str_buf, &format_buf); /* get the pointer to the start of specifier */
    printf("specifier:%s\n", specifier);
    printf("str:%s\n", str_buf);
    printf("format:%s\n", format_buf);
    //str_buf++;
    format_buf++;
    //break;
  }
  //puts(buffer);
  return 0;
}
