#include "s21_functions.h"

//work great
s21_size_t s21_strlen(char *string) {
	s21_size_t len = 0;
	while(*(string + len)) {
		len++;
	}
	return len;
}

//don't work with NULL, otherwise work great
char s21_strtok(char *string, char *delim) {
	s21_size_t len = s21_strlen(string);
	for(int i = 0; i < len; i++) {
		if(string[i] == *delim) 
			string[i] = '\0';
			break;
	}
	return string[i];
}

//work great
char *s21_strcat(char *str_change, char *str_add); {
	return(s21_strncat(str_change, str_add, s21_strlen(str_change) + s21_strlen(str_add)));
}

//work great
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) {
	size_t len_str_change = strlen(str_change);
	int i = 0;
	while(str_add[i] != '\0' && i < n) {
		str_change[len_str_change + i] = str_add[i]; 
		i++;
	}
	str_change[len_str_change + i] = '\0';
	return str_change;
}

char *s21_strerror(int errnum) { 
	// ошибка без static - address of stack memory associated with local variable 'res' returned [-Wreturn-stack-address]
	static char res[50] = {0};
	if(errnum >= 0 && errnum < AMOUNT_ERRORS) {
		strcpy(res, errors[errnum]);
	}// else {
	//	printf("Unknown error: %d", errnum);
	//}
	return res;
}

//work great
int s21_strcmp(char *str_one, char *str_two) {
	while(*str_one && *str_one == *str_two) {
		str_one++;
		str_two++;
	}
return *str_one - *str_two;
}