#include "tests.h"

START_TEST(remove_matrix) {
  {
    matrix_t A = {NULL, 0, 0};
    s21_create_matrix(1, 1, &A);
    s21_remove_matrix(&A);
    ck_assert_int_eq(A.rows, 0);
    ck_assert_int_eq(A.columns, 0);
  }
}
END_TEST

Suite *suite_s21_remove_matrix() {
  Suite *s = suite_create("remove_matrix");
  TCase *tc = tcase_create("remove_matrix_tc");

  tcase_add_test(tc, remove_matrix);
  suite_add_tcase(s, tc);
  return s;
}
