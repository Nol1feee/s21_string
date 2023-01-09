#include "s21_string.h"

//Сравнивает первые n байтов str1 и str2.
int s21_memcmp(void *str1, void *str2, size_t n) {
    int result = 0;
    unsigned char *p_1 = str1;
    unsigned char *p_2 = str2;

    while (p_1 && p_2 && n > 0) {
        n--;
        if (*p_1 != *p_2) {
            result = (*p_1) - (*p_2);
            break;
        }
        p_1++;
        p_2++;
    }
    if (!p_2) {
        result = *p_1;
    } else if (!p_1) {
        result = -(*p_2);
    }
    return result;
}