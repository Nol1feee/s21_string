#include "test_string.h"
#define BUFF_SIZE 100

START_TEST(sscanf_EOF1) {
  char str[] = "";
  char *fstr = "%d";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF2) {
  char str[] = "            \t";
  char *fstr = "%d";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF3) {
  char str[] = "      \t\0";
  char *fstr = "%d";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF4) {
  char str[] = "NewString21";
  char *fstr = "";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF5) {
  char str[] = "NewString21";
  char *fstr = "%";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(sscanf_fail1) {
//   char str[] = "21";
//   char *fstr = "%ds";
//   int a1 = 0, a2 = 0;

//   int res1 = s21_sscanf(str, fstr, &a1);
//   int res2 = sscanf(str, fstr, &a2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sscanf_fail2) {
//   char str[] = "21";
//   char *fstr = "%sz";
//   int a1 = 0, a2 = 0;

//   int res1 = s21_sscanf(str, fstr, &a1);
//   int res2 = sscanf(str, fstr, &a2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(sscanf_fail6) {
//   char str[] = "21 \t \r 25\0";
//   char *fstr = "%d %*n %d";
//   int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;

//   int res1 = s21_sscanf(str, fstr, &a1, &a3, &a5);
//   int res2 = sscanf(str, fstr, &a2, &a4, &a6);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

//START_TEST(sscanf_fail7) {
//  char str[] = "21";
//  char *fstr = "%q";
//  int a1 = 0, a2 = 0;
//
//  int res1 = s21_sscanf(str, fstr, &a1);
//  int res2 = sscanf(str, fstr, &a2);
//  ck_assert_int_eq(res1, res2);
//}
//END_TEST

// START_TEST(sscanf_format_c1) {
//   char str[] = "   a     b c d";
//   char *fstr = "%c %c %c %c";
//   int a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_c2) {
//   char str[] = "   a     b c d";
//   char *fstr = "%c %c %c %c";
//   int a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_c3) {
//   char str[] = "abcd";
//   char *fstr = "%c %c %c %c";
//   int a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_c4) {
//   char str[] = "\tabcd";
//   char *fstr = "%c %*c %*c %c";
//   int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_c5) {
//   char str[] = " a\t\\\r";
//   char *fstr = "%c%c%c%c";
//   int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

//START_TEST(sscanf_long_chars1) {
//  char str[] = "\tabcd";
//  char *fstr = "%1lc %*lc %*lc %lc";
//  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//
//  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//  ck_assert_int_eq(res1, res2);
//  ck_assert_int_eq(a1, a2);
//  ck_assert_int_eq(b1, b2);
//  ck_assert_int_eq(c1, c2);
//  ck_assert_int_eq(d1, d2);
//}
//END_TEST

//START_TEST(sscanf_long_chars2) {
//  char str[] = "\t abcd efg asd";
//  char *fstr = "%lc %lc %lc %n";
//  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//
//  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//  ck_assert_int_eq(res1, res2);
//  ck_assert_int_eq(a1, a2);
//  ck_assert_int_eq(b1, b2);
//  ck_assert_int_eq(c1, c2);
//  ck_assert_int_eq(d1, d2);
//}
//END_TEST
//
//START_TEST(sscanf_long_chars3) {
//  char str[] = "\t abcd efg asd";
//  char *fstr = "%lc %lc%lc %n";
//  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//
//  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//  ck_assert_int_eq(res1, res2);
//  ck_assert_int_eq(a1, a2);
//  ck_assert_int_eq(b1, b2);
//  ck_assert_int_eq(c1, c2);
//  ck_assert_int_eq(d1, d2);
//}
//END_TEST

// START_TEST(sscanf_format_d1) {
//   int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "555562187237128730893213890 666 777 888";
//   const char *fstr = "%d %10d %*d %d";

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_d2) {
//   short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "555367 1234 -32768 32768";
//   const char *fstr = "%4hd %3hd %hd %hd";

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_d3) {
//   long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "1000000000 -2147483648 2147483648 l1";
//   const char *fstr = "%10ld %ld %ld %*ld";

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_d4) {
//   short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "-7 1234 -32768 ++++32768";
//   const char *fstr = "%hd %3hd %hd %hd";

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_d5) {
//   short a1 = 0, a2 = 0;
//   long b1 = 0, b2 = 0;
//   int c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "    0567a+1234\t--32768d 1337";
//   const char *fstr = "%4hda%ld%d%2d";

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(sscanf_format_d6) {
//   short a1 = 0, a2 = 0;
//   long b1 = 0, b2 = 0;
//   int c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//   const char str[] = "    a555367a+1234\t--32768d 1337";
//   const char *fstr = " a%hda%ld%d%2d";

//   int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(b1, b2);
//   ck_assert_int_eq(c1, c2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

START_TEST(sscanf_format_i1) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "5555621 0666 0x777 0X888";
  const char *fstr = "%8i %10i %i %*i";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_i2) {
  short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "5555621 0666 0x777 0x";
  const char *fstr = "%4hi %*10hi %hi %hi";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_i3) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "5555621\t\t\t\n0666\00x777 MK";
  const char *fstr = "%4li%*10li %li %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_i4) {
  short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "+5555621 -0666 0xZZZ777 0X888";
  const char *fstr = "%4hi%*10hi %hi %hi";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_i5) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0xFFFFF -0x0666 0xABCDEF 0x0";
  const char *fstr = "%i %i %i %i";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_i6) {
  short a1 = 0, a2 = 0;
  int b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0xFFFFF -0x0666 0x 0xABCDEF";
  const char *fstr = "%hi%*i%2i %i";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_efg1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1e6 -15.8e3 EE1 ";
  const char *fstr = "%e %f %G %g";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_efg2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0.115e-3 -inf +inf nAn ";
  const char *fstr = "%e %f %G %E";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
}
END_TEST

