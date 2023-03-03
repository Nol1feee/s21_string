#include "s21_string.h"

void *s21_memmove(void *dst, const void *src, size_t n) {
  char *char_dst = (char *)dst;
  const char *char_src = (char *)src;
  /* if there is overlap, then backward copy */
  if ((char_src < char_dst) && (char_dst < char_src + n)) {
    for (char_dst += n, char_src += n; n--;) {
      *--char_dst = *--char_src;
    }
  } else { /*use forward copy from memcpy*/
    char_dst = s21_memcpy(char_dst, char_src, n);
  }
  return char_dst;
}
