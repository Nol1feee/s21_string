#ifndef SRC_TESTS_TEST_STRING_H_
#define SRC_TESTS_TEST_STRING_H_

#include <check.h>
#include <stdint.h>
#include <string.h>

#include "../s21_string.h"

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
Suite *strstr_s21(void);
Suite *memcpy_s21(void);
Suite *memmove_s21(void);
Suite *memset_s21(void);
Suite *strcpy_s21(void);
Suite *strncpy_s21(void);

Suite *insert_s21(void);
Suite *to_lower_s21(void);
Suite *to_upper_s21(void);
Suite *trim_s21(void);

Suite *sprintf_s21(void);

#endif  // SRC_TESTS_TEST_STRING_H_