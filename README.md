# matrix.h-library

### Реализация библиотеки matrix.h на языке С

В данном проекте я реализовала свою библиотеку для обработки числовых матриц на языке программирования Си. Матрицы являются одной из базовых структур данных в программировании, например, они применяются для представления табличных значений, для вычислительных задач и нейронных сетей.

Библиотека для работы с матрицами включает следующие операции:

1. Создание матриц int s21_create_matrix(int rows, int columns, matrix_t *result);
2. Очистка матриц void s21_remove_matrix(matrix_t *A);
3. Сравнение матриц int s21_eq_matrix(matrix_t *A, matrix_t *B);
4. Сложение матриц int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
5. Вычитание матриц int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
6. Умножение матрицы на скаляр int s21_mult_number(matrix_t *A, double number, matrix_t *result);
7. Перемножение матриц int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
8. Транспонирование матрицы int s21_transpose(matrix_t *A, matrix_t *result);
9. Минор матрицы и матрица алгебраических дополнений int s21_calc_complements(matrix_t *A, matrix_t *result);
10. Детерминант матрицы int s21_determinant(matrix_t *A, double *result);
11. Обратная матрица int s21_inverse_matrix(matrix_t *A, matrix_t *result);

Сборка программ настроена с помощью Makefile с соответствующими целями: all, clean, test, s21_matrix.a, gcov_report. Реализовано покрытие интеграционными тестами для всех вариантов флагов и входных значений.
