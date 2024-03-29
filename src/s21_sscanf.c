/*sscanf implementation*/
#include "s21_string.h"

/* for systems */
enum { OCT = 8, DEC = 10, HEX = 16 };

/* check white-space characters */
bool is_whitespace(char ch) {
  return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') ? true : false;
}

/* check non white-space characters */
bool isnt_whitespace(char ch) { return !is_whitespace(ch); }

/* is not an end of string  */
bool isnt_end(char ch) { return ch; }

/* func for skipping different characters */
int skip(const char **string, bool (*skip_cond)(char)) {
  int count = 0;
  while (**string && (*skip_cond)(**string)) {
    (*string)++;
    count++;
  }
  return count;
}

/* sets the format pointer to the character after the % */
static void get_specifier(const char **str, const char **format,
                          _Bool *outsider_ch) {
  int white_count = skip(format, is_whitespace);
  if (white_count) {
    skip(str, is_whitespace);
  }
  while (**format != '%') { /* skip all regular characters*/
    if (**format != **str) {
      *outsider_ch = true;
    }
    (*format)++;
    (*str)++;
  }
  /* stoped at % */
  ++(*format);
}

/* check character if it's a digit*/
bool is_digit(char ch) { return ((ch >= '0') && (ch <= '9')) ? true : false; }

/* checks if the character if a sign or not */
static _Bool is_sign(char ch) {
  return ((ch == '-') || (ch == '+')) ? true : false;
}

/* gets sign and checks that there is no double sign*/
static int sign_check(const char **str, int *count) {
  int sign = 1;
  char next_ch = *((*str) + 1);
  if ((is_sign(**str)) && (is_sign(next_ch))) {
    sign = 0;
    skip(str, isnt_end);
    // TODO: handle error
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
    (*count)++;
  } else if (**str == '+') {
    (*str)++;
    (*count)++;
  }
  return sign;
}

/* converts from string to number */
long str_to_dec(const char **string, int width, int sign, int count, int *err) {
  // sign = sign_check(string, &count);
  long res = 0;
  bool overflow = false;
  *err = ER;
  if (is_digit(**string)) {
    res = **string - SHIFT_zero; /* get the first digit */
    count++;                     // if was a sign, then count 1++, else 0++
    (*string)++;
    while (is_digit(**string) && ((count < width) || (!width)) && !overflow) {
      overflow = (res > (((INT_MAX - (**string - SHIFT_zero)) / 10) + 1))
                     ? true
                     : false;
      res = res * DEC + (**string - SHIFT_zero);
      (*string)++;
      count++;
    }
    *err = OK;
  }
  res = res * sign;
  if (overflow) {
    res = -1;
    skip(string, isnt_whitespace);
  }
  return res;
}

/* check character if it's a length*/
static bool is_correct_length(const char **format) {
  bool res = false;
  char next_ch = *((*format) + 1);
  if ((((**format == 'l') || (**format == 'L')) && (next_ch = 'f')) ||
      (**format == 'h')) {
    res = true;
  }
  return res;
}

/* set the specs in an integer number according to enum */
int set_specs(const char **format, bool *ass_supress, int *width, int *length,
              int *err) {
  int specs = 0;
  while ((**format) && !is_whitespace(**format) && (!specs)) {
    switch (**format) {
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
        if (is_digit(**format) && (**format > '0')) {
          *width =
              str_to_dec(format, 0, 1, 0,
                         err); /* get width (str, width, sign, count, err);*/
          (*format)--;
        } else if (is_correct_length(format)) {
          *length = **format;
        } else {
          fprintf(stderr, "Incorrect specifier\n");
          // TODO:handle an error
        }
    }
    (*format)++;
  }
  return specs;
}

