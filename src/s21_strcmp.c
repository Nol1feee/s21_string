#include "s21_string.h"

// Сравнивает строку, на которую указывает str1, 
//cо строкой, на которую указывает str2. 
int s21_strcmp(char *str1, char *str2) {
    int result = 0;
    char *p_1 = str1;
    char *p_2 = str2;

    while (*p_1 == *p_2) {
        p_1++;
        p_2++;
        if (*p_1 == '\0' || *p_2 == '\0') {
            break;
        }
    }
    if (*p_1 != '\0' && *p_2 != '\0') {
        result = *p_1 - *p_2;
    } else if (*p_1 == '\0') {
        result = -*p_2;
    } else if (*p_2 == '\0') {
        result = *p_1;
    }
    return result;
}
