#ifndef SRC_TESTS_TEST_STRING_H_
#define SRC_TESTS_TEST_STRING_H_

#include <check.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

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

Suite *sscanf_s21(void);
Suite *sprintf_s21(void);

//temp
Suite *test_sprintf_c(void);
Suite *test_sprintf_e(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_g(void);
Suite *test_sprintf(void);
Suite *test_sprintf_signed(void);
Suite *test_sprintf_signed_i(void);
Suite *test_sprintf_octal(void);
Suite *test_sprintf_unsigned(void);
Suite *test_sprintf_hex(void);
Suite *test_sprintf_HEX(void);
Suite *test_sprintf_percent(void);
Suite *test_sprintf_pointer(void);
Suite *test_sprintf_n(void);
Suite *test_sprintf_string(void);

#endif  // SRC_TESTS_TEST_STRING_H_
