#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = 0;
  if (rows > 0 && columns > 0 && result != NULL) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    result->rows = rows;
    result->columns = columns;

    for (int r = 0; r < result->rows; r++) {
      result->matrix[r] = (double *)calloc(columns, sizeof(double));
      code = 0;
    }
  } else {
    code = 1;
  }
  return code;
}