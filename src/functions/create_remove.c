#include "../s21_matrix.h"

/**
 * @brief Функция для создания матрицы
 *
 * @param rows количество строк, тип int
 * @param columns количество столбцов, тип int
 * @param *result указатель матрицу, тип matrix_t
 * @return 0 - OK, 1 - INCORRECT_MATRIX, 2 - OPERATION_ERROR
 */
int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (!result || rows < 1 || columns < 1) return INCORRECT_MATRIX;

  int error_code = OK;
  double** matrix = (double**)calloc(rows, sizeof(double*));
  double* r = (double*)calloc(rows * columns, sizeof(double));
  if (matrix && r) {
    for (int i = 0; i < rows; i++) {
      matrix[i] = r + i * columns;
    }
    result->matrix = matrix;
    result->rows = rows;
    result->columns = columns;
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}

/**
 * @brief Функция для удаления матрицы
 *
 * @param *A указатель матрицу, тип matrix_t
 */
void s21_remove_matrix(matrix_t* A) {
  if (A && !wrong_matrix(*A)) {
    free(A->matrix[0]);
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
  }
}
