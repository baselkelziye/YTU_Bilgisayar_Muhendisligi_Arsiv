CC = gcc
CFLAGS =-I.
DEPS = gamefield.h gameplay.h account.h
OBJ = main.o gamefield.o gameplay.o account.c

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $<

project: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	-rm *.o $(objects)
