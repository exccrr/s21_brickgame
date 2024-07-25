#include "../s21_matrix.h"

/**
 * @brief Функция для сложения матриц
 *
 * @param A адрес на матрицу, тип matrix_t
 * @param B адрес на матрицу, тип matrix_t
 * @param result адрес на матрицу, тип matrix_t
 *
 * @return 0 - OK, 1 - INCORRECT_MATRIX, 2 - OPERATION_ERROR
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (A && B && result && !wrong_matrix(*A) && !wrong_matrix(*B)) {
    if (A->rows == B->rows && A->columns == B->columns && !nan_inf(*A) &&
        !nan_inf(*B)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          if (!isfinite(result->matrix[i][j])) error_code = OPERATION_ERROR;
        }
      }
    } else
      error_code = OPERATION_ERROR;
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}

/**
 * @brief Функция для вычитания матриц
 *
 * @param A адрес на матрицу, тип matrix_t
 * @param B адрес на матрицу, тип matrix_t
 * @param result адрес на матрицу, тип matrix_t
 *
 * @return 0 - OK, 1 - INCORRECT_MATRIX, 2 - OPERATION_ERROR
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (A && B && result && !wrong_matrix(*A) && !wrong_matrix(*B)) {
    if (A->rows == B->rows && A->columns == B->columns && !nan_inf(*A) &&
        !nan_inf(*B)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          if (!isfinite(result->matrix[i][j])) error_code = OPERATION_ERROR;
        }
      }
    } else
      error_code = OPERATION_ERROR;
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}
