#ifndef SRC_TESTS_TEST_STRING_H_
#define SRC_TESTS_TEST_STRING_H_

#include "../s21_string.h"
#include <string.h>
#include <check.h>

Suite *strlen_s21(void);
Suite *strtok_s21(void);
Suite *strncat_s21(void);
Suite *strcat_s21(void);
Suite *strerror_s21(void);
Suite *memchr_s21(void);
Suite *strchr_s21(void);
Suite *strpbrk_s21(void);
Suite *strrchr_s21(void);
Suite *memcmp_s21(void);
Suite *strcmp_s21(void);
Suite *strncmp_s21(void);
Suite *strspn_s21(void);
Suite *strcspn_s21(void);

#endif // SRC_TESTS_TEST_STRING_H_