#include <string.h>
#include <check.h> 

#include "s21_functions.h"

START_TEST(s21_strlen_test) {
char temp[] = "privet, eto nash pervii test";
ck_assert_ptr_eq(s21_strlen(temp), strlen(temp));
}END_TEST

Suite *test_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("string test");
    tc_core = tcase_create("Core");

    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, s21_strlen_test);

    return s;
}

int main(void){
    Suite *s;
    SRunner *runner;
    int failed = 0;

    s = test_suite();
    runner = test_suite();

    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return failed == 0 ? 1 : 0;
}