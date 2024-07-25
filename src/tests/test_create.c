#include "tests.h"

START_TEST(create_matrix) {
  // NULL
  { ck_assert_int_eq(s21_create_matrix(1, 1, NULL), INCORRECT_MATRIX); }
  // неверные размеры 1
  {
    matrix_t A = {NULL, 0, 0};
    ck_assert_int_eq(s21_create_matrix(-1, 1, &A), INCORRECT_MATRIX);
  }
  // неверные размеры 2
  {
    matrix_t A = {NULL, 0, 0};
    ck_assert_int_eq(s21_create_matrix(0, 1, &A), INCORRECT_MATRIX);
  }
  // неверные размеры 3
  {
    matrix_t A = {NULL, 0, 0};
    ck_assert_int_eq(s21_create_matrix(1, 0, &A), INCORRECT_MATRIX);
  }
  // неверные размеры 4
  {
    matrix_t A = {NULL, 0, 0};
    ck_assert_int_eq(s21_create_matrix(2, -1, &A), INCORRECT_MATRIX);
  }
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t check = {NULL, row, col};

    ck_assert_int_eq(s21_create_matrix(row, col, &A), OK);
    ck_assert_int_eq(s21_create_matrix(row, col, &check), OK);
    ck_assert_int_eq(s21_eq_matrix(&A, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
  }
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t A = {0};

    ck_assert_int_eq(s21_create_matrix(row, col, &A), OK);
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite *suite_s21_create_matrix() {
  Suite *s = suite_create("create_matrix");
  TCase *tc = tcase_create("create_matrix_tc");

  tcase_add_test(tc, create_matrix);
  suite_add_tcase(s, tc);
  return s;
}
