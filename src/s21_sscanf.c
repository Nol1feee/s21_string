/*sscanf implementation*/

#include <stdio.h> /* testing printfs */
#include <stdlib.h> /* malloc */
#include <string.h> // TODO: change to s21_string.h
#include <stdbool.h> /* _Bool */
#include <math.h> /* pow*/

/* for specifiers */
enum {
  spec_c = 1 << 0, 
  spec_d = 1 << 1,
  spec_i = 1 << 2,
  spec_e = 1 << 3,
  spec_E = 1 << 4,
  spec_f = 1 << 5,
  spec_g = 1 << 6,
  spec_G = 1 << 7,
  spec_o = 1 << 8,
  spec_s = 1 << 9,
  spec_u = 1 << 10,
  spec_x = 1 << 11,
  spec_X = 1 << 12,
  spec_p = 1 << 13,
  spec_n = 1 << 14,
  spec_percent = 1 << 15
};

/* for systems */
enum {
  OCT = 8,
  DEC = 10,
  HEX = 16
};

/* for shifts */
enum {
  SHIFT = 48, /* code of 0 in ASCII */
  SHIFT_HEX = 55, /* code of A - 10 in ASCII */
  SHIFT_hex = 87 /* code of a - 10 in ASCII */
};

/* check white-space characters */
static _Bool is_whitespace(char ch) {
  return (ch == ' ' || ch == '\t' || ch == '\n') ? true : false;
}

/* skip white-space chatacters */
static int skip_whitespaces(char **string) {
  int count = 0;
  while (is_whitespace(**string)) {
    (*string)++;
    count++;
  }
  return count;
}

/* skip the whole string */
static void skip_all(char **string) {
  while (**string) {
    (*string)++;
  }
}

/* sets the format_buf pointer to the character after the % */
static void get_specifier(char **str_buf, char **format_buf, _Bool *outsider_ch) {
  int white_count = skip_whitespaces(format_buf);
  if (white_count) {
    skip_whitespaces(str_buf);
  }
  while (**format_buf != '%') { /* skip all regular characters*/
    if (**format_buf != **str_buf) {
      *outsider_ch = true;
    }
    (*format_buf)++;
    (*str_buf)++;  
  }
  /* stoped at % */
  ++(*format_buf);
}

/* check character if it's a digit*/
static _Bool is_digit(char ch) {
  return ((ch >= '0') && (ch <= '9')) ? true : false;
}

/* converts from string to number */
static long str_to_dec(char **string, int width, int sign) {
  long res = **string - SHIFT; /* get the first digit */
  int count = 1;
  (*string)++;
  while (is_digit(**string) && ((count < width) || (!width))) {
    res = res * DEC + (**string - SHIFT);
    (*string)++;
    count++;
  }
  return res * sign;
}

/* check character if it's a length*/
static _Bool is_correct_length(char **format_buf) {
  _Bool res = false;
  char next_ch = *((*format_buf) + 1);
  if (((**format_buf == 'l') || (**format_buf == 'L')) && (next_ch = 'f')) {
    res = true;
  }
  return res;
}

