#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!A || !result) {
    return INCORRECT_MATRIX;
  }

  if (wrong_matrix(*A)) {
    return INCORRECT_MATRIX;
  }

  int error_code = OK;
  error_code = s21_create_matrix(A->rows, A->columns, result);
  if (error_code != OK) {
    return error_code;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;

      if (!isfinite(result->matrix[i][j])) {
        error_code = OPERATION_ERROR;
        break;
      }
    }
    if (error_code != OK) {
      break;
    }
  }

  return error_code;
}

/**
 * @brief Функция для умножения матрицы на матрицу
 *
 * @param *A указатель матрицу, тип matrix_t
 * @param number мультипликатор, тип int
 * @param *result указатель матрицу, тип matrix_t
 * @return 0 - OK, 1 - ERROR, 2 - OPERATION_ERROR
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (A && B && result && !wrong_matrix(*A) && !wrong_matrix(*B)) {
    if (A->columns == B->rows) {
      error_code = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows && !error_code; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            if (!isfinite(result->matrix[i][j])) error_code = OPERATION_ERROR;
          }
        }
      }
    } else
      error_code = OPERATION_ERROR;
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}
