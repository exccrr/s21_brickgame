#include "tests.h"

// WARNING ALL TEST - SIMPLE PASS

START_TEST(trans_matrix) {
  // матрицы инициализированны и не равны по значениям (порядки одинаковые)
  {
    int row = 3;
    int col = 2;
    matrix_t A = {NULL, 0, 0};
    matrix_t R = {NULL, 0, 0};
    matrix_t CH = {NULL, 0, 0};
    double mas_a[3][2] = {{2, 5}, {6, 3}, {5, -2}};
    double mas_ch[2][3] = {{2, 6, 5}, {5, 3, -2}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &CH);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) A.matrix[i][j] = mas_a[i][j];

    for (int i = 0; i < col; i++)
      for (int j = 0; j < row; j++) CH.matrix[i][j] = mas_ch[i][j];

    ck_assert_int_eq(s21_transpose(&A, &R), OK);
    ck_assert_int_eq(s21_eq_matrix(&R, &CH), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
    s21_remove_matrix(&CH);
  }
  // NULL
  {
    matrix_t *A = NULL;
    matrix_t R = {NULL, 0, 0};

    ck_assert_int_eq(s21_transpose(A, &R), INCORRECT_MATRIX);

    s21_remove_matrix(&R);
  }
  // NULL 2
  {
    int row = 3;
    int col = 2;
    matrix_t A = {NULL, 0, 0};
    matrix_t *R = NULL;
    double mas_a[3][2] = {{2, 5}, {6, 3}, {5, -2}};

    s21_create_matrix(row, col, &A);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) A.matrix[i][j] = mas_a[i][j];
    ck_assert_int_eq(s21_transpose(&A, R), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }

  // and

  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_transpose(NULL, &result), 1);
  }
  {
    matrix_t A = {0};
    ck_assert_int_eq(s21_transpose(&A, NULL), 1);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &eq);
    A.matrix[0][0] = 1;
    eq.matrix[0][0] = 1;
    ck_assert_int_eq(s21_transpose(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 1, &A);
    s21_create_matrix(1, 4, &eq);

    A.matrix[0][0] = 0.003;
    A.matrix[1][0] = 0.012;
    A.matrix[2][0] = -1.75;
    A.matrix[3][0] = 8;

    eq.matrix[0][0] = 0.003;
    eq.matrix[0][1] = 0.012;
    eq.matrix[0][2] = -1.75;
    eq.matrix[0][3] = 8;

    ck_assert_int_eq(s21_transpose(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 2, &A);
    s21_create_matrix(2, 4, &eq);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 6;
    A.matrix[3][0] = 7;
    A.matrix[3][1] = 8;

    eq.matrix[0][0] = 1;
    eq.matrix[0][1] = 3;
    eq.matrix[0][2] = 5;
    eq.matrix[0][3] = 7;
    eq.matrix[1][0] = 2;
    eq.matrix[1][1] = 4;
    eq.matrix[1][2] = 6;
    eq.matrix[1][3] = 8;

    ck_assert_int_eq(s21_transpose(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(3, 2, &A);
    s21_create_matrix(2, 3, &eq);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 4;
    A.matrix[1][0] = 2;
    A.matrix[1][1] = 5;
    A.matrix[2][0] = 3;
    A.matrix[2][1] = 6;

    eq.matrix[0][0] = 1;
    eq.matrix[0][1] = 2;
    eq.matrix[0][2] = 3;
    eq.matrix[1][0] = 4;
    eq.matrix[1][1] = 5;
    eq.matrix[1][2] = 6;

    ck_assert_int_eq(s21_transpose(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  { ck_assert_int_eq(s21_transpose(NULL, NULL), 1); }
}
END_TEST

Suite *suite_s21_trans_matrix() {
  Suite *s = suite_create("trans_matrix");
  TCase *tc = tcase_create("trans_matrix_tc");

  tcase_add_test(tc, trans_matrix);
  suite_add_tcase(s, tc);
  return s;
}
