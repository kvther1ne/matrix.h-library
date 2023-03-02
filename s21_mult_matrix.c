#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = 0;
  if (check_matrix(A) == 0 && check_matrix(B) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  if (code == 0) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int r = 0; r < result->rows; r++) {
        for (int c = 0; c < result->columns; c++) {
          result->matrix[r][c] = 0.0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[r][c] += A->matrix[r][k] * B->matrix[k][c];
          }
        }
      }
    } else {
      code = 2;
    }
  }
  return code;
}