/* puts string into another vararg*/
static void str_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch,
                         /*int length,*/ int count, const char *str_start,
                         int *ret) {
  if (!ass_supress && !outsider_ch) {
    char *dst_string = va_arg(*argp, char *);  /* take argument address */
    s21_strncpy(dst_string, str_start, count); /* put string into argument */
    s21_strncpy(dst_string + count, "\0", 1);  /* cut extra garbage */
    (*ret)++;
  }
}

/* */
static int str_to_str(const char **str, int width /*, int length*/) {
  int count = 0; /* number of characters */
  while (**str && !is_whitespace(**str) && ((count < width) || !width)) {
    (*str)++; /* go to end of string */
    count++;
  }
  return count;
}

/* put string from source string to another agrument of sscanf */
static void scan_string(const char **str, va_list *argp, bool ass_supress,
                        bool outsider_ch, int width, int *ret) {
  skip(str, is_whitespace);
  const char *str_start = *str;        // save start of string
  int count = str_to_str(str, width);  // number of characters
  str_into_arg(argp, ass_supress, outsider_ch, count, str_start, ret);
}

/* check specs if it's a e/E/f/g/G */
static _Bool is_efg(int specs) {
  return ((specs & spec_e) || (specs & spec_E) || (specs & spec_f) ||
          (specs & spec_g) || (specs & spec_G))
             ? true
             : false;
}

/* puts floating point number into another vararg*/
static void fpnum_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch,
                           int length, int specs, long double res, int *ret,
                           int *err) {
  if (!ass_supress && !outsider_ch && !(*err)) {
    if (is_efg(specs) && (length == 'L')) {
      long double *dst_num =
          va_arg(*argp, long double *); /* take argument address */
      *dst_num = res;
    } else if (is_efg(specs) && (length == 'l')) {
      double *dst_num = va_arg(*argp, double *);
      *dst_num = res;
    } else {
      float *dst_num = va_arg(*argp, float *);
      *dst_num = res;
    }
    (*ret)++;
  }
}

/* multiplies  the res by a power of 10 from the exponent */
static long double get_exp(long double res, const char **str, int *err) {
  (*str)++; /* go to the next char, must be a '-' or '+' */
  int count = 0;
  int sign = sign_check(str, &count);
  int power10 =
      str_to_dec(str, 0, sign, 0, err);  // str, width, sign, count, err
  (*str)--;
  res = res * pow(DEC, power10);
  return res;
}

/* sample must be only in lower case!!! */
static bool match_up(const char **str, const char *sample, int *jump) {
  bool match = true;
  int i = 0;
  for (i = 0; i < (int)s21_strlen(sample); i++) {
    if (((*((*str) + i)) != sample[i]) &&
        ((*((*str) + i)) != (sample[i] - SHIFT_case))) {
      match = false;
      break;
    }
  }
  *jump = i;
  //(*str) += i; // put on the next ch after the last match
  return match;
}

/* check if the 'i' character is inf and get value if yes */
static long double get_inf(const char **str, int *err) {
  long double res = 0;
  int jump = 0;  // by how much will we shift the str
  if (match_up(str, "infinity ", &jump) || match_up(str, "inf ", &jump)) {
    res = INFINITY;
    (*str) += jump;  // put on the next ch after the last match
    printf("=== %s ===\n", *str);
  } else {
    *err = ER;
  }
  return res;
}

/* check if the 'n' character is nan and get value if yes */
static long double get_nan(const char **str, int *err) {
  char next_ch = *((*str) + 1);
  char next_next_ch = *((*str) + 2);
  long double res = 0;
  if ((next_ch == 'a' || next_ch == 'A') &&
      (next_next_ch == 'n' || next_next_ch == 'N')) {
    res = NAN;
    (*str) += 3;  // go to the next character after inf
  } else {
    *err = ER;
  }
  return res;
}

