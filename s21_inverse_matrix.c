#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = 0;
  if (check_matrix(A) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  double determinant = 0.0;
  s21_determinant(A, &determinant);
  if (code == 0) {
    if (A->rows == A->columns) {
      if (determinant != 0) {
        if (A->rows == 1) {
          s21_create_matrix(A->rows, A->columns, result);
          result->matrix[0][0] = 1 / A->matrix[0][0];
        } else {
          matrix_t temp_matrix_cof, temp_matrix_cof_trans;
          s21_calc_complements(A, &temp_matrix_cof);
          s21_transpose(&temp_matrix_cof, &temp_matrix_cof_trans);
          double coef = 1 / determinant;
          s21_mult_number(&temp_matrix_cof_trans, coef, result);
          s21_remove_matrix(&temp_matrix_cof);
          s21_remove_matrix(&temp_matrix_cof_trans);
        }
      } else {
        code = 2;
      }
    } else {
      code = 2;
    }
  }
  return code;
}