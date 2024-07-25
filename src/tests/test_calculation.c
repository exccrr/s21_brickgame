#include "tests.h"

START_TEST(test_calculation) {
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
    double mas_ch[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &check);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{0, 4, 2}, {1, 2, 3}, {5, 2, 1}};
    double mas_ch[3][3] = {{-4, 14, -8}, {0, -10, 20}, {8, 2, -4}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &check);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{8, 15, 3}, {0, -4, 2}, {15, 20, 0}};
    double mas_ch[3][3] = {{-40, 30, 60}, {60, -45, 65}, {42, -16, -32}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &check);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{8.2, 1.5, 3.0}, {0.5, -4.2, 2.1}, {15.2, 20.3, 0}};
    double mas_ch[3][3] = {{-42.63, 31.92, 73.99},
                           {60.9, -45.6, -143.66},
                           {15.75, -15.72, -35.19}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &check);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // NULL
  {
    int row = 3;
    int col = 3;
    matrix_t* result = NULL;
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{8.2, 1.5, 3.0}, {0.5, -4.2, 2.1}, {15.2, 20.3, 0}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // NULL 2
  {
    int row = 3;
    int col = 3;
    matrix_t* A = NULL;
    matrix_t result = {NULL, row, col};

    ck_assert_int_eq(s21_calc_complements(A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&result);
  }
  // NULL 3
  {
    matrix_t* A = NULL;
    matrix_t* result = NULL;
    ck_assert_int_eq(s21_calc_complements(A, result), INCORRECT_MATRIX);
  }
  // NULL 4 ( А создается заполненной всеми 0 => детерминант 0 => ошибка)
  {
    int row = 3;
    int col = 3;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};

    s21_create_matrix(row, col, &A);

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // Не квадратная матрица
  {
    int row = 3;
    int col = 4;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][4] = {{1, 2, 3, 0}, {0, 4, 2, 0}, {5, 2, 1, 0}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // Не квадратная матрица 2
  {
    int row = 1;
    int col = 4;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][4] = {{1, 2, 3, 0}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // Отрицательное значение строки
  {
    int row = 1;
    int col = 1;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[1][1] = {{1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    A.rows = -1;
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
    A.rows = 1;
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // Отрицательное значение колонки
  {
    int row = 1;
    int col = 1;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[1][1] = {{1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    A.columns = -1;
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
    A.columns = 1;
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // есть NAN
  {
    int row = 3;
    int col = 3;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{1, NAN, 3}, {0, 4, 2}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // есть INFINITY
  {
    int row = 3;
    int col = 3;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{INFINITY, 2, 3}, {0, 4, 2}, {5, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  // есть INFINITY 2
  {
    int row = 3;
    int col = 3;
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{1, 2, 3}, {0, 4, 2}, {-INFINITY, 2, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }

  // and

  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_calc_complements(NULL, &result), 1);
  }
  {
    matrix_t A = {0};
    ck_assert_int_eq(s21_calc_complements(&A, NULL), 1);
  }
  { ck_assert_int_eq(s21_calc_complements(NULL, NULL), 1); }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(3, 2, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &result), 2);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &eq);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;

    eq.matrix[0][0] = 0;
    eq.matrix[0][1] = 10;
    eq.matrix[0][2] = -20;
    eq.matrix[1][0] = 4;
    eq.matrix[1][1] = -14;
    eq.matrix[1][2] = 8;
    eq.matrix[2][0] = -8;
    eq.matrix[2][1] = -2;
    eq.matrix[2][2] = 4;

    ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &eq);

    A.matrix[0][0] = 0.01;
    A.matrix[0][1] = 3;
    A.matrix[0][2] = 0.24;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 8;
    A.matrix[1][2] = -5;
    A.matrix[2][0] = 41;
    A.matrix[2][1] = 0.36;
    A.matrix[2][2] = 1;

    eq.matrix[0][0] = 9.8;
    eq.matrix[0][1] = -206;
    eq.matrix[0][2] = -327.64;
    eq.matrix[1][0] = -2.9136;
    eq.matrix[1][1] = -9.83;
    eq.matrix[1][2] = 122.9964;
    eq.matrix[2][0] = -16.92;
    eq.matrix[2][1] = 0.29;
    eq.matrix[2][2] = -2.92;

    ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }

  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(2, 2, &A);
    s21_create_matrix(2, 2, &eq);

    A.matrix[0][0] = 0.01;
    A.matrix[0][1] = 3;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 8;

    eq.matrix[0][0] = 8;
    eq.matrix[0][1] = -1;
    eq.matrix[1][0] = -3;
    eq.matrix[1][1] = 0.01;

    ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }

  {
    matrix_t control;
    matrix_t A;
    matrix_t result;

    int code_1 = s21_create_matrix(3, 3, &A);
    int code_2 = s21_create_matrix(3, 3, &control);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;

    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;

    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;

    control.matrix[0][0] = 0;
    control.matrix[0][1] = 10;
    control.matrix[0][2] = -20;

    control.matrix[1][0] = 4;
    control.matrix[1][1] = -14;
    control.matrix[1][2] = 8;

    control.matrix[2][0] = -8;
    control.matrix[2][1] = -2;
    control.matrix[2][2] = 4;

    int code_res = s21_calc_complements(&A, &result);

    ck_assert_int_eq(code_res, OK);
    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(code_2, OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &control), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&control);
  }

  {
    int rows1 = 2, cols1 = 2;
    matrix_t A, result;
    int code_1 = s21_create_matrix(rows1, cols1, &A);

    A.matrix[0][0] = 57.0;
    A.matrix[0][1] = -55.0;
    A.matrix[1][0] = 2.0;
    A.matrix[1][1] = -79.0;

    int status = s21_calc_complements(&A, &result);

    ck_assert_int_eq(status, OK);
    ck_assert_int_eq(code_1, OK);

    ck_assert_double_eq_tol(result.matrix[0][0], -79.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][1], -2.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][0], 55.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][1], 57.0, 1e-06);

    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }

  {
    matrix_t A, check, result;
    int code_1 = s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &check);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;

    check.matrix[0][0] = 0;
    check.matrix[0][1] = 10;
    check.matrix[0][2] = -20;
    check.matrix[1][0] = 4;
    check.matrix[1][1] = -14;
    check.matrix[1][2] = 8;
    check.matrix[2][0] = -8;
    check.matrix[2][1] = -2;
    check.matrix[2][2] = 4;

    int ret_val = s21_calc_complements(&A, &result);
    int eq = s21_eq_matrix(&result, &check);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(ret_val, OK);
    ck_assert_int_eq(eq, SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A, check, result;
    int code_1 = s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &check);

    A.matrix[0][0] = 23464;

    check.matrix[0][0] = 1;

    int ret_val = s21_calc_complements(&A, &result);
    int eq = s21_eq_matrix(&result, &check);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(ret_val, OK);
    ck_assert_int_eq(eq, SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A, check, result;
    int code_1 = s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &check);

    A.matrix[0][0] = 3;
    A.matrix[0][1] = 15;
    A.matrix[0][2] = 3;
    A.matrix[0][3] = 9;
    A.matrix[1][0] = 8;
    A.matrix[1][1] = 6;
    A.matrix[1][2] = 4;
    A.matrix[1][3] = 2;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 3;
    A.matrix[2][2] = 9;
    A.matrix[2][3] = 9;
    A.matrix[3][0] = -1;
    A.matrix[3][1] = 3;
    A.matrix[3][2] = 3;
    A.matrix[3][3] = 2;

    check.matrix[0][0] = -6;
    check.matrix[0][1] = 92;
    check.matrix[0][2] = -222;
    check.matrix[0][3] = 192;
    check.matrix[1][0] = 234;
    check.matrix[1][1] = 48;
    check.matrix[1][2] = 174;
    check.matrix[1][3] = -216;
    check.matrix[2][0] = 66;
    check.matrix[2][1] = -204;
    check.matrix[2][2] = 18;
    check.matrix[2][3] = 312;
    check.matrix[3][0] = -504;
    check.matrix[3][1] = 456;
    check.matrix[3][2] = 744;
    check.matrix[3][3] = -840;

    int ret_val = s21_calc_complements(&A, &result);
    int eq = s21_eq_matrix(&result, &check);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(ret_val, OK);
    ck_assert_int_eq(eq, SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  {
    int rows1 = 4, cols1 = 4;
    matrix_t A, result;
    int code_1 = s21_create_matrix(rows1, cols1, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 0.0;
    A.matrix[0][2] = 0.0;
    A.matrix[0][3] = -1.0;

    A.matrix[1][0] = -1.0;
    A.matrix[1][1] = 1.0;
    A.matrix[1][2] = -1.0;
    A.matrix[1][3] = 0.0;

    A.matrix[2][0] = 1.0;
    A.matrix[2][1] = -1.0;
    A.matrix[2][2] = 1.0;
    A.matrix[2][3] = 1.0;

    A.matrix[3][0] = -1.0;
    A.matrix[3][1] = 1.0;
    A.matrix[3][2] = -1.0;
    A.matrix[3][3] = -1.0;

    int status = s21_calc_complements(&A, &result);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][1], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][2], 0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][3], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][0], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][1], 0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][2], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][3], 0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][0], 0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][1], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][2], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][3], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][0], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][1], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][2], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][3], 0.0, 1e-06);

    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  {
    int rows1 = 4, cols1 = 4;
    matrix_t A, result;
    int code_1 = s21_create_matrix(rows1, cols1, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 0.0;
    A.matrix[0][2] = -1.0;
    A.matrix[0][3] = 1.0;

    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 1.0;
    A.matrix[1][2] = 0.0;
    A.matrix[1][3] = 1.0;

    A.matrix[2][0] = 1.0;
    A.matrix[2][1] = 0.0;
    A.matrix[2][2] = 0.0;
    A.matrix[2][3] = 0.0;

    A.matrix[3][0] = 0.0;
    A.matrix[3][1] = 1.0;
    A.matrix[3][2] = -1.0;
    A.matrix[3][3] = -1.0;

    int status = s21_calc_complements(&A, &result);

    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][1], 1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][2], 2.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[0][3], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][0], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][1], -2.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][2], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[1][3], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][0], -3.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][1], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][2], -2.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[2][3], 1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][0], -0.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][1], -1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][2], 1.0, 1e-06);
    ck_assert_double_eq_tol(result.matrix[3][3], 1.0, 1e-06);

    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A = {0}, result;
    int status = s21_calc_complements(&A, &result);
    ck_assert_int_eq(status, INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A, result;
    int code_1 = s21_create_matrix(2, 3, &A);
    int status = s21_calc_complements(&A, &result);
    ck_assert_int_eq(code_1, OK);
    ck_assert_int_eq(status, OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  {
    double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
    double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
    matrix_t matrix, res_org, res_my;
    s21_create_matrix(3, 3, &matrix);
    s21_create_matrix(3, 3, &res_org);
    for (int i = 0; i < matrix.rows; i++) {
      for (int j = 0; j < matrix.columns; j++) {
        matrix.matrix[i][j] = m[i][j];
      }
    }
    for (int i = 0; i < matrix.rows; i++) {
      for (int j = 0; j < matrix.columns; j++) {
        res_org.matrix[i][j] = r[i][j];
      }
    }
    int ret = s21_calc_complements(&matrix, &res_my);
    ck_assert_int_eq(ret, 0);
    ret = s21_eq_matrix(&res_org, &res_my);
    ck_assert_int_eq(ret, 1);
    s21_remove_matrix(&matrix);
    s21_remove_matrix(&res_my);
    s21_remove_matrix(&res_org);
  }
}

END_TEST

Suite* suite_s21_calculation() {
  Suite* s = suite_create("test_calculation");
  TCase* tc = tcase_create("test_calculation_tc");

  tcase_add_test(tc, test_calculation);
  suite_add_tcase(s, tc);
  return s;
}
