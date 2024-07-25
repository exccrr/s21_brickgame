CC = gcc
flags = -Werror -Wall -Wextra -std=c11
check_flag = -lcheck
gcov_flags = -fprofile-arcs -ftest-coverage
valgrind_flags = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=high
# valgrind_flags = --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=high

files = ./functions/*.c
test_files = ./tests/*.c
out_file = ./s21_matrix
library = ./s21_matrix.a

ifeq ($(shell uname -s), Linux)
	check_flag += -lm -lsubunit
	open=xdg-open
else
	open=open
endif

all: clang s21_matrix.a

s21_matrix.a:
	$(CC) -c $(flags) $(files)
	ar rcs $(library) ./*.o 
	ranlib $(library)
	rm ./*.o

debug: s21_matrix.a
	$(CC) $(flags) $(library) -o debug

test: s21_matrix.a
	$(CC) $(flags) $(test_files) $(library) -o $(out_file) $(check_flag)
	./s21_matrix

gcov_report:
	$(CC) $(flags) $(gcov_flags) $(test_files) $(files) -o $(out_file) $(check_flag)
	./s21_matrix
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	$(open) report/index.html
	make rm_gcov
	rm *.info

clean:
	-rm $(out_file)
	-rm $(library)
	-rm -rf report
	-rm valgrind.txt
	-rm *.o
	-rm *.a
	-rm ./debug
	-rm -rf s21_matrix.dSYM

rebuild:
	make clean
	make all

rm_gcov:
	rm *.gcno	
	rm *.gcda

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i */*.c *.h
	rm -fr ./.clang-format

format_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h

valgrind: s21_matrix.a
	$(CC) $(flags) $(test_files) $(library) -o $(out_file) $(check_flag)
	valgrind $(valgrind_flags) $(out_file)
# valgrind: s21_matrix.a debug
# 	valgrind $(valgrind_flags) ./debug