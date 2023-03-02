# matrix.h-library

### Implementation of my own version of the matrix.h library in C

Library for processing numerical matrices in the C programming language implement basic operations with matrices:

1. Creating matrix int s21_create_matrix(int rows, int columns, matrix_t *result);
2. Cleaning of matrices void s21_remove_matrix(matrix_t *A);
3. Matrix comparison int s21_eq_matrix(matrix_t *A, matrix_t *B);
4. Adding matrices int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
5. Substracting matrices int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
6. Matrix multiplication by scalar int s21_mult_number(matrix_t *A, double number, matrix_t *result);
7. Multiplication of two matrices int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
8. Matrix transpose int s21_transpose(matrix_t *A, matrix_t *result);
9. Minor of matrix and matrix of algebraic complements int s21_calc_complements(matrix_t *A, matrix_t *result);
10. Matrix determinant int s21_determinant(matrix_t *A, double *result);
11. Inverse of matrix int s21_inverse_matrix(matrix_t *A, matrix_t *result);


Makefile used for building the library and tests (with the targets all, clean, test, s21_matrix.a, gcov_report). The gcov_report target generates a gcov report in the form of an html page.
Unit-tests check the result of implementation by comparing them with the right answers. Tests cover at least 80% of each function.
