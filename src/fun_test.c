#include "s21_sprintf.h"
#define BUFF_SIZE 100
int main() {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%03d";
  int val = 69;
  s21_sprintf(str1, format, val);
  printf("%s\n", str1);
  sprintf(str2, format, val);
  printf("%s\n", str2);
  return 0;
}