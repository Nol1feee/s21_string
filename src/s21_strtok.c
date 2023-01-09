#include "s21_string.h"

//фун-ия для strtok
int enum_delim(char str, const char *delim) {
  int flag = 0;
  while (*delim && flag == 0) {
    if (str == *delim) {
      flag = 1;
    }
    delim++;
  }
return flag;
}
//делит строку на токены
char *s21_strtok(char *str, const char *delim) {
	char *res = NULL;
	static char *buf = NULL;
	if(str) {
		buf = NULL;
	} else {
		str = buf;
	}
	res = str;
	//переместить res = str, тк будет фейлить много тестов, но пока что я хз куда
	while(*str) {
		if(enum_delim(*str, delim)) {
			break;
		}	
		str++;
	}
	if(*str) {
		*str = '\0';
		buf = str + 1;
	} else {
		res = NULL;
		buf = NULL;
	}
	return res;
}
//можно енам делим на стрпбрк заменить + стрток валится