#include "../s21_matrix.h"

/**
 * @brief Функция для определения детерминатора матрицы
 *
 * @param *А указатель на структуру тип matrix_t
 * @param *result указатель на число, тип double
 * @return 0 - OK, 1 - INCORRECT_MATRIX , 2 - OPERATION_ERROR
 */
int s21_determinant(matrix_t* A, double* result) {
  int error_code = OK;
  matrix_t temp = {NULL, 0, 0};
  if (A && result && !wrong_matrix(*A)) {
    if ((A->rows == A->columns) && !nan_inf(*A)) {
      // сделать копию матрицы
      error_code = s21_create_matrix(A->rows, A->columns, &temp);
      if (error_code == OK) {
        copy_matrix(*A, &temp);
        // привести к треугольной
        *result = gause(&temp);
        s21_remove_matrix(&temp);
      }
    } else
      error_code = OPERATION_ERROR;
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}

/**
 * @brief Функция для определения есть ли среди членов матрицы бесконечность
 * или неопределенное значение
 *
 * @param А структура, тип matrix_t
 * @return false - нету, true - есть
 */
bool nan_inf(matrix_t A) {
  bool flag = false;
  for (int i = 0; i < A.rows && !flag; i++) {
    for (int j = 0; j < A.columns && !flag; j++) {
      if (isnan(A.matrix[i][j]) || isinf(A.matrix[i][j])) flag = true;
    }
  }
  return flag;
}

/**
 * @brief Функция меняет местами 0-ю строку с какой-либо другой
 *
 * @param А структура, тип matrix_t
 * @param source_line номер строки которую нужно заменить
 * @param dst_line номер строки на которую нужно заменить
 * @param line номер строки для замены, тип int
 */
void replace_lines(matrix_t* A, int source_line, int dst_line) {
  double temp = 0.0L;
  for (int i = 0; i < A->columns; i++) {
    temp = A->matrix[dst_line][i];
    A->matrix[dst_line][i] = A->matrix[source_line][i];
    A->matrix[source_line][i] = temp;
  }
}

/**
 * @brief Функция копирует матрицу 1 в матрицу 2
 *
 * @param А структура, тип matrix_t
 * @param *temp указатель на структуру, тип matrix_t
 */
void copy_matrix(matrix_t A, matrix_t* temp) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      temp->matrix[i][j] = A.matrix[i][j];
    }
  }
}

/**
 * @brief Функция создает из матрицы 1 треугольную матрицу 2
 *
 * @param А структура, тип matrix_t
 * @param *temp указатель на структуру, тип matrix_t
 * @return true - встретилось деление -> некорректные вычисления;
 * false - ф-я отработала успешно, деления на 0 не было
 */
double gause(matrix_t* temp) {
  double deter = 1;
  for (int x = 0; x < temp->rows; x++) {
    int y = 0;
    // если элемент главной диагонали равен 0, то пытаюсь поменять эту строку
    // на другую, где элемент в этом столбце ненулевой
    if (temp->matrix[x][x] == 0) {
      for (y = x + 1; y < temp->columns; y++) {
        if (temp->matrix[y][x] != 0) {
          // если нашел такую строку, то делаю замену и прерываю поиск
          replace_lines(temp, x, y);
          deter = -deter;
          break;
        }
      }
    }
    if (y == temp->rows) {
      deter = 0.0;
      break;
    }
    // произвожу преобразование матрицы для данного шага итерации
    make_transformation(temp, x);
    deter *= temp->matrix[x][x];
  }
  return deter;
}

/**
 * @brief Функция производит одну иттерацию преобразования в треугольную
 * матрицу.
 *
 * @param А структура, тип matrix_t
 * @param *temp указатель на структуру, тип matrix_t
 * @return true - встретилось деление -> некорректные вычисления;
 * false - ф-я отработала успешно, деления на 0 не было
 * @note происходит преобразование всех строк по коэффициенту для определенного
 * столбца.
 */
void make_transformation(matrix_t* A, int x) {
  double k = 0.0L;
  for (int i = x + 1; i < A->columns; i++) {
    if (A->matrix[x][x] != 0) {
      k = A->matrix[i][x] / A->matrix[x][x];
      for (int j = x; j < A->columns; j++) {
        A->matrix[i][j] = A->matrix[i][j] - A->matrix[x][j] * k;
      }
    }
  }
}

/**
 * @brief Функция вычисляет определитель верхнетреугольной матрицы
 *
 * @param A структура, тип matrix_t
 * @param *temp указатель на структуру, тип matrix_t
 */
double calculate_det(matrix_t A) {
  double result = 1.0L;
  for (int i = 0; i < A.rows; i++) {
    result *= A.matrix[i][i];
  }
  return result;
}