/* */
static void get_first_fpnum(const char **str, int sign, int *count,
                            long double *res, int *power10, int *err) {
  char next_ch = *((*str) + 1);
  if (is_digit(**str)) {
    *res = (**str - SHIFT_zero) * sign;
    (*str)++;
    (*count)++;
  } else if ((**str == '.') && (is_digit(next_ch))) {
    (*power10)++;
    (*str)++;
    (*count)++;
  } else if ((**str == 'i') || (**str == 'I')) {
    *res = get_inf(str, err) * sign;
  } else if ((**str == 'n') || (**str == 'N')) {
    *res = get_nan(str, err) * sign;
  } else {
    // TODO:hanlde error
    *err = ER;
  }
}

/* */
static void str_to_fpnum(const char **str, int width, int sign, int count,
                         int *power10, long double *res, int *err) {
  // int count = 1; // number of characters (digits or .)
  while (
      ((count < width) || !width) && **str && !is_whitespace(**str) &&
      (is_digit(**str) || (**str == '.') || (**str == 'e') || (**str == 'E'))) {
    if (is_digit(**str) && (!(*power10))) {
      *res = (*res) * DEC + (**str - SHIFT_zero) * sign;
    } else if (is_digit(**str) && (*power10)) {
      *res =
          (*res) +
          ((long double)(**str - SHIFT_zero) / pow(DEC, (*power10)++)) * sign;
    } else if ((**str == '.') && (!(*power10))) {
      (*power10)++;
    } else if ((**str == 'e') || (**str == 'E')) {
      *res = get_exp(*res, str, err);
    } else {
      // TODO: handle error
      *err = ER;
      break;
    }
    (*str)++;
    count++;
  }
}

/* put floating-point number from source string to another agrument of sscanf */
static void scan_efg(const char **str, va_list *argp, _Bool ass_supress,
                     _Bool outsider_ch, int width, int length, int specs,
                     int *ret, int *err) {
  skip(str, is_whitespace);
  int count =
      0;  // TODO: finish sign handle as +1 character into count (for width)
  int sign = sign_check(str, &count);
  long double res = 0;
  int power10 = 0; /* for power of 10 */
  get_first_fpnum(str, sign, &count, &res, &power10, err);
  if (!(*err) && (res != INFINITY) && (res != NAN)) {
    str_to_fpnum(str, width, sign, count, &power10, &res, err);
  }
  if (!(*err)) {
    fpnum_into_arg(argp, ass_supress, outsider_ch, length, specs, res, ret,
                   err);
  }
}

/* check if the character is a hexadecimal symbol */
static _Bool is_hex(char ch) {
  return ((is_digit(ch)) || ((ch >= 'A') && (ch <= 'F')) ||
          ((ch >= 'a') && (ch <= 'f')))
             ? true
             : false;
}

/* check if the character is a octal symbol */
static _Bool is_oct(char ch) {
  return ((ch >= '0') && (ch <= '7')) ? true : false;
}

/* check for a prefix and skipping it if it exists */
static int prefix_check(const char **str, int specs, int *count, int *sign) {
  *sign = sign_check(str, count);
  int prefix = DEC;  // for decimal
  char next_ch = *((*str) + 1);
  char next_next_ch = *((*str) + 2);
  if ((specs & spec_x) || (specs & spec_X) || (specs & spec_p) ||
      (specs & spec_i)) { /* for hexadecimal */
    if ((**str == '0') && ((next_ch == 'x') || (next_ch == 'X')) &&
        (is_hex(next_next_ch) || is_whitespace(next_next_ch) ||
         !next_next_ch)) {
      prefix = HEX;
      (*str) += 2;
    }
  }
  if ((specs & spec_o) || (specs & spec_i)) { /* for octal */
    if ((**str == '0') && is_oct(next_ch)) {
      prefix = OCT;
      (*str)++;
    }
  }
  return prefix;
}

