#ifndef MATRIX_H
#define MATRIX_H

// только для сравнения !!!
#define SUCCESS 1
#define FAILURE 0

// для всех операций над матрицами, кроме сравнения
#define OK 0
#define INCORRECT_MATRIX 1  // некорректная матрица
#define OPERATION_ERROR 2   // ошибка вычисления

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// create, remove
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// equal
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// sum , sub
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// multioplication
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// transponent
int s21_transpose(matrix_t *A, matrix_t *result);

// minor
int s21_calc_complements(matrix_t *A, matrix_t *result);

// determinant
int s21_determinant(matrix_t *A, double *result);

// inversion
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// utilities
int wrong_matrix(matrix_t A);
void s21_print_matrix(matrix_t A);
bool nan_inf(matrix_t A);
bool is_first_zero(matrix_t A);
void replace_lines(matrix_t *A, int source_line, int dst_line);
void copy_matrix(matrix_t A, matrix_t *temp);
double gause(matrix_t *temp);
void make_transformation(matrix_t *A, int col);
double calculate_det(matrix_t A);

#endif