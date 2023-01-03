#include "s21_functions.h"

//возвращает длину строки без '\0'
s21_size_t s21_strlen(char *string) {
	s21_size_t len = 0;
	while(*(string + len)) {
		len++;
	}
	return len;
}

//don't work with NULL, otherwise work great
char *s21_strtok(char *string, char *delim) {
	s21_size_t len = s21_strlen(string);
	for(int i = 0; i < len; i++) {
		if(string[i] == *delim) 
			string[i] = '\0';
			break;
	}
	return string;
}

//фун-ия добавляет в конец str_change содержание str_add
char *s21_strcat(char *str_change, char *str_add) {
	return(s21_strncat(str_change, str_add, s21_strlen(str_change) + s21_strlen(str_add)));
}

//фун-ия добавляет в конец str_change содержание str_add не более n байт 
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
//выводит сообщение об ошибке (для линукса и мак ос разные)
//заменить спринтф на с21_спринтф!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
char *s21_strerror(int errnum) { 
	static char res[50] = {0};
	if(errnum >= 0 && errnum < AMOUNT_ERRORS) {
		strcpy(res, errors[errnum]);
	} else {
		sprintf(res, "Unknown error: %d", errnum);
	}
	return res;
}

//фун-ия посимвольно сравнивает 2 строки, если они равны - возвращает 0,
//если 1ый несовпадающий символ 1ой строки "больше" - возвращает положительное число,
//если символ второй строки больше - отрицательное
int s21_strcmp(char *str_one, char *str_two) {
	while(*str_one && *str_one == *str_two) {
		str_one++;
		str_two++;
	}
return *str_one - *str_two;
}