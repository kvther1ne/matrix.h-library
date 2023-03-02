#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = 0;
  if (check_matrix(A) == 0 && check_matrix(B) == 0) {
    code = 0;
  } else {
    code = 1;
  }
  if (code == 0) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int r = 0; r < A->rows; r++) {
        for (int c = 0; c < A->columns; c++) {
          result->matrix[r][c] = A->matrix[r][c] + B->matrix[r][c];
        }
      }
    } else {
      code = 2;
    }
  }
  return code;
}