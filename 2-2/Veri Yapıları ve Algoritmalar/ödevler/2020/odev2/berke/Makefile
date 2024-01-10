all: compile run

compile: 20011602.c
	gcc -ansi -o 20011602.exe 20011602.c

run:
	./20011602.exe

memcheck:
	gcc -g -o 20011602.exe 20011602.c &&\
	valgrind --tool=memcheck ./20011602.exe

debug:
	gcc -g -o 20011602.exe 20011602.c &&\
	gdb 20011602.exe
