// // #include "s21_string.h"

// s21_size_t s21_strcspn(const char *str1, const char *str2) {
//   s21_size_t count = 0;
//   for (const char *a = str1; *a; a++) {
//     int fl = 0;
//     for (const char *b = str2; *b; b++) {
//       if (*a == *b) {
//         fl = 1;
//         break;
//       }
//     }
//     if (!fl) {
//       count++;
//     } else {
//       break;
//     }
//   }
//   return count;
// }