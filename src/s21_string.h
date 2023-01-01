#define s21_size_t unsigned long long 
#define s21_NULL (void*)0

#include <stdio.h>
#include <string.h>
#include "s21_errors.h"

//возвращает длину строки, работает на 100%
s21_size_t s21_strlen(char *string) {
	s21_size_t len = 0;
	while(*(string + len)) {
		len++;
	}
	return len;
}

//don't work with NULL, otherwise work great
void s21_strtok(char *string, char *delim) {
	s21_size_t len = s21_strlen(string);
	for(int i = 0; i < len; i++) {
		if(string[i] == *delim) 
			string[i] = '\0';
	}
}

//abort, but i need trap + incorrect work, when i try to add one symbol with not enought memory 
char s21_strcat(char *str_change, char *str_add) {
	s21_size_t len = s21_strlen(str_change);
	s21_size_t len_str_add = s21_strlen(str_add);
	while(*str_add != '\0') {
		*(str_change + len) = *str_add;
		str_change++;
		str_add++;
	}
	//for(int i = len; *str_add != '\0'; str_change[i] = *str_add, i++, str_add++);
	str_change[len + len_str_add] = '\0';
	return *str_change;
}

//fix strcat, then i need 15 min. for strncat
void s21_strncat(char *restrict s1, char *restrict s2, s21_size_t n) {
}

//work witch %c, but i need use %s
char s21_strerror(int errnum) { 
	char res[50];
	if(errnum >= 0 && errnum < AMOUNT_ERRORS) {
		printf("%s", errors[errnum]); 
	} else {
		printf("Unknown error: %d", errnum);
	}
	return 0;
}

void s21_strcmp(char *str_one, char *str_two) {
}
