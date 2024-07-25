#include "tests.h"

START_TEST(equal_matrix) {
  // матрицы инициализированны и не равны по значениям (порядки одинаковые)
  {
    int row = 4;
    int col = 5;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = ((double)i + 10);
        B.matrix[i][j] = (double)i + 15;
      }
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // матрицы инициализированны и равны по значениям (порядки одинаковые)
  {
    int row = 4;
    int col = 5;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = ((double)i + 10);
        B.matrix[i][j] = (double)i + 10;
      }
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // матрицы инициализированны и равны по значениям (порядки одинаковые)
  {
    int row = 4;
    int col = 5;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = ((double)i + 10);
        B.matrix[i][j] = (double)i + 10.00000001;
      }
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // матрицы инициализированны и равны по значениям (порядки одинаковые)
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    double mas_a[3][3] = {{10L, 10L, 10L}, {10L, 10L, 10L}, {10L, 10L, 10L}};
    double mas_b[3][3] = {{10.00000001L, 10.00000001L, 10.00000001L},
                          {10.00000001L, 10.00000001L, 10.00000001L},
                          {10.00000001L, 10.00000001L, 10.00000001L}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // НЕ РАВНЫ
  {
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(10, 10, &A);
    s21_create_matrix(10, 10, &B);

    for (double i = 0, k = 0.0000001; i < A.rows; ++i) {
      for (double j = 0; j < A.columns; ++j, k += 0.0000001) {
        A.matrix[(int)i][(int)j] = k;
        B.matrix[(int)i][(int)j] = k;
      }
    }
    A.matrix[0][0] += 0.0000001;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // матрицы не инициализированны
  {
    matrix_t *A = NULL;
    matrix_t *B = NULL;

    ck_assert_int_eq(s21_eq_matrix(A, B), FAILURE);
  }
  // NAN
  {
    int row = 3, col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};

    double mas_a[3][3] = {{NAN, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][3] = {{NAN, 5, 7}, {6, 3, 4}, {5, -2, -3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);

    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) A.matrix[i][j] = mas_a[i][j];

    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) B.matrix[i][j] = mas_b[i][j];

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // INF
  {
    int row = 3, col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};

    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {INFINITY, -2, -3}};
    double mas_b[3][3] = {{2, 5, 7}, {6, 3, 4}, {INFINITY, -2, -3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);

    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) A.matrix[i][j] = mas_a[i][j];

    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) B.matrix[i][j] = mas_b[i][j];

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
}
END_TEST

Suite *suite_s21_equal_matrix() {
  Suite *s = suite_create("equal_matrix");
  TCase *tc = tcase_create("equal_matrix_tc");

  tcase_add_test(tc, equal_matrix);
  suite_add_tcase(s, tc);
  return s;
}
