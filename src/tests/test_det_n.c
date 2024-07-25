#include "tests.h"

START_TEST(test_det_n) {
  // все данные корректны
  {
    double check = -2511.72L;
    double result = 0.0L;

    int row = 4;
    int col = 4;
    matrix_t A = {NULL, row, col};
    double mas_a[4][4] = {{-4.1, -2, 0, 0.2},
                          {0.4, 13, 21, -0.3},
                          {5, -2, 3.3, -9.1},
                          {1, 2, 3, 4}};

    s21_create_matrix(row, col, &A);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = -32L;
    double result = 0.0L;

    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{4, 0, 2}, {1, 2, 3}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = 40L;
    double result = 0.0L;

    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{0, 4, 2}, {1, 2, 3}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = 3.0L;
    double result = 0.0L;

    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{0, 1, 2}, {1, 2, 3}, {3, 4, 2}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = 305L;
    double result = 0.0L;
    int row = 2;
    int col = 2;
    double mas_a[2][2] = {{101, -1}, {2, 3}};
    matrix_t A = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq(result, check);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = -348.4008L;
    double result = 0.0L;
    int row = 2;
    int col = 2;
    double mas_a[2][2] = {{-19.4, -0.24}, {3.33, 18}};
    matrix_t A = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = -9.975L;
    double result = 0.0L;
    int row = 2;
    int col = 2;
    double mas_a[2][2] = {{-0.3, 0.8}, {12, 1.25}};
    matrix_t A = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = 1602L;
    double result = 0.0L;

    int row = 4;
    int col = 4;
    matrix_t A = {NULL, row, col};
    double mas_a[4][4] = {
        {13, 1, 38, 42}, {2, 4, 2, 1}, {4, 1, 2, 3}, {4, 2, 4, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = 689.666L;
    double result = 0.0L;

    int row = 4;
    int col = 4;
    matrix_t A = {NULL, row, col};
    double mas_a[4][4] = {
        {1, 3, 8, 1}, {4, 5, 2.2, 3.1}, {12, 0, 6, 1.1}, {3, 5.3, 18, 0}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }

  // все данные корректны
  {
    double check = 34.122;
    double result = 0.0L;

    int row = 4;
    int col = 4;
    matrix_t A = {NULL, row, col};
    double mas_a[4][4] = {{0.5, 4, 2, 8},
                          {1, 7, 1.1, 2.2},
                          {3.3, 4.4, 5.5, 6.6},
                          {7.7, 8.8, 9.9, 0}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }
  // все данные корректны
  {
    double check = -40L;
    double result = 0.0L;

    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, check, 1e-7);
    s21_remove_matrix(&A);
  }

  //   не квадратная матрица
  {
    double result = 0.0L;
    int row = 2;
    int col = 3;
    double mas_a[2][3] = {{-0.3L, 0.8L, 0.0L}, {12, 1.25L, 0.0L}};
    matrix_t A = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // не квадратная матрица
  {
    double result = 0.0L;
    int row = 3;
    int col = 1;
    double mas_a[3][1] = {{-0.3L}, {0.8L}, {0.0L}};
    matrix_t A = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // NULL 1
  {
    double result = 0.0L;
    matrix_t *A = NULL;
    ck_assert_int_eq(s21_determinant(A, &result), INCORRECT_MATRIX);
  }
  // NULL 2, не выделена папять под матрицу
  {
    double result = 0.0L;
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
  }
  // NULL 3
  {
    double *result = NULL;
    matrix_t A = {NULL, 3, 3};
    s21_create_matrix(3, 3, &A);
    ck_assert_int_eq(s21_determinant(&A, result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // некорректный размер срок
  {
    int row = 3, col = 3;
    double *result = NULL;
    matrix_t A = {NULL, 3, 3};
    double mas_a[3][3] = {{4, 0, 2}, {1, 2, 3}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    A.rows = 0;
    ck_assert_int_eq(s21_determinant(&A, result), INCORRECT_MATRIX);
    A.rows = 3;
    s21_remove_matrix(&A);
  }
  // некорректные размер столбцов
  {
    int row = 3, col = 3;
    double *result = NULL;
    matrix_t A = {NULL, 3, 3};
    double mas_a[3][3] = {{4, 0, 2}, {1, 2, 3}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    A.columns = 0;
    ck_assert_int_eq(s21_determinant(&A, result), INCORRECT_MATRIX);
    A.columns = 3;

    s21_remove_matrix(&A);
  }

  // and

  {
    double result = 0;
    ck_assert_int_eq(s21_determinant(NULL, &result), 1);
  }
  {
    matrix_t A = {0};
    s21_create_matrix(5, 5, &A);
    ck_assert_int_eq(s21_determinant(&A, NULL), 1);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(1, 1, &A);
    A.matrix[0][0] = 1;
    ck_assert_int_eq(s21_determinant(&A, &result), 0);
    ck_assert_int_eq(result, 1);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;
    ck_assert_int_eq(s21_determinant(&A, &result), 0);
    ck_assert_double_eq_tol(result, -1, 0.1);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(3, 2, &A);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;

    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;

    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;

    ck_assert_int_eq(s21_determinant(&A, &result), 2);
    s21_remove_matrix(&A);
  }

  // others
  {
    int size = 5;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) A.matrix[i][j] = i + j;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);

    ck_assert_double_eq_tol(res, 0, 1e-06);

    s21_remove_matrix(&A);
  }

  {
    int size = 5;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    A.matrix[0][1] = 6;
    A.matrix[0][2] = -2;
    A.matrix[0][3] = -1;
    A.matrix[0][4] = 5;
    A.matrix[1][3] = -9;
    A.matrix[1][4] = -7;
    A.matrix[2][1] = 15;
    A.matrix[2][2] = 35;
    A.matrix[3][1] = -1;
    A.matrix[3][2] = -11;
    A.matrix[3][3] = -2;
    A.matrix[3][4] = 1;
    A.matrix[4][0] = -2;
    A.matrix[4][1] = -2;
    A.matrix[4][2] = 3;
    A.matrix[4][4] = -2;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);
    ck_assert_double_eq_tol(res, 2480, 1e-7);

    s21_remove_matrix(&A);
  }

  {
    int size = 3;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 2;
    A.matrix[0][1] = 3;
    A.matrix[0][2] = 1;
    A.matrix[1][0] = 7;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 1;
    A.matrix[2][0] = 9;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = 1;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);
    ck_assert_double_eq_tol(res, -32, 1e-7);

    s21_remove_matrix(&A);
  }

  {
    int size = 2;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    A.matrix[0][0] = -5;
    A.matrix[0][1] = -4;
    A.matrix[1][0] = -2;
    A.matrix[1][1] = -3;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);
    ck_assert_double_eq_tol(res, 7, 1e-7);

    s21_remove_matrix(&A);
  }

  {
    int size = 1;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    A.matrix[0][0] = -5;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);
    ck_assert_double_eq_tol(res, -5, 1e-7);

    s21_remove_matrix(&A);
  }

  {
    int size = 2;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);
    A.columns = 0;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, INCORRECT_MATRIX);
    A.columns = 2;
    s21_remove_matrix(&A);
  }

  {
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(2, 3, &A);

    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++) A.matrix[i][j] = i + j;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OPERATION_ERROR);

    s21_remove_matrix(&A);
  }
  {
    int size = 6;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 0;
    A.matrix[0][1] = 0;
    A.matrix[0][2] = 2;
    A.matrix[0][3] = 4;
    A.matrix[0][4] = 5;
    A.matrix[0][5] = 1;

    A.matrix[1][0] = 3;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 1;
    A.matrix[1][3] = 3;
    A.matrix[1][4] = 0;
    A.matrix[1][5] = 1;

    A.matrix[2][0] = 1;
    A.matrix[2][1] = 4;
    A.matrix[2][2] = 2;
    A.matrix[2][3] = 1;
    A.matrix[2][4] = 5;
    A.matrix[2][5] = 6;

    A.matrix[3][0] = 3;
    A.matrix[3][1] = 0;
    A.matrix[3][2] = 1;
    A.matrix[3][3] = 4;
    A.matrix[3][4] = 2;
    A.matrix[3][5] = 1;

    A.matrix[4][0] = 4;
    A.matrix[4][1] = 2;
    A.matrix[4][2] = 0;
    A.matrix[4][3] = 1;
    A.matrix[4][4] = 9;
    A.matrix[4][5] = 2;

    A.matrix[5][0] = 3;
    A.matrix[5][1] = 1;
    A.matrix[5][2] = 9;
    A.matrix[5][3] = 5;
    A.matrix[5][4] = 7;
    A.matrix[5][5] = 0;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);
    ck_assert_double_eq_tol(res, 26588, 1e-06);

    s21_remove_matrix(&A);
  }
  {
    int size = 5;
    matrix_t A;
    double res = 0;

    int ret_code_1 = s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 7.389428;
    A.matrix[0][1] = 2.958676;
    A.matrix[0][2] = 9.588797;
    A.matrix[0][3] = -3.047775;
    A.matrix[0][4] = 6.871365;

    A.matrix[1][0] = 7.647412;
    A.matrix[1][1] = 6.283314;
    A.matrix[1][2] = 1.088828;
    A.matrix[1][3] = -1.504749;
    A.matrix[1][4] = 4.928701;

    A.matrix[2][0] = 3.512002;
    A.matrix[2][1] = 3.837188;
    A.matrix[2][2] = -2.289623;
    A.matrix[2][3] = -6.025250;
    A.matrix[2][4] = 1.820978;

    A.matrix[3][0] = -8.616517;
    A.matrix[3][1] = -3.838246;
    A.matrix[3][2] = 0.406613;
    A.matrix[3][3] = -2.473955;
    A.matrix[3][4] = 9.841163;

    A.matrix[4][0] = -3.091114;
    A.matrix[4][1] = 3.274901;
    A.matrix[4][2] = 4.103472;
    A.matrix[4][3] = -2.941481;
    A.matrix[4][4] = 8.295972;

    int ret_code_2 = s21_determinant(&A, &res);
    ck_assert_int_eq(ret_code_1, OK);
    ck_assert_int_eq(ret_code_2, OK);
    ck_assert_double_eq_tol(res, -29092.655985, 1e-06);

    s21_remove_matrix(&A);
  }
  {
    int rows1 = 2, cols1 = 2;
    matrix_t A;
    double result = 0;

    int code_1 = s21_create_matrix(rows1, cols1, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = -1.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 0.0;

    int status = s21_determinant(&A, &result);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);

    ck_assert_double_eq_tol(result, 0.0, 1e-06);
    s21_remove_matrix(&A);
  }
  {
    int rows1 = 1, cols1 = 1;
    matrix_t A;
    int code_1 = s21_create_matrix(rows1, cols1, &A);
    double result = 0;
    A.matrix[0][0] = -55.0;
    int status = s21_determinant(&A, &result);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result, -55.000000000014, 1e-06);
    s21_remove_matrix(&A);
  }
  {
    int rows1 = 2, cols1 = 2;
    matrix_t A;
    int code_1 = s21_create_matrix(rows1, cols1, &A);
    double result = 0;

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = -1.0;
    A.matrix[1][0] = -1.0;
    A.matrix[1][1] = 0.0;

    int status = s21_determinant(&A, &result);
    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result, -1.0, 7);
    s21_remove_matrix(&A);
  }
  {
    int rows1 = 5, cols1 = 5;
    matrix_t A;
    int code_1 = s21_create_matrix(rows1, cols1, &A);
    double result = 0;

    A.matrix[0][0] = 0.0;
    A.matrix[0][1] = -1.0;
    A.matrix[0][2] = -1.0;
    A.matrix[0][3] = 0.0;
    A.matrix[0][4] = 1.0;

    A.matrix[1][0] = -1.0;
    A.matrix[1][1] = 0.0;
    A.matrix[1][2] = -1.0;
    A.matrix[1][3] = -1.0;
    A.matrix[1][4] = -1.0;

    A.matrix[2][0] = 1.0;
    A.matrix[2][1] = 0.0;
    A.matrix[2][2] = -1.0;
    A.matrix[2][3] = 1.0;
    A.matrix[2][4] = -1.0;

    A.matrix[3][0] = 1.0;
    A.matrix[3][1] = 0.0;
    A.matrix[3][2] = 1.0;
    A.matrix[3][3] = 0.0;
    A.matrix[3][4] = 1.0;

    A.matrix[4][0] = -1.0;
    A.matrix[4][1] = 0.0;
    A.matrix[4][2] = 0.0;
    A.matrix[4][3] = 1.0;
    A.matrix[4][4] = -1.0;

    int status = s21_determinant(&A, &result);
    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result, 2.0, 1e-06);
    s21_remove_matrix(&A);
  }
  {
    int rows1 = 1, cols1 = 1;
    matrix_t A;
    int code_1 = s21_create_matrix(rows1, cols1, &A);
    double result = 0;
    A.matrix[0][0] = 22.0;
    int status = s21_determinant(&A, &result);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result, 22.000000000000004, 1e-06);
    s21_remove_matrix(&A);
  }
  {
    int rows1 = 1, cols1 = 1;
    matrix_t A;
    int code_1 = s21_create_matrix(rows1, cols1, &A);
    double result = 0;
    A.matrix[0][0] = 1.0;
    int status = s21_determinant(&A, &result);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result, 1.0, 1e-06);
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite *suite_s21_det_n() {
  Suite *s = suite_create("test_det_n");
  TCase *tc = tcase_create("test_det_n_tc");

  tcase_add_test(tc, test_det_n);
  suite_add_tcase(s, tc);
  return s;
}
