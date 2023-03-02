#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int r = 0; r < A->rows; r++) {
        free(A->matrix[r]);
      }
      free(A->matrix);
      A->matrix = NULL;
      A->rows = 0;
      A->columns = 0;
    }
  }
}