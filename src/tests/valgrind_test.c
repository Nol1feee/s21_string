#include "test_string.h"

int main() {
  char buf[100];
  s21_sprintf(buf, "asdfggsdd sad %s %d %c %lf", "ssss", 6, 'c', 6.5);
  s21_sprintf(buf, "asdfggsdd sad %s %ld %hi %hd %ld %f %lf %u", "ssss", 2147L,
              4, 5, 6555L, 7.7, 6.5, 6);
  char s[][50] = {"kek LOL",     "check",       "123456",
                  "eee eee EEE", "eee eee EEE", "kkk ccc ckckck"};
  char d[][50] = {"kek", "ch", "11111", "E", "e", "c k "};
  for (int i = 0; i < 6; i++) {
    void *aboba = s21_trim(s[i], d[i]);
    free(aboba);
  }
  char str[][50] = {"kek LOL", "check", "123456", "kEk CHekc129;"};
  for (int i = 0; i < 4; ++i) {
    void *aboba = s21_to_upper(str[i]);
    free(aboba);
  }
  char st[][50] = {"kek LOL", "check", "123456", "kEk CHekc129;"};
  for (int i = 0; i < 4; ++i) {
    void *aboba = s21_to_lower(st[i]);
    free(aboba);
  }
  char to_change[50] = "delim -> k <- delim";
  char to_add[50] = " ";
  s21_size_t forward = 5;
  void *aboba = s21_insert(to_change, to_add, forward);
  free(aboba);

  return 0;
}