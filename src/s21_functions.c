#include "s21_string.h"

int s21_strtok(char *string, char *delim) {
    int i = 0;
    char ch_buf = 0;
    while(ch_buf != '\0') {
        ch_buf = string[i];
        i++;
    }
    printf("%d", ch_buf);
	return 0;
}

s21_size_t s21_strlen(char *string) {
	s21_size_t len = 0;
	for(; *(string + len); len++);
	return len;
}
