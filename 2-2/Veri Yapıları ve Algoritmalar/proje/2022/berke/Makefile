all: compile run

compile: 20011602.c
	gcc -ansi -g -o 20011602.out 20011602.c

run:
	./20011602.out

memcheck:
	make compile &&\
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./20011602.out

debug:
	make compile &&\
	gdb ./20011602.out

test: 20011602.c
	gcc -o 20011602.out 20011602.c &&\
	make run
