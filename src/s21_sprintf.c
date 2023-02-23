
#include "s21_sprintf.h"

int s21_sprintf(char* buf, const char* format, ...) {
    // NULL? b
    *buf = 0;
    va_list param;
    va_start(param, format);
    char* temp = NULL;
    char* result = NULL;
    long int d;
    long double f;
    wchar_t symbol;
    char* string;
    uint64_t u;
    s21 sh21;
    s21_reset_struct(&sh21);
    int count_char = 0;

    for (const char* line = format; *line; line++) {
        //    if (*line == '\0') break;
        if (sh21.format == 0 && *line != '%') {
            count_char += 1;  // для флага n
            s21_strncat(buf, line, 1);

        } else if (sh21.format == 0 && *line == '%') {
            sh21.format = 1;

        } else if (sh21.format) {
            if (*line == '%') {
                // s21_strcat?
                result = calloc(2, sizeof(char));
                result[0] = '%';
                s21_strcat(buf, result);
                free(result);
                s21_reset_struct(&sh21);
                count_char += 1;
            } else if (*line == '-') {
                sh21.fill_left = 1;
            } else if (*line == '+') {
                sh21.signed_conversion = 1;
            } else if (*line == ' ') {
                sh21.space_signed_conversion = 1;
            } else if (*line == '.') {
                sh21.floating = 0;
            } else if (*line == 'h') {
                sh21.h_flag = 1;
            } else if (*line == 'l') {
                sh21.l_flag = 1;
            } else if (*line == 'L') {
                sh21.L_flag = 1;
            } else if (((*line) >= '0') && ((*line) <= '9')) {
                numbers(line, &sh21);
                // пропускает цифры, которые были обработаны в numbers
                while (*(line + 1) >= '0' && *(line + 1) <= '9') line++;
            } else if (*line == 'i' || *line == 'd') {
                if (sh21.h_flag)
                    d = (short int)va_arg(param, int);
                else if (sh21.l_flag)
                    d = va_arg(param, long int);
                else
                    d = va_arg(param, int);
                flag_i_d(&sh21, temp, buf, result, d);
            } else if (*line == 'f') {
                if(sh21.L_flag) {
                   f = (va_arg(param, long double));
                } else {
                   f = va_arg(param, double);
                }
                flag_f(&sh21, temp, buf, result, f);
            } else if (*line == 'c') {
                symbol = (char)va_arg(param, int);
                flag_c(&sh21, buf, result, symbol);
            } else if (*line == 's') {
                string = va_arg(param, char*);
                flag_s(&sh21, string, buf, result);
            } else if (*line == 'u') {
                u = va_arg(param, uint64_t);
                flag_u(&sh21, temp, buf, result, u);
            } else if (*line == 'n') {
                int* count = va_arg(param, int*);
                *count = count_char;
                fill_result(buf, result, &sh21);
            }
        }
    }
    va_end(param);
    return s21_strlen(buf);
}
void flag_i_d(s21* sh21, char* temp, char* buf, char* result, long int d) {
    temp = s21_int_to_string(d, sh21->floating);
    result = calloc(s21_strlen(temp) + 1, sizeof(char));
    //почему бы не передать структуру? зачем передавать отдельно 2 значения..?
    result = s21_add_sign(result, temp, sh21->signed_conversion,
                          sh21->space_signed_conversion, d);
    result = s21_add_zero(result, temp, sh21->floating);
    insert_and_free(sh21, temp, buf, result);
}

void flag_f(s21* sh21, char* temp, char* buf, char* result, long double f) {
    temp = s21_float_to_string(f, sh21->floating);
    result = calloc(s21_strlen(temp) + 1, sizeof(char));

    result = s21_add_sign(result, temp, sh21->signed_conversion,
                          sh21->space_signed_conversion, f);
    insert_and_free(sh21, temp, buf, result);
}

void flag_c(s21* sh21, char* buf, char* result, wchar_t symbol) {
    result = calloc((sh21->width != -1 ? sh21->width : 0) + 2, sizeof(char));
    if (sh21->width != -1 && sh21->fill_left == 0) {
        for (int i = 0; i < sh21->width; i++) {
            result[i] = ' ';
            if (i == sh21->width - 1) result[i] = symbol;
        }
    } else if (sh21->width != -1) {
        result[0] = symbol;
        for (int i = 1; i < sh21->width; i++) result[i] = ' ';
    } else {
        result[0] = symbol;
    }
    fill_result(buf, result, sh21);
}

void flag_s(s21* sh21, char* string, char* buf, char* result) {
    int input_len = s21_strlen(string);
    if (sh21->floating < input_len && sh21->floating >= 0)
        input_len = sh21->floating;
    int output_len = sh21->width > input_len ? sh21->width : input_len;
    int padding_len = 0 > sh21->width - input_len ? 0 : sh21->width - input_len;
    result = calloc(output_len + 1, sizeof(char));
    result[output_len] = '\0';
    char* s_ptr;
    char* p_ptr;
    if (sh21->fill_left == 1) {
        s_ptr = &result[0];
        p_ptr = &result[input_len];
    } else {
        s_ptr = &result[padding_len];
        p_ptr = &result[0];
    }
    s21_memset(p_ptr, ' ', padding_len);
    s21_memcpy(s_ptr, string, input_len);
    fill_result(buf, result, sh21);
}

void flag_u(s21* sh21, char* temp, char* buf, char* result, uint64_t u) {
    if (sh21->h_flag) {
        u = (uint16_t)u;
    } else if (sh21->l_flag) {
        u = (uint64_t)u;
    } else {
        u = (uint32_t)u;
    }
    temp = s21_uint_to_string(u, sh21->floating);
    result = calloc(s21_strlen(temp) + 1, sizeof(char));
    result = s21_add_zero(result, temp, sh21->floating);
    insert_and_free(sh21, temp, buf, result);
}

