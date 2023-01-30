/*sscanf implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> /* for strlen, strcpy (then delete)*/

int s21_sscanf(const char *str, const char *format, ...) {
  if (format) { // temporary!! to avoid the warning
  char *buffer = (char *)malloc(strlen(str) * sizeof(char));
  strcpy(buffer, str);
  puts(buffer);
  }
  return 0;
}
