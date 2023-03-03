#include "s21_string.h"

int main() {
    int buf[100];
    s21_sprintf(buf, "%e", 30.30);
    printf("my = %s\n", buf);

		int buf_orig[100];
		sprintf(buf_orig, "%e", 30.30);
		printf("orig = %s\n", buf_orig);
    return 0;
}