/* puts signed integer number into another vararg*/
static void inum_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch,
                          int length, int specs, long res, int *ret) {
  if (!ass_supress && !outsider_ch) {
    if (specs & spec_c) {
      char *dst_char = va_arg(*argp, char *);
      *dst_char = res;
    } else if (length == 'l') {
      long *dst_num = va_arg(*argp, long *); /* take argument address */
      *dst_num = res;
    } else if (length == 'h') {
      short *dst_num = va_arg(*argp, short *);
      *dst_num = (short)res;
    } else {
      int *dst_num = va_arg(*argp, int *);
      *dst_num = (int)res;
    }
  }
  if (!(specs & spec_n)) {
    (*ret)++;
  }
}

/* puts insigned integer number into another vararg*/
static void uint_into_arg(va_list *argp, _Bool ass_supress, _Bool outsider_ch,
                          int length, int specs, long res, int *ret) {
  if (!ass_supress && !outsider_ch) {
    if (length == 'l') {
      unsigned long *dst_num =
          va_arg(*argp, unsigned long *); /* take argument address */
      *dst_num = res;
    } else if (length == 'h') {
      unsigned short *dst_num = va_arg(*argp, unsigned short *);
      *dst_num = (short)res;
    } else {
      unsigned int *dst_num = va_arg(*argp, unsigned int *);
      *dst_num = (int)res;
    }
    if (!(specs & spec_n)) {
      (*ret)++;
    }
  }
}

/* puts pointer into another vararg*/
static void pointer_into_arg(va_list *argp, _Bool ass_supress,
                             _Bool outsider_ch, unsigned long res, int *ret) {
  if (!ass_supress && !outsider_ch) {
    void **dst_pointer;
    dst_pointer = va_arg(*argp, void **);
    *dst_pointer = (void *)res;
    (*ret)++;
  }
}

/* converts hex characters to numbers */
static short hex_to_num(char hex) {
  short num = 0;
  if (is_digit(hex)) {
    num = hex - SHIFT_zero;
  } else if ((hex >= 'A') && (hex <= 'F')) {
    num = hex - SHIFT_HEX;
  } else {
    num = hex - SHIFT_hex;
  }
  return num;
}

/* convert from string to hexadecimal integer */
static long str_to_hex(const char **str, int width, int sign, int count,
                       int *err) {
  // int sign = sign_check(str, &count);
  *err = ER;
  long res = 0;
  if (is_hex(**str) || is_whitespace(**str) || !(**str)) {
    const char *hex_start = *str;
    while (((count < width) || !width) && **str && !is_whitespace(**str) &&
           is_hex(**str)) {
      (*str)++;
      count++;
    }
    const char *hex_finish = --(*str);  // on last hex
    int power16 = 0;
    for (const char *hex_cur = hex_finish; hex_cur >= hex_start; hex_cur--) {
      res += hex_to_num(*hex_cur) * pow(HEX, power16++);
    }
    res *= sign;
    *str = hex_finish + 1;
    *err = OK;
  }
  return res;
}

/* put hexadecimal integer from source string to another agrument of sscanf */
static void scan_hex(const char **str, va_list *argp, _Bool ass_supress,
                     _Bool outsider_ch, int width, int length, int specs,
                     int *ret, int *err) {
  skip(str, is_whitespace);
  int count = 0,
      sign =
          0;  // TODO: finish sign handle as +1 character into count (for width)
  // int sign = sign_check(str, &count); /* get sign or check for double sign */
  prefix_check(str, specs, &count, &sign); /* skip 0x/0X prefix */
  long res = str_to_hex(str, width, sign, count,
                        err); /* convert from string to hex int*/
  ;
  if (!(*err)) {
    inum_into_arg(argp, ass_supress, outsider_ch, length, specs, res, ret);
  }
}

/* convert from string to octal integer */
static long str_to_oct(const char **str, int width, int sign, int count,
                       int *err) {
  // sign = sign_check(str, &count);
  long res = 0;
  *err = ER;
  if (is_oct(**str)) {
    const char *oct_start = *str;
    while (((count < width) || !width) && **str && !is_whitespace(**str) &&
           is_oct(**str)) {
      (*str)++;
      count++;
    }
    const char *oct_finish = --(*str);  // on last oct
    int power8 = 0;
    for (const char *oct_cur = oct_finish; oct_cur >= oct_start; oct_cur--) {
      res += hex_to_num(*oct_cur) * pow(OCT, power8++);
    }
    res *= sign;
    *str = oct_finish + 1;
    *err = OK;
  }
  return res;
}