/* set the specs in an integer number according to enum */
static int set_specs(char **format_buf, _Bool *ass_supress, int *width, int *length) {
  int specs = 0;
  while ((**format_buf) && !is_whitespace(**format_buf) && (!specs)) {
    switch (**format_buf) {
      case 'c': 
        specs |= spec_c;
        break;
      case 'd':
        specs |= spec_d;
        break;
      case 'i':
        specs |= spec_i;
        break;
      case 'e':
        specs |= spec_e;
        break;
      case 'E':
        specs |= spec_E;
        break;
      case 'f':
        specs |= spec_f;
        break;
      case 'g':
        specs |= spec_g;
        break;
      case 'G':
        specs |= spec_G;
        break;
      case 'o':
        specs |= spec_o;
        break;
      case 's':
        specs |= spec_s;
        break;
      case 'u':
        specs |= spec_u;
        break;
      case 'x':
        specs |= spec_x;
        break;
      case 'X':
        specs |= spec_X;
        break;
      case 'p':
        specs |= spec_p;
        break;
      case 'n':
        specs |= spec_n;
        break;
      case '%':
        specs |= spec_percent;
        break;
      case '*':
        *ass_supress = true;
        break;

      default:
        if (is_digit(**format_buf) && (**format_buf > '0')) {
          *width = str_to_dec(format_buf, 0, 1); /* get width */
          (*format_buf)--;
        } else if (is_correct_length(format_buf)) {
          *length = **format_buf;
        } else {
          fprintf(stderr, "Incorrect specifier\n");
          // TODO:handle an error
        }
    }
    (*format_buf)++;
  }
  return specs;
}

/* puts string into another vararg*/
static void str_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch, /*int length,*/ int count, char *str_buf_start) {
    if (!ass_supress && !outsider_ch) {
      char *dst_string = va_arg(*argp, char*); /* take argument address */
      strncpy(dst_string, str_buf_start, count); /* put string into argument */
      strncpy(dst_string + count, "\0", 1); /* cut extra garbage */
    }
}

/* */
static int str_to_str(char **str_buf, int width/*, int length*/) {
  int count = 0; /* number of characters */
    while (**str_buf && !is_whitespace(**str_buf) && ((count < width) || !width)) {
      (*str_buf)++; /* go to end of string */
      count++;
    }
  return count;
}

/* put string from source string to another agrument of sscanf */
static void scan_string(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width/*, int length*/) {
  skip_whitespaces(str_buf);
  char *str_buf_start = *str_buf; //save start of string 
  int count = str_to_str(str_buf, width/*, length*/); // number of characters 
  str_into_arg(argp, ass_supress, outsider_ch, /*length,*/ count, str_buf_start);
}

/* check specs if it's a e/E/f/g/G */
static _Bool is_efg(int specs) {
  return ((specs & spec_e) || (specs & spec_E) || (specs & spec_f) || (specs & spec_g) || (specs & spec_G)) ? true : false;
}

/* puts floating point number into another vararg*/
static void fpnum_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch, int length, int specs, long double res) {
  if (!ass_supress && !outsider_ch) {
    if (is_efg(specs) && (length == 'L')) {
      long double *dst_num = va_arg(*argp, long double*); /* take argument address */
      *dst_num = res;
    } else if (is_efg(specs) && (length == 'l')) {
      double *dst_num = va_arg(*argp, double*);
      *dst_num = res;
    } else {
      float *dst_num = va_arg(*argp, float*);
      *dst_num = res;
    }
  }
}

/* checks if the character if a sign or not */
static _Bool is_sign(char ch) {
  return ((ch == '-') || (ch == '+')) ? true : false;
}

/* gets sign and checks that there is no double sign*/
static int sign_check(char **str_buf) {
  int sign = 1;
  char next_ch = *((*str_buf) + 1);
  if ((is_sign(**str_buf)) && (is_sign(next_ch))) {
    sign = 0;
    skip_all(str_buf);
  } else if (**str_buf == '-') {
    sign = -1;
    (*str_buf)++;
  } else if (**str_buf == '+') {
    (*str_buf)++;
  }
  return sign;
}

/* multiplies  the res by a power of 10 from the exponent */
static long double get_exp(long double res, char **str_buf) {
  (*str_buf)++; /* go to the next char, must be a '-' or '+' */
  int sign = sign_check(str_buf);
  int power10 = str_to_dec(str_buf, 0, 1);
  (*str_buf)--;
  res = res * pow(DEC, power10 * sign);
  return res;
}

