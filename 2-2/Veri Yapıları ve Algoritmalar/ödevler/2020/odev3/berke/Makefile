all: compile run

compile: 20011602.c
	gcc -ansi -g -o 20011602.out 20011602.c

run:
	./20011602.out

memcheck:
	make compile &&\
	valgrind --tool=memcheck --leak-check=full -s ./20011602.out

debug:
	make compile &&\
	gdb ./20011602.out