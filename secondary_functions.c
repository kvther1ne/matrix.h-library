#include "s21_matrix.h"

void matrix_minor(int i, int j, matrix_t *A, matrix_t *minor) {
  int i_rm = 0, j_rm = 0;
  for (int r = 0; r < A->rows; r++) {
    if (r != i) {
      for (int c = 0; c < A->columns; c++) {
        if (c != j) {
          minor->matrix[i_rm][j_rm] = A->matrix[r][c];
          j_rm++;
        }
      }
      i_rm++;
      j_rm = 0;
    }
  }
}

void cofactor_matrix(matrix_t *A) {
  for (int r = 0; r < A->rows; r++) {
    for (int c = 0; c < A->columns; c++) {
      A->matrix[r][c] *= pow(-1, (r + c));
    }
  }
}

int check_matrix(matrix_t *A) {
  int code = 1;
  if (A != NULL) {
    if (A->matrix != NULL && A->rows > 0 && A->columns > 0) {
      code = 0;
    }
  }
  return code;
}