/* put octal integer from source string to another agrument of sscanf */
static void scan_oct(const char **str, va_list *argp, _Bool ass_supress,
                     _Bool outsider_ch, int width, int length, int specs,
                     int *ret, int *err) {
  skip(str, is_whitespace);
  int count = 0,
      sign =
          0;  // TODO: finish sign handle as +1 character into count (for width)
  prefix_check(str, specs, &count, &sign); /* skip 0 prefix */
  long res = str_to_oct(str, width, sign, count,
                        err); /* convert from string to octal int*/
  if (!(*err)) {
    inum_into_arg(argp, ass_supress, outsider_ch, length, specs, res,
                  ret); /* write down into another arg*/
  }
}

/* put pointer from source string to another agrument of sscanf */
static void scan_pointer(const char **str, va_list *argp, _Bool ass_supress,
                         _Bool outsider_ch, int width, int specs, int *ret,
                         int *err) {
  *err = ER;
  skip(str, is_whitespace); /* number of hexadecimal characters */
  int count = 0,
      sign =
          0;  // TODO: finish sign handle as +1 character into count (for width)
  // int sign = sign_check(str); /* get sign or check for double sign */
  prefix_check(str, specs, &count, &sign); /* skip 0x prefix */
  if (is_hex(**str)) {
    const char *hex_start = *str;
    while (((count < width) || !width) && **str && !is_whitespace(**str) &&
           is_hex(**str)) {
      (*str)++;
      count++;
    }
    unsigned long res = 0;
    const char *hex_finish = --(*str);  // on last hex
    int power16 = 0;
    for (const char *hex_cur = hex_finish; hex_cur >= hex_start; hex_cur--) {
      res += hex_to_num(*hex_cur) * pow(HEX, power16++);
    }
    *str = hex_finish + 1;
    res *= sign;
    pointer_into_arg(argp, ass_supress, outsider_ch, res, ret);
    *err = OK;
  }
}

/* */
static void count_chars(const char **str, const char *const *str_start,
                        va_list *argp, _Bool ass_supress, _Bool outsider_ch,
                        int length, int specs, int *ret) {
  int amount = *str - *str_start;
  inum_into_arg(argp, ass_supress, outsider_ch, length, specs, amount, ret);
}

/* put signed decimal/octal/hexadecimal integer from source string to another
 * agrument of sscanf */
static void scan_doh(const char **str, va_list *argp, bool ass_supress,
                     bool outsider_ch, int width, int length, int specs,
                     int *ret, int *err) {
  skip(str, is_whitespace);
  if (**str) {
    int count = 0, sign = 0;
    int prefix = 0;
    prefix = prefix_check(str, specs, &count, &sign);
    long res = 0;
    switch (prefix) {
      case DEC:
        res = str_to_dec(str, width, sign, count, err);
        break;
      case OCT:
        res = str_to_oct(str, width, sign, count, err);
        break;
      case HEX:
        res = str_to_hex(str, width, sign, count, err);
        break;
    }
    if (!(*err)) {
      inum_into_arg(argp, ass_supress, outsider_ch, length, specs, res, ret);
    }
  } else {
    *ret = EOF;
  }
}

/* put unsigned decimal integer from source string to another agrument of sscanf
 */
static void scan_uint(const char **str, va_list *argp, bool ass_supress,
                      bool outsider_ch, int width, int length, int specs,
                      int *ret, int *err) {
  skip(str, is_whitespace);
  if (**str) {
    int count = 0, sign = 0;
    sign = sign_check(str, &count);
    int res = 0;
    res = str_to_dec(str, width, sign, count, err);
    if (!(*err)) {
      uint_into_arg(argp, ass_supress, outsider_ch, length, specs, res, ret);
    }
  } else {
    *ret = EOF;
  }
}

