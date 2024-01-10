all: compile run

compile:
	gcc -ansi 20011602.c

run:
	a

memcheck:
	gcc -ansi -g 20011602.c &&\
	valgrind --tool=memcheck ./a.out