#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = 0;
  if (check_matrix(A) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  if (code == 0) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = 1;
      } else {
        matrix_t temp_matrix;
        s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix);
        for (int r = 0; r < A->rows; r++) {
          for (int c = 0; c < A->columns; c++) {
            matrix_minor(r, c, A, &temp_matrix);
            double determinant;
            s21_determinant(&temp_matrix, &determinant);
            result->matrix[r][c] = determinant;
          }
        }
        s21_remove_matrix(&temp_matrix);
        cofactor_matrix(result);
      }
    } else {
      code = 2;
    }
  }
  return code;
}