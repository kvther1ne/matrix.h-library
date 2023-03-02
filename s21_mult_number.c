#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = 0;
  if (check_matrix(A) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  if (code == 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[r][c] = A->matrix[r][c] * number;
      }
    }
  }
  return code;
}