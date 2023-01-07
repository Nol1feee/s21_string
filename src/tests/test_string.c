#include "test_string.h"

int main(void) {
    int failed = 0;
    Suite *s21_string_test[] = {
        test_strlen(), 
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
