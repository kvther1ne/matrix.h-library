#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = 0;
  if (check_matrix(A) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  if (code == 0) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[c][r] = A->matrix[r][c];
      }
    }
  }
  return code;
}