/* */
static void get_first_fpnum(char **str_buf, int sign, long double *res, int* power10) {
  char next_ch = *((*str_buf) + 1);
  if (is_digit(**str_buf)) {
    *res = (**str_buf - SHIFT) * sign;
    (*str_buf)++;
  } else if ((**str_buf == '.') && (is_digit(next_ch))){
    (*power10)++;
    (*str_buf)++;
  } else {
    // TODO:hanlde error
  }
}

/* */
static void str_to_fpnum(char **str_buf, int width, int sign, int *power10, long double *res) {
  int count = 1; // number of characters (digits or .) 
  while (((count < width) || !width) && **str_buf && !is_whitespace(**str_buf) && (is_digit(**str_buf) || (**str_buf == '.') || (**str_buf == 'e') || (**str_buf == 'E'))) {
    if (is_digit(**str_buf) && (!(*power10))) {
      *res = (*res) * DEC + (**str_buf - SHIFT) * sign;
    } else if (is_digit(**str_buf) && (*power10)) {
      *res = (*res) + ((long double)(**str_buf - SHIFT) / pow(DEC, (*power10)++)) * sign;
    } else if ((**str_buf == '.') && (!(*power10))) {
      (*power10)++;
    } else if ((**str_buf == 'e') || (**str_buf == 'E')) { 
      *res = get_exp(*res, str_buf);
    } else {
      //TODO: handle error
      break;
    }
    (*str_buf)++; 
    count++;
  }
}

/* put floating-point number from source string to another agrument of sscanf */
static void scan_efg(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length, int specs) {
  skip_whitespaces(str_buf);
  int sign = sign_check(str_buf); 
  long double res = 0;
  int power10 = 0; /* for power of 10 */
  get_first_fpnum(str_buf, sign, &res, &power10);
  str_to_fpnum(str_buf, width, sign, &power10, &res);
  fpnum_into_arg(argp, ass_supress, outsider_ch, length, specs, res);
}

/* check if the character is a hexadecimal symbol */
static _Bool is_hex(char ch) {
  return ((is_digit(ch)) || ((ch >= 'A') && (ch <= 'F')) || ((ch >= 'a') && (ch <= 'f'))) ? true : false;
}

/* check if the character is a octal symbol */
static _Bool is_oct(char ch) {
  return ((ch >= '0') && (ch <= '7')) ? true : false;
}

/* check for a prefix and skipping it if it exists */
static int prefix_check(char **str_buf, int specs) {
  int prefix = DEC; // for decimal
  char next_ch = *((*str_buf) + 1);
  char next_next_ch = *((*str_buf) + 2);
  if ((specs & spec_x) || (specs & spec_X) || (specs & spec_p) || (specs & spec_i)) { /* for hexadecimal */
    if ((**str_buf == '0') && ((next_ch == 'x') || (next_ch == 'X')) && is_hex(next_next_ch)) {
      prefix = HEX;
      (*str_buf) += 2;
    }
  }
  if ((specs & spec_o) || (specs & spec_i)) { /* for octal */
    if ((**str_buf == '0') && is_oct(next_ch)) {
      prefix = OCT;
      (*str_buf)++;
    }
  }
  return prefix;
}

/* puts integer number into another vararg*/
static void inum_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch, int length, int specs, long res) {
  if (!ass_supress && !outsider_ch) {
    if (is_efg(specs) && (length == 'l')) {
      long *dst_num = va_arg(*argp, long*); /* take argument address */
      *dst_num = res;
    } else if (is_efg(specs) && (length == 'h')) {
      short *dst_num = va_arg(*argp, short*);
      *dst_num = (short)res;
    } else {
      int *dst_num = va_arg(*argp, int*);
      *dst_num = (int)res;
    }
  }
}

/* puts pointer into another vararg*/
static void pointer_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch, /*int length, int specs,*/ unsigned long res) {
  if (!ass_supress && !outsider_ch) {
    void **dst_pointer;
    dst_pointer = va_arg(*argp, void**);
    printf("dst_pointer: %p\n", dst_pointer);
    printf("res: %lx\n", res); 
    printf("res as p: %p\n", (void**)res); 
    *dst_pointer = (void*)res;
  }
}

