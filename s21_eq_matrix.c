#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (check_matrix(A) == 0 && check_matrix(B) == 0) {
    if ((A->columns == B->columns) && (A->rows == B->rows)) {
      for (int r = 0; r < A->rows; r++) {
        for (int c = 0; c < A->columns; c++) {
          if ((fabs(A->matrix[r][c] - B->matrix[r][c]) > S21_EPS)) {
            code = FAILURE;
          }
        }
      }
    } else {
      code = FAILURE;
    }
  } else {
    code = FAILURE;
  }
  return code;
}