START_TEST(sscanf_format_efg3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0.115e-3 \t\n +INfiNity 0.3e-6 +infINAty ";
  const char *fstr = "%e %f %G %E";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_efg4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] =
      "\n \t5679.e10 \t\n +15268.E5 +0.123456e+3 \t\n  -103728.618e-7";
  const char *fstr = "%Le %7Lf %*LG %Lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_efg5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  long double c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] =
      "\n \t1452.5e10 \t\n 163829463 .61553814e15 \t\n  -516173.1469e5";
  const char *fstr = "%6e %*g %LG %Lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_efg6) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  long double c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = 0, res2 = 0;
  const char str[] =
      "\n \tt1452.5e10 \t\n 163829463 .61553814e15 \t\n  -516173.1469e5";
  const char *fstr = "%7e %*g %LG %Lf";

  res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_o1) {
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "\n \t+0178392 \t\n -5628\t\n 01576 +0Z";
  const char *fstr = "%o %o %*o %";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_o2) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "\n \t+01783 \t\n -5628\t\n 01A576 +01337";
  const char *fstr = "%ho %ho %5ho %*4o";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_o3) {
  unsigned long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "\n \t+0178392 \t\n -5628\t\n 01576 +0Z";
  const char *fstr = "%lo %lo %3lo %*lo";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_s1) {
  int n1 = 1, n2 = 5;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char *fstr = "%5s %4s %n %3s";

  int res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(sscanf_format_s3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char *fstr = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_format_s4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char *fstr = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_format_s5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char *fstr = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_format_u1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char *fstr = "%hu %hu %hu %hu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_u2) {
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 1234567 -55555 777";
  const char *fstr = "%*u %6u %5u %4u";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_u3) {
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                    d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char *fstr = "%lu %2u %5lu %4lu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_u4) {
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                    d2 = 0;
  const char str[] = "-1337 V233333331 5008 3000";
  const char *fstr = "%lu %2u %5lu %4lu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_x1) {
  unsigned int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "+0x82196F -FFFF 0xFFF 0XX1337";
  const char *fstr = "%X %x %x %x";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_p1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char *fstr = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_p2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char *fstr = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_p3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "-0xFFFF -0xAAAa 7A2b3d 0xABCDEF";
  const char *fstr = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_format_p4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "-0xFFFF -0xFAAAa vz7A2b3d 0xABCDEF";
  const char *fstr = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n1) {
  int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
  int n1 = 500, n2 = 10000;

  const char str[] = "123123%SkipMePlease!!!!123";
  const char *fstr = "%d%%SkipMePlease!!!!%d %n";

  int res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
  int res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n2) {
  int a1, a2;
  int b1 = 80, b2 = 33;
  int c1 = 55, c2 = 33;
  int n1 = 0, n2 = 0;
  const char str[] = "12%13%14";
  const char *fstr = "%d%%%d%%%d	%n";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &n1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n3) {
  int a1 = 1234, a2 = 33333;
  int b1 = 1234, b2 = 33333;

  const char str[] = "%%123%888";
  const char *fstr = "%%%%%d%%%d";
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

Suite *sscanf_s21() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sscanf");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_EOF1);
  tcase_add_test(tc_core, sscanf_EOF2);
  tcase_add_test(tc_core, sscanf_EOF3);
  tcase_add_test(tc_core, sscanf_EOF4);
  tcase_add_test(tc_core, sscanf_EOF5);
//   tcase_add_test(tc_core, sscanf_fail1);
//   tcase_add_test(tc_core, sscanf_fail2);
//   tcase_add_test(tc_core, sscanf_fail6);
//  tcase_add_test(tc_core, sscanf_fail7);
//   tcase_add_test(tc_core, sscanf_format_c1);
//   tcase_add_test(tc_core, sscanf_format_c2);
//   tcase_add_test(tc_core, sscanf_format_c3);
//   tcase_add_test(tc_core, sscanf_format_c4);
//   tcase_add_test(tc_core, sscanf_format_c5);
//  tcase_add_test(tc_core, sscanf_long_chars1);
//  tcase_add_test(tc_core, sscanf_long_chars2);
//  tcase_add_test(tc_core, sscanf_long_chars3);
//   tcase_add_test(tc_core, sscanf_format_d1);
//   tcase_add_test(tc_core, sscanf_format_d2);
//   tcase_add_test(tc_core, sscanf_format_d3);
//   tcase_add_test(tc_core, sscanf_format_d4);
//   tcase_add_test(tc_core, sscanf_format_d5);
//   tcase_add_test(tc_core, sscanf_format_d6);
  tcase_add_test(tc_core, sscanf_format_i1);
  tcase_add_test(tc_core, sscanf_format_i2);
  tcase_add_test(tc_core, sscanf_format_i3);
  tcase_add_test(tc_core, sscanf_format_i4);
  tcase_add_test(tc_core, sscanf_format_i5);
  tcase_add_test(tc_core, sscanf_format_i6);
  tcase_add_test(tc_core, sscanf_format_efg1);
  tcase_add_test(tc_core, sscanf_format_efg2);
  tcase_add_test(tc_core, sscanf_format_efg3);
  tcase_add_test(tc_core, sscanf_format_efg4);
  tcase_add_test(tc_core, sscanf_format_efg5);
  tcase_add_test(tc_core, sscanf_format_efg6);
  tcase_add_test(tc_core, sscanf_format_o1);
  tcase_add_test(tc_core, sscanf_format_o2);
  tcase_add_test(tc_core, sscanf_format_o3);
  tcase_add_test(tc_core, sscanf_format_s1);
  tcase_add_test(tc_core, sscanf_format_s3);
  tcase_add_test(tc_core, sscanf_format_s4);
  tcase_add_test(tc_core, sscanf_format_s5);
  tcase_add_test(tc_core, sscanf_format_u1);
  tcase_add_test(tc_core, sscanf_format_u2);
  tcase_add_test(tc_core, sscanf_format_u3);
  tcase_add_test(tc_core, sscanf_format_u4);
  tcase_add_test(tc_core, sscanf_format_x1);
  tcase_add_test(tc_core, sscanf_format_p1);
  tcase_add_test(tc_core, sscanf_format_p2);
  tcase_add_test(tc_core, sscanf_format_p3);
  tcase_add_test(tc_core, sscanf_format_p4);
  tcase_add_test(tc_core, sscanf_n1);
  tcase_add_test(tc_core, sscanf_n2);
  tcase_add_test(tc_core, sscanf_n3);

  suite_add_tcase(s, tc_core);

  return s;
}
