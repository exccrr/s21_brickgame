#ifndef S21_TESTS
#define S21_TESTS
#include <check.h>
#include <stdbool.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *suite_s21_create_matrix();
Suite *suite_s21_equal_matrix();
Suite *suite_s21_add_matrix();
Suite *suite_s21_sub_matrix();
Suite *suite_s21_mul_matrix_num();
Suite *suite_s21_mul_matrix_mat();
Suite *suite_s21_trans_matrix();
Suite *suite_s21_det_2();
Suite *suite_s21_det_n();
Suite *suite_s21_calculation();
Suite *suite_s21_reverse();
Suite *suite_s21_remove_matrix();

#endif