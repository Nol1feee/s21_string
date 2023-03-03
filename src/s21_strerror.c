#include "s21_errors.h"
#include "s21_string.h"
// выводит сообщение об ошибке (для линукса и мак ос разные)
// заменить спринтф на с21_спринтф!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
char *s21_strerror(int errnum) {
  static char res[50] = {0};
  if (errnum >= 0 && errnum < AMOUNT_ERRORS) {
    s21_strcpy(res, errors[errnum]);
  } else {
    s21_sprintf(res, "Unknown error: %d", errnum);
  }
  return res;
}