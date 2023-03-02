#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  double temp = 0;
  int code = 0, degree = 1;
  if (check_matrix(A) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  if (code == 0) {
    if (A->columns == A->rows) {
      if (A->columns == 1) {
        *result = A->matrix[0][0];
      } else if (A->columns == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else if (A->columns > 2) {
        matrix_t new_matrix;
        *result = 0.0;
        for (int c = 0; c < A->columns; c++) {
          temp = 0;
          s21_create_matrix(A->rows - 1, A->columns - 1, &new_matrix);
          matrix_minor(0, c, A, &new_matrix);
          s21_determinant(&new_matrix, &temp);
          *result += degree * (A->matrix[0][c] * temp);
          degree *= -1;
          s21_remove_matrix(&new_matrix);
        }
      }
    } else {
      code = 2;
    }
  }
  return code;
}