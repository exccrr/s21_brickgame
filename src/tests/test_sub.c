#include "tests.h"

// WARNING ALL TEST - SIMPLE PASS
START_TEST(sub_matrix) {
  // все данные корректны, квадратные матрицы
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][3] = {{-2, -5, -7}, {-6, -3, -4}, {-5, 2, 3}};
    double mas_ch[3][3] = {{4, 10, 14}, {12, 6, 8}, {10, -4, -6}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, квадратные матрицы
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2.7, 5.7, 7.7}, {6.7, 3.7, 4.7}, {5.7, -2.7, -3.7}};
    double mas_b[3][3] = {{-2, -5, -7}, {-6, -3, -4}, {-5, 2, 3}};
    double mas_ch[3][3] = {
        {4.7, 10.7, 14.7}, {12.7, 6.7, 8.7}, {10.7, -4.7, -6.7}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, квадратные матрицы
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2.7, 5.7, 7.7}, {6.7, 3.7, 4.7}, {5.7, -2.7, -3.7}};
    double mas_b[3][3] = {
        {-2.4, -2.4, -2.4}, {-2.4, 2.4, 2.4}, {2.4, 2.4, 2.4}};
    double mas_ch[3][3] = {
        {5.1, 8.1, 10.1}, {9.1, 1.3, 2.3}, {3.3, -5.1, -6.1}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, квадратные матрицы, вычитание с 0й матрицей
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2.7, 5.7, 7.7}, {6.7, 3.7, 4.7}, {5.7, -2.7, -3.7}};
    double mas_b[3][3] = {0};
    double mas_ch[3][3] = {{2.7, 5.7, 7.7}, {6.7, 3.7, 4.7}, {5.7, -2.7, -3.7}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, квадратные матрицы, вычитание с равной матрицей
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2.7, 5.7, 7.7}, {6.7, 3.7, 4.7}, {5.7, -2.7, -3.7}};
    double mas_b[3][3] = {{2.7, 5.7, 7.7}, {6.7, 3.7, 4.7}, {5.7, -2.7, -3.7}};
    double mas_ch[3][3] = {0};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, прямоугольные матрицы , разное кол-во столбцов
  {
    int row = 2;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[2][3] = {{2.0000007L, 5.00007L, 7.0007L},
                          {6.00000007L, 3.0007L, 4.7L}};
    double mas_b[2][3] = {{2.7, 5.7L, 7.7L}, {6.7L, -3.7L, 4.7L}};

    double mas_ch[2][3] = {{-0.6999993L, -0.69993L, -0.6993L},
                           {-0.69999993L, 6.7007L, 0L}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, прямоугольные матрицы, разное кол-во строк
  {
    int row = 3;
    int col = 2;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][2] = {
        {2.0000007L, 5.00007L}, {6.00000007L, 3.0007L}, {7.0007L, 4.7L}};
    double mas_b[3][2] = {{2.7, 5.7L}, {6.7L, -3.7L}, {7.7L, 4.7L}};
    double mas_ch[3][2] = {
        {-0.6999993L, -0.69993L}, {-0.69999993L, 6.7007L}, {-0.6993L, 0L}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, прямоугольные матрицы , 1 строка
  {
    int row = 1;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[1][3] = {{6.00000007L, 3.0007L, 4.7L}};
    double mas_b[1][3] = {{6.7L, -3.7L, 4.7L}};
    double mas_ch[1][3] = {{-0.69999993L, 6.7007L, 0L}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // все данные корректны, прямоугольные матрицы , 1 столбец
  {
    int row = 5;
    int col = 1;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t check = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[5][1] = {{2.0000007L}, {6.00000007L}, {18}, {0}, {2.3333}};
    double mas_b[5][1] = {{2.7}, {6.7L}, {3.1}, {0}, {-1.6666}};
    double mas_ch[5][1] = {
        {-0.6999993L}, {-0.69999993L}, {14.9}, {0}, {3.9999}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &B);
    s21_create_matrix(row, col, &check);

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
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        check.matrix[i][j] = mas_ch[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // На вход подается неинициализированная матрица А
  {
    int row = 5;
    int col = 1;
    matrix_t* A = NULL;
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_b[5][1] = {{-2.7}, {-6.7L}, {-3.1}, {0}, {1.6666}};

    s21_create_matrix(row, col, &B);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        B.matrix[i][j] = mas_b[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(A, &B, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&B);
  }
  // На вход подается неинициализированная матрица B
  {
    int row = 5;
    int col = 1;
    matrix_t* B = NULL;
    matrix_t A = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[5][1] = {{-2.7}, {-6.7L}, {-3.1}, {0}, {1.6666}};

    s21_create_matrix(row, col, &A);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        A.matrix[i][j] = mas_a[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, B, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // На вход подается неинициализированная матрица result
  {
    int row = 5;
    int col = 1;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t* result = NULL;

    double mas_a[5][1] = {{2.0000007L}, {6.00000007L}, {18}, {0}, {2.3333}};
    double mas_b[5][1] = {{-2.7}, {-6.7L}, {-3.1}, {0}, {1.6666}};

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

    ck_assert_int_eq(s21_sub_matrix(&A, &B, result), INCORRECT_MATRIX);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы разных размеров
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[4][3] = {{1, 2, 3}, {2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};

    s21_create_matrix(row + 1, col, &A);
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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы разных размеров 2
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][5] = {
        {2, 5, 7, 23, 1}, {6, 3, 4, 11, 11}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы содержащие NAN
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2, 5, NAN}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][5] = {
        {2, 5, 7, 23, 1}, {6, 3, 4, 11, 11}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы содержащие NAN 2
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{2, 5, 0}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][5] = {
        {NAN, 5, 7, 23, 1}, {6, 3, 4, 11, 11}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы содержащие NAN 3
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{NAN, 5, 0}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][5] = {
        {NAN, 5, 7, 23, 1}, {6, 3, 4, 11, 11}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы содержащие INFINITY
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{INFINITY, 5, 0}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][5] = {
        {5, 5, 7, 23, 1}, {6, 3, 4, 11, 11}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы содержащие INFINITY 2
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{10, 5, 0}, {6, 3, 4}, {5, -2, -3}};
    double mas_b[3][5] = {
        {5, 5, 7, 23, 1}, {6, 3, 4, INFINITY, 11}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Подаются матрицы содержащие INFINITY 3
  {
    int row = 3;
    int col = 3;
    matrix_t A = {NULL, row, col};
    matrix_t B = {NULL, row, col};
    matrix_t result = {NULL, row, col};

    double mas_a[3][3] = {{4, 5, 0}, {6, 3, 4}, {5, -2, -INFINITY}};
    double mas_b[3][5] = {
        {5, 5, 7, 23, 1}, {6, 3, 4, 11, -INFINITY}, {5, -2, -3, 12, 3}};

    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col + 2, &B);

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
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }

  // ANDRY

  {
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(5, 5, &A);
    for (int i = 0; i < A.rows; ++i) {
      for (int j = 0, k = 0; j < A.columns; ++j, ++k) {
        A.matrix[i][j] = k;
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), 1);
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
    ck_assert_int_eq(s21_sub_matrix(NULL, &B, &result), 1);
    s21_remove_matrix(&B);
  }
  { ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL), 1); }
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
    eq.matrix[0][0] = -2;
    eq.matrix[0][1] = -4;
    eq.matrix[0][2] = -6;
    eq.matrix[0][3] = -8;
    eq.matrix[1][0] = -10;
    eq.matrix[1][1] = -12;
    eq.matrix[1][2] = -14;
    eq.matrix[1][3] = -16;
    eq.matrix[2][0] = -18;
    eq.matrix[2][1] = -20;
    eq.matrix[2][2] = -22;
    eq.matrix[2][3] = -24;
    eq.matrix[3][0] = -26;
    eq.matrix[3][1] = -28;
    eq.matrix[3][2] = -30;
    eq.matrix[3][3] = -32;
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
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
    for (double i = 0, k = 0.000001, l = 0.000003; i < A.rows; ++i) {
      for (double j = 0; j < A.columns; ++j, k += 0.000001, l += 0.000003) {
        A.matrix[(int)i][(int)j] = k;
        B.matrix[(int)i][(int)j] = l;
      }
    }
    eq.matrix[0][0] = -0.000002;
    eq.matrix[0][1] = -0.000004;
    eq.matrix[0][2] = -0.000006;
    eq.matrix[0][3] = -0.000008;
    eq.matrix[1][0] = -0.000010;
    eq.matrix[1][1] = -0.000012;
    eq.matrix[1][2] = -0.000014;
    eq.matrix[1][3] = -0.000016;
    eq.matrix[2][0] = -0.000018;
    eq.matrix[2][1] = -0.000020;
    eq.matrix[2][2] = -0.000022;
    eq.matrix[2][3] = -0.000024;
    eq.matrix[3][0] = -0.000026;
    eq.matrix[3][1] = -0.000028;
    eq.matrix[3][2] = -0.000030;
    eq.matrix[3][3] = -0.000032;
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
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
    s21_create_matrix(4, 5, &A);
    s21_create_matrix(5, 5, &B);
    for (int i = 0; i < A.rows; ++i) {
      for (int j = 0, k = 0; j < A.columns; ++j, ++k) {
        A.matrix[i][j] = k;
      }
    }
    for (int i = 0; i < B.rows; ++i) {
      for (int j = 0, k = 0; j < B.columns; ++j, ++k) {
        B.matrix[i][j] = k;
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(5, 5, &A);
    s21_create_matrix(5, 5, &B);
    for (int i = 0; i < B.rows; ++i) {
      for (int j = 0, k = 0; j < B.columns; ++j, ++k) {
        A.matrix[i][j] = k;
        B.matrix[i][j] = k;
      }
    }
    B.matrix[2][3] = NAN;
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
  }
  {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t eq = {0};
    matrix_t result = {0};
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);
    s21_create_matrix(1, 1, &eq);
    A.matrix[0][0] = 0.0000004;
    B.matrix[0][0] = 0.0000002;
    eq.matrix[0][0] = 0.0000002;
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
    ck_assert_int_eq(s21_eq_matrix(&result, &eq), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&eq);
    s21_remove_matrix(&result);
  }
}

END_TEST

Suite* suite_s21_sub_matrix() {
  Suite* s = suite_create("sub_matrix");
  TCase* tc = tcase_create("sub_matrix_tc");

  tcase_add_test(tc, sub_matrix);
  suite_add_tcase(s, tc);
  return s;
}