char* revers(char* str, int i) {
    str[i] = '\0';
    for (int j = 0, k = s21_strlen(str) - 1, line; j < k; j++, k--) {
        line = str[j];
        str[j] = str[k];
        str[k] = line;
    }
    return str;
}

char* s21_int_to_string(long int number, long int floating) {
    int i = 1;
    //динамика, тк выделяется на куче или по приколу? тк я не вижу смысла этой динамики
    //можно выделить 20 байт, а не 32 (20ой под /0)
    char* str = calloc(32, sizeof(char));
    if (number < 0) number *= -1;
    if (number != 0) {
        while (number > 0) {
            str[i++ - 1] = (number % 10) + '0';
            number /= 10;
        }
    } else if (floating != 0) {
        str[i - 1] = '0';
    }
    return revers(str, i);
}

char* s21_add_sign(char* dest, char* src, int signed_conversion,
                   int space_signed_conversion, long int number) {
    if (number < 0 || (int)signed_conversion == 1) {
        dest = realloc(dest, s21_strlen(src) + 2);
        if (number < 0) {
            dest[0] = '-';
        } else {
            dest[0] = '+';
        }
        dest[1] = '\0';
    } else if (space_signed_conversion == 1) {
        dest = realloc(dest, s21_strlen(src) + 2);

        dest[0] = ' ';

        dest[1] = '\0';
    }
    return dest;
}

char* s21_add_zero(char* dest, char* src, int floating) {
    if ((int)floating > (int)s21_strlen(src)) {
        size_t k = s21_strlen(dest);
        if (s21_strlen(dest)) floating++;
        dest = realloc(dest, (floating + 1) * sizeof(char));
        for (; k < (floating - s21_strlen(src)); k++) s21_strcat(dest, "0");
        dest[k] = '\0';
    }
    return dest;
}

int s21_pow(int x, int y) {
    int temp = x;
    for (int i = 1; i < y; i++) temp *= x;
    return temp;
}

int s21_round(double y) { return (int)(y + 0.5); }

char* s21_float_to_string(long double number, int floating) {
    if (number < 0) number *= -1;
    int int_part = number;
    char* str = s21_int_to_string(int_part, 1);
    if (floating == 0) {
        const size_t offset = s21_strlen(str) - 1;
        if (int_part % 2 == 1)
            str[offset] = (((int)(number + 0.5) % 10) + '0');
        else
            str[offset] = (((int)number % 10) + '0');
    } else {
        number -= int_part;
        int f_len = (floating != -1) ? floating : 6;
        str[s21_strlen(str)] = '.';
        char* temp =
                s21_int_to_string(s21_round((1 + number) * s21_pow(10, f_len)), 1);
        for (int i = 0; i <= f_len - 1; i++) temp[i] = temp[i + 1];
        temp[f_len] = '\0';
        s21_strcat(str, temp);
        free(temp);
    }
    return str;
}

char* s21_uint_to_string(unsigned long long number, long int floating) {
    int i = 0;
    char* str = calloc(32, sizeof(char));
    if (number != 0) {
        while (number > 0) {
            str[i++] = (number % 10) + '0';
            number /= 10;
        }
    } else if (floating != 0) {
        str[i] = '0';
    }
    return revers(str, i + 1);
}

void s21_reset_struct(s21* sh21) {
    sh21->format = 0;
    sh21->fill_left = 0;
    sh21->signed_conversion = 0;
    sh21->space_signed_conversion = 0;
    sh21->width = -1;
    sh21->floating = -1;
    sh21->h_flag = 0;
    sh21->l_flag = 0;
    sh21->L_flag = 0;
    //  sh21->pointer = NULL;
    // sh21->fillnull = 0;
}

void fill_result(char* buf, char* result, s21* sh21) {
    s21_strcat(buf, result);
    s21_reset_struct(sh21);
    free(result);
}

void numbers(const char* line, s21* sh21) {
    int atoi = 0;
    while (*line >= '0' && *line <= '9') {
        atoi *= 10;
        atoi += *line;
        line++;
        atoi -= '0';
    }
    if (sh21->floating == -1)
        sh21->width = atoi;
    else if (sh21->floating == 0)
        sh21->floating = atoi;
    // if (line[0] == '0') sh21->fillnull = 1;  // Влад, посмотри
}

void insert_and_free(s21* sh21, char* temp, char* buf, char* result) {
    s21_strcat(result, temp);
    free(temp);
    result = s21_add_spaces(result, sh21);
    fill_result(buf, result, sh21);
}

char* s21_add_spaces(char* line, s21* sh21) {
    int str_len = s21_strlen(line);
    if (str_len < sh21->width) {
        char* temp = calloc(sh21->width + 1, sizeof(char));
        int padding_len = sh21->width - str_len;
        char* spc_ptr = calloc(padding_len + 1, sizeof(char));
        // if (sh21->fillnull > 0) {  // Влад, посмотри
        //  s21_memset(spc_ptr, '0', padding_len);
        // } else {
        s21_memset(spc_ptr, ' ', padding_len);
        // }
        spc_ptr[padding_len] = 0;  // Влад, посмотри
        if (sh21->fill_left == 1) {
            s21_strcat(temp, line);
            s21_strcat(temp, spc_ptr);
        } else {
            s21_strcat(temp, spc_ptr);
            s21_strcat(temp, line);
        }
        free(spc_ptr);
        free(line);
        line = temp;
    }
    return line;
}
