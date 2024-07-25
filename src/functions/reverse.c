#include "../s21_matrix.h"

/**
 * @brief Функция для умножения матрицы на матрицу
 *
 * @param *A указатель матрицу, тип matrix_t
 * @param *result указатель матрицу, тип matrix_t
 * @return 0 - OK, 1 - INCORRECT_MATRIX, 2 - OPERATION_ERROR
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  // возможно нужны еще какие -то проверки
  if (A && result && !wrong_matrix(*A)) {
    if (A->rows == A->columns) {
      double det = 0.0L;
      error_code = s21_determinant(A, &det);
      // если возможно вычислить детерминант и он не равен нулю
      if (!error_code && det != 0.0L) {
        det = 1 / det;
        if (A->rows == 1) {
          s21_create_matrix(1, 1, result);
          result->matrix[0][0] = 1.0 / A->matrix[0][0];
        } else {
          matrix_t calc = {NULL, 0, 0};
          matrix_t transp = {NULL, 0, 0};
          s21_calc_complements(A, &calc);
          s21_transpose(&calc, &transp);
          s21_mult_number(&transp, det, result);
          s21_remove_matrix(&transp);
          s21_remove_matrix(&calc);
        }

      } else
        error_code = OPERATION_ERROR;

    } else
      error_code = OPERATION_ERROR;
  } else {
    error_code = INCORRECT_MATRIX;
  }

  return error_code;
}
