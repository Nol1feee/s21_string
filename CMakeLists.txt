cmake_minimum_required(VERSION 3.22)
project(s21_string C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(s21_string
        src/fun_test.c
        src/s21_errors.h
        "src/s21_for_c#.c"
        src/s21_insert.c
        src/s21_memchr.c
        src/s21_memcmp.c
        src/s21_memcpy.c
        src/s21_memmove.c
        src/s21_memset.c
        src/s21_sprintf.c
        src/s21_sprintf.h
        src/s21_strcat.c
        src/s21_strchr.c
        src/s21_strcmp.c
        src/s21_strcpy.c
        src/s21_strcspn.c
        src/s21_strerror.c
      #  src/s21_string.c
        src/s21_string.h
        src/s21_strlen.c
        src/s21_strncat.c
        src/s21_strncmp.c
        src/s21_strncpy.c
        src/s21_strpbrk.c
        src/s21_strrchr.c
        src/s21_strspn.c
        src/s21_strstr.c
        src/s21_strtok.c
        src/s21_to_lower.c
        src/s21_to_upper.c
        src/s21_trim.c)
