CFLAGS = -Wall -Werror -Wextra -std=c11 -g
MATRIXFUNC = $(SOURCES:.c=.o)
SOURCES = s21_calc_complements.c s21_create_matrix.c s21_determinant.c s21_eq_matrix.c s21_inverse_matrix.c s21_mult_matrix.c s21_mult_number.c s21_remove_matrix.c s21_sub_matrix.c s21_sum_matrix.c s21_transpose.c secondary_functions.c
TESTS = s21_matrix_tests.o
S21MATRIXLIB = s21_matrix.a

UNAME = $(shell uname -s)
FLAGS = 

ifeq ($(UNAME), Linux)
	FLAGS += -lcheck_pic -lm -lsubunit -lrt -lpthread -g
else
	FLAGS += -lcheck
endif

all: test

%.o: %.c
	gcc $(CFLAG) -c $^  -o $@

test: $(TESTS) $(S21MATRIXLIB)
	gcc  $^ -g -o test $(FLAGS)
	rm -rf *.o 
	./test

$(TESTS): $(TESTS:.o=.c)
	gcc -Wall -std=c11 -c $^  -o $@
	
s21_matrix.a: $(MATRIXFUNC)
	ar rc $(S21MATRIXLIB) $^
	ranlib $(S21MATRIXLIB)

rebuild: clean all

gcov_report: clean $(TESTS)
	gcc -o test $(TESTS) --coverage $(SOURCES) $(FLAGS)
	./test
	lcov -t "a.out" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
	rm -rf test *.o *.a *gcda *gcno *info

clean:
	rm -rf test *.o *.a *gcda report *gcno *info
