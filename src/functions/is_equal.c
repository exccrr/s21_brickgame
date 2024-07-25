#include "../s21_matrix.h"

/**
 * @brief Функция для создания матрицы
 *
 * @param rows количество строк, тип int
 * @param columns количество столбцов, тип int
 * @param *result указатель матрицу, тип matrix_t
 * @return 0 - FAILURE, 1 - SUCCESS
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error_code = SUCCESS;
  if ((A && B) && (A->rows == B->rows) && (A->columns == B->columns)) {
    for (int i = 0; i < A->rows && error_code; i++) {
      for (int j = 0; j < A->columns && error_code; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7 || nan_inf(*A) ||
            nan_inf(*B)) {
          error_code = FAILURE;
        }
      }
    }
  } else {
    error_code = FAILURE;
  }
  return error_code;
}
