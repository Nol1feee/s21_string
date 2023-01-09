#include "s21_string.h"
 #include "s21_errors.h"
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