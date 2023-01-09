#include "s21_string.h"

//фун-ия добавляет в конец str_change содержание str_add не более n байт 
char *s21_strncat(char *str_change, char *str_add, s21_size_t n) {
	size_t len_str_change = strlen(str_change);
	int k = n;
  int i = 0;
	while(str_add[i] != '\0' && i < k) {
		str_change[len_str_change + i] = str_add[i]; 
		i++;
	}
	str_change[len_str_change + i] = '\0';
	return str_change;
}