#include "test_string.h"

int main(void) {
    int failed = 0;
    Suite *s21_string_test[] = {
        strlen_s21(), strtok_s21(), strncat_s21(), strcat_s21(), strerror_s21(),
        memchr_s21(), strchr_s21(), strpbrk_s21(), strrchr_s21(), memcmp_s21(),
        strcmp_s21(), strncmp_s21(), strspn_s21(), strcspn_s21(),  
        NULL
    };
    for (int i = 0; s21_string_test[i] != NULL; i++) {
        SRunner *runner = srunner_create(s21_string_test[i]);

        srunner_set_fork_status(runner, CK_NOFORK);
        srunner_run_all(runner, CK_NORMAL);

        failed += srunner_ntests_failed(runner);
        srunner_free(runner);
    }
    return failed == 0 ? 1 : 0;
}
