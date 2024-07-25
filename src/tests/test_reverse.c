#include "tests.h"

// WARNING ALL TEST - SIMPLE PASS

START_TEST(test_reverse) {
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_ch[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

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
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    double mas_a[3][3] = {{20, -1.3, -10.1}, {1, 1, 1}, {5, -2, -3}};
    double mas_ch[3][3] = {{-0.02481389L, 0.404466501L, 0.218362282L},
                           {0.198511166L, -0.2357320099L, -0.74689826L},
                           {-0.17369727L, 0.831265508L, 0.52853598L}};

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
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны
  {
    int row = 4;
    int col = 4;
    matrix_t A = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};
    double mas_a[4][4] = {{-4.1, -2, 0, 0.2},
                          {0.4, 13, 21, -0.3},
                          {5, -2, 3.3, -9.1},
                          {1, 2, 3, 4}};
    double mas_ch[4][4] = {
        {-0.125842052L, -0.033252114L, 0.0678419569L, 0.158138646l},
        {-0.238247097L, 0.0651784434L, -0.14016291624L, -0.3020698963L},
        {0.1504228178L, 0.007476948L, 0.085320019L, 0.187142675L},
        {0.037766948L, -0.029883904L, -0.0108690459L, 0.22114328L}};

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
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // детерминант матрицы = 0 => ошибка вычисления
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{10, 5, -1}, {0, 0, 0}, {5, -2, -3}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // сроки и столбцы не совпадают
  {
    int row = 4;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[4][3] = {{10, 5, -1}, {0, 0, 0}, {5, -2, -3}, {1, 1, 1}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // сроки и столбцы не совпадают
  {
    int row = 3;
    int col = 4;
    matrix_t A = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][4] = {{10, 5, -1, 1}, {0, 0, 0, 0}, {5, -2, -3, 4}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // структура не инициализированна
  {
    int row = 3;
    int col = 4;
    matrix_t* A = NULL;
    matrix_t result = {NULL, row, col};

    s21_create_matrix(row, col, &result);

    ck_assert_int_eq(s21_inverse_matrix(A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&result);
  }
  // структура не инициализированна
  {
    int row = 3;
    int col = 3;
    matrix_t* result = NULL;
    matrix_t A = {NULL, row, col};
    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};

    s21_create_matrix(row, col, &A);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // отрицательный размер столбца
  {
    int row = 3;
    int col = -1;
    matrix_t* result = NULL;
    matrix_t A = {NULL, row, col};

    ck_assert_int_eq(s21_inverse_matrix(&A, result), INCORRECT_MATRIX);
  }
  // нулевой размер столбца
  {
    int row = 3;
    int col = 0;
    matrix_t* result = NULL;
    matrix_t A = {NULL, row, col};

    ck_assert_int_eq(s21_inverse_matrix(&A, result), INCORRECT_MATRIX);
  }
  // отрицательный размер строки
  {
    int row = -2;
    int col = 1;
    matrix_t* result = NULL;
    matrix_t A = {NULL, row, col};

    ck_assert_int_eq(s21_inverse_matrix(&A, result), INCORRECT_MATRIX);
  }
  // нулевой размер строки
  {
    int row = -2;
    int col = 0;
    matrix_t* result = NULL;
    matrix_t A = {NULL, row, col};

    ck_assert_int_eq(s21_inverse_matrix(&A, result), INCORRECT_MATRIX);
  }
  // and

  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_inverse_matrix(NULL, &result), 1);
  }
  {
    matrix_t A = {0};
    ck_assert_int_eq(s21_inverse_matrix(&A, NULL), 1);
  }
  { ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), 1); }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(3, 2, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);
    s21_remove_matrix(&A);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 4;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 6;
    A.matrix[2][0] = 7;
    A.matrix[2][1] = 8;
    A.matrix[2][2] = 9;
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &eq);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;

    eq.matrix[0][0] = 1;
    eq.matrix[0][1] = -1;
    eq.matrix[0][2] = 1;
    eq.matrix[1][0] = -38;
    eq.matrix[1][1] = 41;
    eq.matrix[1][2] = -34;
    eq.matrix[2][0] = 27;
    eq.matrix[2][1] = -29;
    eq.matrix[2][2] = 24;
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    matrix_t A = {0};
    matrix_t result = {0};
    matrix_t eq = {0};
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &eq);
    A.matrix[0][0] = 2;

    eq.matrix[0][0] = 0.5;

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&eq);
  }
  {
    double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
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
    int ret = s21_inverse_matrix(&matrix, &res_my);
    ck_assert_int_eq(ret, 0);
    ret = s21_eq_matrix(&res_org, &res_my);
    ck_assert_int_eq(ret, 1);
    s21_remove_matrix(&matrix);
    s21_remove_matrix(&res_my);
    s21_remove_matrix(&res_org);
  }
}
END_TEST

Suite* suite_s21_reverse() {
  Suite* s = suite_create("test_reverse");
  TCase* tc = tcase_create("test_reverse_tc");

  tcase_add_test(tc, test_reverse);
  suite_add_tcase(s, tc);
  return s;
}