/* converts hex characters to numbers */
static short hex_to_num(char hex) {
  short num = 0;
  if (is_digit(hex)) {
    num = hex - SHIFT;
  } else if ((hex >= 'A') && (hex <= 'F')) {
    num = hex - SHIFT_HEX;
  } else {
    num = hex - SHIFT_hex;
  }
  return num;
}

/* convert from string to hexadecimal integer */
static long str_to_hex(char **str_buf, int width, int sign) {
  int count = 0; // number of hexadecimal characters 
  char *hex_start = *str_buf;
  while (((count < width) || !width) && **str_buf && !is_whitespace(**str_buf) && is_hex(**str_buf)) { 
    (*str_buf)++; 
    count++;
  }
  long res = 0;
  char *hex_finish = --(*str_buf); // on last hex
  int power16 = 0;
  for (char *hex_cur = hex_finish; hex_cur >= hex_start; hex_cur--) {
    res += hex_to_num(*hex_cur) * pow(HEX, power16++); 
  }
  res *= sign;
  *str_buf = hex_finish + 1;
  return res;
}

/* put hexadecimal integer from source string to another agrument of sscanf */
static void scan_hex(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length, int specs) {
  skip_whitespaces(str_buf);
  int sign = sign_check(str_buf); /* get sign or check for double sign */
  prefix_check(str_buf, specs); /* skip 0x/0X prefix */
  long res = str_to_hex(str_buf, width, sign); /* convert from string to hex int*/;
  inum_into_arg(argp, ass_supress, outsider_ch, length, specs, res);

}

/* convert from string to octal integer */
static long str_to_oct(char **str_buf, int width, int sign) {
  int count = 0; /* number of octal characters */
  char *oct_start = *str_buf;
  while (((count < width) || !width) && **str_buf && !is_whitespace(**str_buf) && is_oct(**str_buf)) { 
    (*str_buf)++; 
    count++;
  }
  long res = 0;
  char *oct_finish = --(*str_buf); // on last oct
  int power8 = 0;
  for (char *oct_cur = oct_finish; oct_cur >= oct_start; oct_cur--) {
    res += hex_to_num(*oct_cur) * pow(OCT, power8++); 
  }
  res *= sign;
  *str_buf = oct_finish + 1;
  return res;
}

/* put octal integer from source string to another agrument of sscanf */
static void scan_oct(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length, int specs) {
  skip_whitespaces(str_buf);
  int sign = sign_check(str_buf); /* get sign or check for double sign */
  prefix_check(str_buf, specs); /* skip 0 prefix */
  long res = str_to_oct(str_buf, width, sign); /* convert from string to octal int*/
  inum_into_arg(argp, ass_supress, outsider_ch, length, specs, res); /* write down into another arg*/
}

/* put pointer from source string to another agrument of sscanf */
static void scan_pointer(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, /*int length,*/ int specs) {
  skip_whitespaces(str_buf);
  //int sign = sign_check(str_buf); /* get sign or check for double sign */
  prefix_check(str_buf, specs);
  int count = 0; /* number of hexadecimal characters */
  char *hex_start = *str_buf;
  while (((count < width) || !width) && **str_buf && !is_whitespace(**str_buf) && (is_digit(**str_buf) || is_hex(**str_buf))) { 
    (*str_buf)++; 
    count++;
  }
  unsigned long res = 0;
  char *hex_finish = --(*str_buf); // on last hex
  int power16 = 0;
  for (char *hex_cur = hex_finish; hex_cur >= hex_start; hex_cur--) {
    res += hex_to_num(*hex_cur) * pow(HEX, power16++); 
  }
  *str_buf = hex_finish + 1;
  // TODO: str_to_pointer into separate function
  pointer_into_arg(argp, ass_supress, outsider_ch, res);
}

