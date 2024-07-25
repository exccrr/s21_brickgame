#include "../s21_matrix.h"

/**
 * @brief Функция для транспонирования матрицы
 *
 * @param *A указатель матрицу, тип matrix_t
 * @param *result указатель матрицу, тип matrix_t
 * @return 0 - OK, 1 - INCORRECT_MATRIX, 2 - OPERATION_ERROR
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (A && result && !wrong_matrix(*A)) {
    error_code = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows && !error_code; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
    }
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}