/* */
static void scan_percent(const char **str,
                         /*va_list *argp, bool ass_supress, bool outsider_ch,
                            int width, int length, int specs, int *ret,*/
                         int *err) {
  skip(str, is_whitespace);
  if (**str) {
    if (**str == '%') {
      (*str)++;
    } else {
      *err = ER;
    }
  }
}

static void scan_char(const char **str, va_list *argp, bool ass_supress,
                      bool outsider_ch, int width, int specs, int *ret) {
  skip(str, is_whitespace);

  inum_into_arg(argp, ass_supress, outsider_ch, 0, specs, **str, ret);
  if (width) {
    (*str) += width;
  } else
    (*str)++;
}

/* scan processing*/
static void scan_proc(const char **str, const char *const *str_start, int specs,
                      va_list *argp, _Bool ass_supress, _Bool outsider_ch,
                      int width, int length, int *ret, int *err) {
  if (specs & spec_s) { /* scan strings */
    scan_string(str, argp, ass_supress, outsider_ch, width, ret);
  }
  if (is_efg(specs)) { /* scan decimal numbers with floating point or scientific
                          notation */
    scan_efg(str, argp, ass_supress, outsider_ch, width, length, specs, ret,
             err);
  }
  if ((specs & spec_x) || (specs & spec_X)) { /* scan hexadecimal integers */
    scan_hex(str, argp, ass_supress, outsider_ch, width, length, specs, ret,
             err);
  }
  if (specs & spec_o) { /* scan octal integers */
    scan_oct(str, argp, ass_supress, outsider_ch, width, length, specs, ret,
             err);
  }
  if (specs & spec_p) { /* scan pointer */
    scan_pointer(str, argp, ass_supress, outsider_ch, width, specs, ret, err);
  }
  if (specs & spec_n) { /* count characters read before n */
    count_chars(str, str_start, argp, ass_supress, outsider_ch, width, specs,
                ret);
  }
  if ((specs & spec_i) ||
      (specs & spec_d)) { /* scan signed integer: dec/oct/hex */
    scan_doh(str, argp, ass_supress, outsider_ch, width, length, specs, ret,
             err);
  }
  if (specs & spec_u) { /* scan unsigned decimal integer*/
    scan_uint(str, argp, ass_supress, outsider_ch, width, length, specs, ret,
              err);
  }
  if (specs & spec_percent) { /* scan '%'*/
    scan_percent(
        str,
        /*argp, ass_supress, outsider_ch, width, length, specs, ret,*/ err);
  }
  if (specs & spec_c) {
    scan_char(str, argp, ass_supress, outsider_ch, width, specs, ret);
  }
}

/* main sscanf function */
int s21_sscanf(const char *str, const char *format, ...) {
  const char *const str_start =
      str; /* save start of string for %n and free() */
  va_list argp;
  va_start(argp, format);
  bool outsider_ch = false; /* for outsider characters in the format string*/
  int ret = 0, err = OK;
  if (!(*str) && *format) {
    ret = EOF;
  }
  while ((*str || *format) && (!err)) {
    get_specifier(&str, &format,
                  &outsider_ch); /* set format to the start of specifier*/
    printf("str:%s\n", str);
    printf("format:%s\n", format);
    bool ass_supress = false; /* supress assignment (*) */
    int width = 0, length = 0;
    int specs = set_specs(&format, &ass_supress, &width, &length,
                          &err); /* fill the specs number */
    if (!(*str) && !(specs & spec_n)) {
      break;
    }
    scan_proc(&str, &str_start, specs, &argp, ass_supress, outsider_ch, width,
              length, &ret, &err);
  }
  va_end(argp);
  return ret;
}