/* */
static void count_chars(char **str_buf, const char* const *str_start, va_list *argp, _Bool ass_supress, _Bool outsider_ch, /*int width,*/ int length, int specs) {
  int amount = *str_buf - *str_start;
  inum_into_arg(argp, ass_supress, outsider_ch, length, specs, amount);
}

/* put signed decimal/octal/hexadecimal integer from source string to another agrument of sscanf */
static void scan_doh(char **str_buf, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length, int specs) {
  skip_whitespaces(str_buf);
  int sign = sign_check(str_buf); /* get sign or check for double sign */
  int prefix = prefix_check(str_buf, specs);
  long res = 0;
  switch (prefix) {
    case DEC: 
      res = str_to_dec(str_buf, width, sign);
      break;
    case OCT:
      res = str_to_oct(str_buf, width, sign);
      break;
    case HEX:
      res = str_to_hex(str_buf, width, sign);
      break;
  }
  inum_into_arg(argp, ass_supress, outsider_ch, length, specs, res);
}

/* scan processing*/
static void scan_proc(char **str_buf, const char* const *str_start, int specs, va_list *argp, _Bool ass_supress, _Bool outsider_ch, int width, int length) {
  if (specs & spec_s) { /* scan strings */
    scan_string(str_buf, argp, ass_supress, outsider_ch, width/*, length*/);
  } // TODO l length for %s ?
  if (is_efg(specs)) { /* scan decimal numbers with floating point or scientific notation */
    scan_efg(str_buf, argp, ass_supress, outsider_ch, width, length, specs);
  }
  if ((specs & spec_x) || (specs & spec_X)) { /* scan hexadecimal integers */
    scan_hex(str_buf, argp, ass_supress, outsider_ch, width, length, specs); 
  }
  if (specs & spec_o) { /* scan octal integers */
    scan_oct(str_buf, argp, ass_supress, outsider_ch, width, length, specs); 
  }
  if (specs & spec_p) { /* scan pointer */
    scan_pointer(str_buf, argp, ass_supress, outsider_ch, width, specs); 
  }
  if (specs & spec_n) { /* count characters read before n */
    count_chars(str_buf, str_start, argp, ass_supress, outsider_ch, width, specs); 
  }
  if (specs & spec_i) { /* scan signed integer: dec/oct/hex */
    scan_doh(str_buf, argp, ass_supress, outsider_ch, width, length, specs); 
  }
}

/* main sscanf function */
int s21_sscanf(const char *str, const char *format, ...) {
  char *str_buf = (char*)malloc(strlen(str) * sizeof(char));
  char *format_buf = (char*)malloc(strlen(format) * sizeof(char));
  const char * const str_start = str_buf; /* save start of string for %n and free() */
  const char * const format_start = format_buf; /* save start of string for free() */
  strcpy(str_buf, str);
  strcpy(format_buf, format);
  printf("str:%s\n", str_buf);
  printf("format:%s\n", format_buf);
  va_list argp;
  va_start(argp, format);
  _Bool outsider_ch = false; /* for outsider characters in the format string*/
  while (*str_buf && *format_buf) {
    get_specifier(&str_buf, &format_buf, &outsider_ch); /* set format_buf to the start of specifier*/
    printf("str:%s\n", str_buf);
    printf("format:%s\n", format_buf);
    _Bool ass_supress = false; /* supress assignment (*) */
    int width = 0, length = 0;
    int specs = set_specs(&format_buf, &ass_supress, &width, &length); /* fill the specs number */
    printf("width = %d, length = %c = %d\n", width, length, length);
    if (specs & spec_p) {
      printf("ok\n");
    }
    scan_proc(&str_buf, &str_start, specs, &argp, ass_supress, outsider_ch, width, length);
    printf("specs = %d\n", specs);
  }
  va_end(argp);
  free((void*)str_start);
  free((void*)format_start);
  return 0;
}
