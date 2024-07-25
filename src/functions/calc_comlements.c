#include "../s21_matrix.h"

/**
 * @brief Функция для умножения матрицы на матрицу
 *
 * @param *A указатель матрицу, тип matrix_t
 * @param *result указатель матрицу, тип matrix_t
 * @return 0 - OK, 1 - INCORRECT_MATRIX, 2 - OPERATION_ERROR
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int det_error = OK, error_code = OK;
  double det = 0.0L;

  if (A && result && !wrong_matrix(*A)) {
    if (A->rows == A->columns && !nan_inf(*A)) {
      error_code = s21_create_matrix(A->rows, A->columns, result);
      if (error_code == OK && A->rows == 1 && A->columns == 1) {
        result->matrix[0][0] = 1;
      } else if (error_code == OK) {
        int min_row = A->rows - 1;
        int min_col = A->columns - 1;
        matrix_t minor = {NULL, 0, 0};
        error_code = s21_create_matrix(min_row, min_col, &minor);
        // эти 2 цикла просто, что бы идти по начальной матрице
        for (int i = 0; i < A->rows && !error_code; i++) {
          for (int j = 0; j < A->columns && !error_code; j++) {
            // эти что бы понимать какие числа не нужно записывать
            for (int x = 0, min_i = 0; x < A->rows; x++) {
              if (x != i) {
                for (int y = 0, min_j = 0; y < A->columns; y++) {
                  if (y != j) {
                    minor.matrix[min_i][min_j] = A->matrix[x][y];
                    min_j++;
                  }
                }
                min_i++;
              }
            }
            det_error = s21_determinant(&minor, &det);
            if (!det_error) {
              result->matrix[i][j] = ((i + j) & 1) ? -det : det;
            } else {
              error_code = OPERATION_ERROR;
            }
          }
        }
        s21_remove_matrix(&minor);
      }
    } else
      error_code = OPERATION_ERROR;
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}

/**
 * @brief Функция для проверки корректности матрицы
 *
 * @param rows, тип int
 * @param columns, тип int
 *
 * @return 0 - данные корректны, 1 - недопустимые данные
 */
int wrong_matrix(matrix_t A) {
  return (A.rows <= 0 || A.columns <= 0 || A.matrix == NULL);
}