/*sscanf implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> /* for strlen, strcpy (then delete)*/

/* check white-space characters*/
_Bool is_whitespace(char ch) {
  if (ch == ' ' || ch == '\t' || ch == '\n') {
    return true;
  } else {
    return false;
  }
}

/* get specifier from format string */
char *get_specifier(char *str_buf, char *format_buf) {
  while (is_whitespace(*format_buf)) { /* skip all spaces*/
    format_buf++;
  }
  while (format_buf != '%') { /* skip all regular characters*/
    if (format_buf == str_buf) {
      format_buf++;
      str_bur++;      
    } else {
      //empty word?
    }
  }
  /* to get all symbols before the first whitespace
  char *specifier = 
  while (!is_white_space(*format)) {

  }*/
}

int s21_sscanf(const char *str, const char *format, ...) {
  char *str_buf = (char *)malloc(strlen(str) * sizeof(char));
  char *format_buf = (char *)malloc(strlen(format) * sizeof(char));
  strcpy(str_buf, str);
  strcpy(format_buf, format);
  //char *p_str = str_buf; /* a pointer to keep track of the position in the str*/
  //char *p_format = format_buf; /* a pointer to keep track of the position in the format*/
  while (str_buf && format_buf) {
    char *specifier = get_specifier(str_buf, format_buf);
  }
  //puts(buffer);
  return 0;
}
