CC = gcc -g -Wall -Werror -Wextra -std=c11 -D_GNU_SOURSE
SU = suite_test_
CO = convertation/
OK = okruglenie/
SR = sravnenie/
OS = $(shell uname -s)
ifeq ($(OS), Linux)
UBU =  -lm -lpthread -lrt -lsubunit
else
UBU = 
endif

all: clean s21_decimal.a test gcov_report

s21_decimal.a:
	mkdir obj
	$(CC) -c $(CO)s21_from_int_to_decimal/s21_from_int_to_decimal.c -o obj/s21_from_int_to_decimal.o
	$(CC) -c $(CO)s21_from_float_to_decimal/s21_from_float_to_decimal.c -o obj/s21_from_float_to_decimal.o
	$(CC) -c $(CO)s21_from_decimal_to_int/s21_from_decimal_to_int.c -o obj/s21_from_decimal_to_int.o
	$(CC) -c $(CO)s21_from_decimal_to_float/s21_from_decimal_to_float.c -o obj/s21_from_decimal_to_float.o
	$(CC) -c math/s21_add/s21_add.c -o obj/s21_add.o
	$(CC) -c math/s21_sub/s21_sub.c -o obj/s21_sub.o
	$(CC) -c math/s21_mul/s21_mul.c -o obj/s21_mul.o
	$(CC) -c math/s21_div/s21_div.c -o obj/s21_div.o
	$(CC) -c math/s21_mod/s21_mod.c -o obj/s21_mod.o
	$(CC) -c $(SR)s21_is_less/s21_is_less.c -o obj/s21_is_less.o
	$(CC) -c $(SR)s21_is_less_or_equal/s21_is_less_or_equal.c -o obj/s21_is_less_or_equal.o
	$(CC) -c $(SR)s21_is_greater/s21_is_greater.c -o obj/s21_is_greater.o
	$(CC) -c $(SR)s21_is_greater_or_equal/s21_is_greater_or_equal.c -o obj/s21_is_greater_or_equal.o
	$(CC) -c $(SR)s21_is_equal/s21_is_equal.c -o obj/s21_is_equal.o
	$(CC) -c $(SR)s21_is_not_equal/s21_is_not_equal.c -o obj/s21_is_not_equal.o
	$(CC) -c $(OK)s21_floor/s21_floor.c -o obj/s21_floor.o
	$(CC) -c $(OK)s21_round/s21_round.c -o obj/s21_round.o
	$(CC) -c $(OK)s21_truncate/s21_truncate.c -o obj/s21_truncate.o
	$(CC) -c $(OK)s21_negate/s21_negate.c -o obj/s21_negate.o
	$(CC) -c other/mul_10.c -o obj/mul_10.o
	ar rcs s21_decimal.a obj/*.o
	ranlib s21_decimal.a

test.a:
	$(CC) -c $(CO)s21_from_int_to_decimal/$(SU)s21_from_int_to_decimal.c -o obj/$(SU)s21_from_int_to_decimal.o
	$(CC) -c $(CO)s21_from_float_to_decimal/$(SU)s21_from_float_to_decimal.c -o obj/$(SU)s21_from_float_to_decimal.o
	$(CC) -c $(CO)s21_from_decimal_to_int/$(SU)s21_from_decimal_to_int.c -o obj/$(SU)s21_from_decimal_to_int.o
	$(CC) -c $(CO)s21_from_decimal_to_float/$(SU)s21_from_decimal_to_float.c -o obj/$(SU)s21_from_decimal_to_float.o
	$(CC) -c math/s21_add/$(SU)s21_add.c -o obj/$(SU)s21_add.o
	$(CC) -c math/s21_sub/$(SU)s21_sub.c -o obj/$(SU)s21_sub.o
	$(CC) -c math/s21_mul/$(SU)s21_mul.c -o obj/$(SU)s21_mul.o
	$(CC) -c math/s21_div/$(SU)s21_div.c -o obj/$(SU)s21_div.o
	$(CC) -c math/s21_mod/$(SU)s21_mod.c -o obj/$(SU)s21_mod.o
	$(CC) -c $(SR)s21_is_less/$(SU)s21_is_less.c -o obj/$(SU)s21_is_less.o
	$(CC) -c $(SR)s21_is_less_or_equal/$(SU)s21_is_less_or_equal.c -o obj/$(SU)s21_is_less_or_equal.o
	$(CC) -c $(SR)s21_is_greater/$(SU)s21_is_greater.c -o obj/$(SU)s21_is_greater.o
	$(CC) -c $(SR)s21_is_greater_or_equal/$(SU)s21_is_greater_or_equal.c -o obj/$(SU)s21_is_greater_or_equal.o
	$(CC) -c $(SR)s21_is_equal/$(SU)s21_is_equal.c -o obj/$(SU)s21_is_equal.o
	$(CC) -c $(SR)s21_is_not_equal/$(SU)s21_is_not_equal.c -o obj/$(SU)s21_is_not_equal.o
	$(CC) -c $(OK)s21_floor/$(SU)s21_floor.c -o obj/$(SU)s21_floor.o
	$(CC) -c $(OK)s21_round/$(SU)s21_round.c -o obj/$(SU)s21_round.o
	$(CC) -c $(OK)s21_truncate/$(SU)s21_truncate.c -o obj/$(SU)s21_truncate.o
	$(CC) -c $(OK)s21_negate/$(SU)s21_negate.c -o obj/$(SU)s21_negate.o
	ar rcs test.a obj/*.o
	ranlib test.a

test: s21_decimal.a test.a
	$(CC) test_main.c -L. s21_decimal.a test.a -lcheck $(UBU) -o test_decimal.out
	./test_decimal.out

gcov_report: s21_decimal.a test.a
	$(CC) --coverage *.c other/*.c $(CO)s21_from_int_to_decimal/*.c $(CO)s21_from_float_to_decimal/*.c $(CO)s21_from_decimal_to_int/*.c \
	$(CO)s21_from_decimal_to_float/*.c math/s21_add/*.c math/s21_sub/*.c math/s21_mul/*.c math/s21_div/*.c math/s21_mod/*.c \
	$(SR)s21_is_less/*.c $(SR)s21_is_less_or_equal/*.c $(SR)s21_is_greater/*.c $(SR)s21_is_greater_or_equal/*.c $(SR)s21_is_equal/*.c \
	$(SR)s21_is_not_equal/*.c $(OK)s21_floor/*.c $(OK)s21_round/*.c $(OK)s21_truncate/*.c $(OK)s21_negate/*.c -lcheck $(UBU) s21_decimal.a -L. s21_decimal.a test.a -o test_decimal.out
	./test_decimal.out
	lcov -t "my_test" -c -d ./ --output-file ./test.info
	genhtml -o report test.info
	rm -rf *.gcda *.gch *.gcno *.out *.o *.out
	open report/index.html

clean:
	rm -rf *.o *.gcda *.info report *.gcno *.a *.out obj/*.o obj *.out.dSYM
