#include "tests.h"

// WARNING ALL TEST - SIMPLE PASS

START_TEST(mul_matrix_num) {
  // все данные корректны
  {
    double number = 8.1;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{11, -11, 11}, {12, 13, 14}};
    double mas_check[2][3] = {{89.1, -89.1, 89.1}, {97.2, 105.3, 113.4}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};
    matrix_t CH = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    s21_create_matrix(row, col, &CH);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        CH.matrix[i][j] = mas_check[i][j];
      }
    }
    s21_mult_number(&A, number, &R);
    ck_assert_int_eq(s21_eq_matrix(&R, &CH), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
    s21_remove_matrix(&CH);
  }
  // все данные корректны
  {
    double number = 0.5;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{101, -1, 11}, {2, 3, 4}};
    double mas_check[2][3] = {{50.5, -0.5, 5.5}, {1, 1.5, 2}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};
    matrix_t CH = {NULL, row, col};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &CH);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        CH.matrix[i][j] = mas_check[i][j];
      }
    }
    s21_mult_number(&A, number, &R);
    ck_assert_int_eq(s21_eq_matrix(&R, &CH), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
    s21_remove_matrix(&CH);
  }
  // NULL
  {
    double number = 8.1;
    int row = 2;
    int col = 3;

    matrix_t *A = NULL;
    matrix_t R = {NULL, row, col};

    ck_assert_int_eq(s21_mult_number(A, number, &R), INCORRECT_MATRIX);
    s21_remove_matrix(&R);
  }
  // NULL 2
  {
    double number = 0.5;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{101, -1, 11}, {2, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t *R = NULL;
    s21_create_matrix(row, col, &A);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_mult_number(&A, number, R), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // INF 1
  {
    double number = INFINITY;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{101, -1, 11}, {2, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_mult_number(&A, number, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }
  // INF 2
  {
    double number = 0.5;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{INFINITY, -1, 11}, {2, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_number(&A, number, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }
  // INF 3
  {
    double number = 0.5;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{2, -1, 11}, {2, 3, -INFINITY}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_number(&A, number, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }
  // NAN
  {
    double number = 0.5;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{2, -1, 11}, {2, 3, NAN}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_number(&A, number, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }
  // NAN 2
  {
    double number = 0.5;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{2, -1, NAN}, {2, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_number(&A, number, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }
  // NAN 3
  {
    double number = NAN;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{2, -1, 11}, {2, 3, 10}};

    matrix_t A = {NULL, row, col};
    matrix_t R = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_number(&A, number, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }

  // ANDRY

  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_mult_number(NULL, NAN, &result), 1);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(-1, -1, &A);
    ck_assert_int_eq(s21_mult_number(&A, NAN, &result), 1);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &eq);
    for (int i = 0, k = 1; i < A.rows; ++i) {
      for (int j = 0; j < A.columns; ++j, ++k) {
        A.matrix[i][j] = k;
      }
    }
    eq.matrix[0][0] = 2;
    eq.matrix[0][1] = 4;
    eq.matrix[0][2] = 6;
    eq.matrix[0][3] = 8;
    eq.matrix[1][0] = 10;
    eq.matrix[1][1] = 12;
    eq.matrix[1][2] = 14;
    eq.matrix[1][3] = 16;
    eq.matrix[2][0] = 18;
    eq.matrix[2][1] = 20;
    eq.matrix[2][2] = 22;
    eq.matrix[2][3] = 24;
    eq.matrix[3][0] = 26;
    eq.matrix[3][1] = 28;
    eq.matrix[3][2] = 30;
    eq.matrix[3][3] = 32;
    ck_assert_int_eq(s21_mult_number(&A, 2, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &eq);
    for (double i = 0, k = 0.000001; i < A.rows; ++i) {
      for (double j = 0; j < A.columns; ++j, k += 0.000001) {
        A.matrix[(int)i][(int)j] = k;
      }
    }
    eq.matrix[0][0] = 0.000002;
    eq.matrix[0][1] = 0.000004;
    eq.matrix[0][2] = 0.000006;
    eq.matrix[0][3] = 0.000008;
    eq.matrix[1][0] = 0.000010;
    eq.matrix[1][1] = 0.000012;
    eq.matrix[1][2] = 0.000014;
    eq.matrix[1][3] = 0.000016;
    eq.matrix[2][0] = 0.000018;
    eq.matrix[2][1] = 0.000020;
    eq.matrix[2][2] = 0.000022;
    eq.matrix[2][3] = 0.000024;
    eq.matrix[3][0] = 0.000026;
    eq.matrix[3][1] = 0.000028;
    eq.matrix[3][2] = 0.000030;
    eq.matrix[3][3] = 0.000032;
    ck_assert_int_eq(s21_mult_number(&A, 2, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &eq);
    for (double i = 0, k = 0.001; i < A.rows; ++i) {
      for (double j = 0; j < A.columns; ++j, k += 0.001) {
        A.matrix[(int)i][(int)j] = k;
      }
    }
    eq.matrix[0][0] = 0.000002;
    eq.matrix[0][1] = 0.000004;
    eq.matrix[0][2] = 0.000006;
    eq.matrix[0][3] = 0.000008;
    eq.matrix[1][0] = 0.000010;
    eq.matrix[1][1] = 0.000012;
    eq.matrix[1][2] = 0.000014;
    eq.matrix[1][3] = 0.000016;
    eq.matrix[2][0] = 0.000018;
    eq.matrix[2][1] = 0.000020;
    eq.matrix[2][2] = 0.000022;
    eq.matrix[2][3] = 0.000024;
    eq.matrix[3][0] = 0.000026;
    eq.matrix[3][1] = 0.000028;
    eq.matrix[3][2] = 0.000030;
    eq.matrix[3][3] = 0.000032;
    ck_assert_int_eq(s21_mult_number(&A, 0.002, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(4, 4, &A);
    for (double i = 0, k = 0.000001; i < A.rows; ++i) {
      for (double j = 0; j < A.columns; ++j, k += 0.000001) {
        A.matrix[(int)i][(int)j] = k;
      }
    }
    A.matrix[2][3] = NAN;
    ck_assert_int_eq(s21_mult_number(&A, 2, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &eq);
    A.matrix[0][0] = 10;
    eq.matrix[0][0] = 20;
    ck_assert_int_eq(s21_mult_number(&A, 2, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(5, 5, &A);
    ck_assert_int_eq(s21_mult_number(&A, NAN, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
}
END_TEST

Suite *suite_s21_mul_matrix_num() {
  Suite *s = suite_create("mul_matrix_num");
  TCase *tc = tcase_create("mul_matrix_num_tc");

  tcase_add_test(tc, mul_matrix_num);
  suite_add_tcase(s, tc);
  return s;
}
