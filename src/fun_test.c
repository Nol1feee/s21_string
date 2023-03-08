#include "s21_sprintf.h"

int main() {
    char my[100] = {0};
    s21_sprintf(my, "%s", "kekekekk");
    printf("my = %s\n", my);

    char orig[100] = {0};
    sprintf(orig, "%c", 'c');
		printf("orig = %s\n", orig);
    return 0;
}