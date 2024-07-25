#include "tests.h"

// WARNING ALL TEST - SIMPLE PASS

START_TEST(mul_matrix_mat) {
  // две корректные матрицы и результат
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, 4}};
    double mas_check[3][3] = {{9, 11, 17}, {12, 13, 22}, {15, 15, 27}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};
    matrix_t CH = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    s21_create_matrix(row, row, &CH);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        CH.matrix[i][j] = mas_check[i][j];
      }
    }

    s21_mult_matrix(&A, &B, &R);

    ck_assert_int_eq(s21_eq_matrix(&R, &CH), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&CH);
  }
  // две корректные матрицы и результат
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{12, 14}, {12, 15}, {13, 16}};
    double mas_b[2][3] = {{11, -11, 11}, {12, 13, 14}};
    double mas_check[3][3] = {{300, 50, 328}, {312, 63, 342}, {335, 65, 367}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};
    matrix_t CH = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    s21_create_matrix(row, row, &CH);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        CH.matrix[i][j] = mas_check[i][j];
      }
    }

    s21_mult_matrix(&A, &B, &R);

    ck_assert_int_eq(s21_eq_matrix(&R, &CH), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&CH);
  }
  // две корректные матрицы и результат
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{2, 2}, {2, 2}, {2, 2}};
    double mas_b[2][3] = {{1, -1, 1}, {1, -1, 1}};
    double mas_check[3][3] = {{4, -4, 4}, {4, -4, 4}, {4, -4, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};
    matrix_t CH = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    s21_create_matrix(row, row, &CH);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        CH.matrix[i][j] = mas_check[i][j];
      }
    }

    s21_mult_matrix(&A, &B, &R);

    ck_assert_int_eq(s21_eq_matrix(&R, &CH), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&CH);
  }
  // Не соответсвуют колонки и столбцы
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{2, 2}, {2, 2}, {2, 2}};
    double mas_b[3][3] = {{1, -1, 1}, {1, -1, 1}, {-1, 1, 1}};
    matrix_t R = {NULL, row, row};
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, row, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }
  // Не соответсвуют колонки и столбцы 2
  {
    int row = 3;
    int col = 1;
    double mas_a[3][2] = {{2, 2}, {2, 2}, {2, 2}};
    double mas_b[3][1] = {{1}, {1}, {-1}};
    matrix_t R = {NULL, row, row};
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, row};

    s21_create_matrix(row, 2, &A);
    s21_create_matrix(row, col, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }
  // NULL
  {
    int row = 3;
    int col = 2;
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, 4}};

    matrix_t* A = NULL;
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};

    s21_create_matrix(col, row, &B);
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }
    ck_assert_int_eq(s21_mult_matrix(A, &B, &R), INCORRECT_MATRIX);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }
  // NULL 2
  {
    int row = 3;
    int col = 2;
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, 4}};

    matrix_t* B = NULL;
    matrix_t A = {NULL, col, row};
    matrix_t R = {NULL, row, row};

    s21_create_matrix(col, row, &A);
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        A.matrix[i][j] = mas_b[i][j];
      }
    }
    ck_assert_int_eq(s21_mult_matrix(&A, B, &R), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
  }
  // NULL 3
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, 4}};

    matrix_t A = {NULL, col, row};
    matrix_t B = {NULL, col, row};
    matrix_t* R = NULL;

    s21_create_matrix(col, row, &A);
    s21_create_matrix(row, row, &B);
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }
    ck_assert_int_eq(s21_mult_matrix(&A, &B, R), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // NAN
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{NAN, 4}, {2, 5}, {3, 6}};
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }
  // NAN 2
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{5, 4}, {2, 5}, {3, 6}};
    double mas_b[2][3] = {{1, -1, 1}, {NAN, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }
  // INF
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{INFINITY, 4}, {2, 5}, {3, 6}};
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, 4}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }
  // INF 2
  {
    int row = 3;
    int col = 2;
    double mas_a[3][2] = {{2, 4}, {2, 5}, {3, 6}};
    double mas_b[2][3] = {{1, -1, 1}, {2, 3, -INFINITY}};

    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, col, row};
    matrix_t R = {NULL, row, row};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(col, row, &B);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &R), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
  }

  // andry

  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(5, 5, &A);
    for (int i = 0; i < A.rows; ++i) {
      for (int j = 0, k = 0; j < A.columns; ++j, ++k) {
        A.matrix[i][j] = k;
      }
    }
    ck_assert_int_eq(s21_mult_matrix(&A, NULL, &result), 1);
    s21_remove_matrix(&A);
  }
  {
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(5, 5, &B);
    for (int i = 0; i < B.rows; ++i) {
      for (int j = 0, k = 0; j < B.columns; ++j, ++k) {
        B.matrix[i][j] = k;
      }
    }
    ck_assert_int_eq(s21_mult_matrix(NULL, &B, &result), 1);
    s21_remove_matrix(&B);
  }
  { ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL), 1); }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t eq = {0};
    matrix_t result = {0};
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);
    s21_create_matrix(1, 1, &eq);
    A.matrix[0][0] = 0.002;
    B.matrix[0][0] = 0.002;
    eq.matrix[0][0] = 0.000004;
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&eq);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &B);
    s21_create_matrix(4, 4, &eq);
    for (int i = 0, k = 1, l = 3; i < A.rows; ++i) {
      for (int j = 0; j < A.columns; ++j, ++k, l += 3) {
        A.matrix[i][j] = k;
        B.matrix[i][j] = l;
      }
    }
    eq.matrix[0][0] = 270;
    eq.matrix[0][1] = 300;
    eq.matrix[0][2] = 330;
    eq.matrix[0][3] = 360;
    eq.matrix[1][0] = 606;
    eq.matrix[1][1] = 684;
    eq.matrix[1][2] = 762;
    eq.matrix[1][3] = 840;
    eq.matrix[2][0] = 942;
    eq.matrix[2][1] = 1068;
    eq.matrix[2][2] = 1194;
    eq.matrix[2][3] = 1320;
    eq.matrix[3][0] = 1278;
    eq.matrix[3][1] = 1452;
    eq.matrix[3][2] = 1626;
    eq.matrix[3][3] = 1800;
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &B);
    s21_create_matrix(4, 4, &eq);
    for (double i = 0, k = 0.001, l = 0.003; i < A.rows; ++i) {
      for (double j = 0; j < A.columns; ++j, k += 0.001, l += 0.003) {
        A.matrix[(int)i][(int)j] = k;
        B.matrix[(int)i][(int)j] = l;
      }
    }
    eq.matrix[0][0] = 0.000270;
    eq.matrix[0][1] = 0.000300;
    eq.matrix[0][2] = 0.000330;
    eq.matrix[0][3] = 0.000360;
    eq.matrix[1][0] = 0.000606;
    eq.matrix[1][1] = 0.000684;
    eq.matrix[1][2] = 0.000762;
    eq.matrix[1][3] = 0.000840;
    eq.matrix[2][0] = 0.000942;
    eq.matrix[2][1] = 0.001068;
    eq.matrix[2][2] = 0.001194;
    eq.matrix[2][3] = 0.001320;
    eq.matrix[3][0] = 0.001278;
    eq.matrix[3][1] = 0.001452;
    eq.matrix[3][2] = 0.001626;
    eq.matrix[3][3] = 0.001800;
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(4, 1, &A);
    s21_create_matrix(1, 4, &B);
    s21_create_matrix(4, 4, &eq);

    A.matrix[0][0] = 0.003;
    A.matrix[1][0] = 0.012;
    A.matrix[2][0] = -1.75;
    A.matrix[3][0] = 8;

    B.matrix[0][0] = 13;
    B.matrix[0][1] = 0;
    B.matrix[0][2] = 9.34;
    B.matrix[0][3] = -41;

    eq.matrix[0][0] = 0.039;
    eq.matrix[0][1] = 0;
    eq.matrix[0][2] = 0.02802;
    eq.matrix[0][3] = -0.123;
    eq.matrix[1][0] = 0.156;
    eq.matrix[1][1] = 0;
    eq.matrix[1][2] = 0.11208;
    eq.matrix[1][3] = -0.492;
    eq.matrix[2][0] = -22.75;
    eq.matrix[2][1] = 0;
    eq.matrix[2][2] = -16.345;
    eq.matrix[2][3] = 71.75;
    eq.matrix[3][0] = 104;
    eq.matrix[3][1] = 0;
    eq.matrix[3][2] = 74.72;
    eq.matrix[3][3] = -328;

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(2, 1, &A);
    s21_create_matrix(1, 2, &B);

    A.matrix[0][0] = 1;
    A.matrix[1][0] = 2;

    B.matrix[0][0] = 2;
    B.matrix[0][1] = NAN;

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(2, 2, &A);
    s21_create_matrix(1, 2, &B);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;

    B.matrix[0][0] = 2;
    B.matrix[0][1] = 1;

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
}

END_TEST

Suite* suite_s21_mul_matrix_mat() {
  Suite* s = suite_create("mul_matrix_mat");
  TCase* tc = tcase_create("mul_matrix_mat_tc");

  tcase_add_test(tc, mul_matrix_mat);
  suite_add_tcase(s, tc);
  return s;
}
