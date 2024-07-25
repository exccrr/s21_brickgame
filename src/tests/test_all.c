#include "tests.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  // srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_ntests_failed(runner);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {suite_s21_create_matrix(), suite_s21_equal_matrix(),
                         suite_s21_add_matrix(),    suite_s21_sub_matrix(),
                         suite_s21_remove_matrix(), suite_s21_mul_matrix_num(),
                         suite_s21_det_n(),         suite_s21_mul_matrix_mat(),
                         suite_s21_trans_matrix(),  suite_s21_reverse(),
                         suite_s21_calculation(),   NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();
  return 0;
}
