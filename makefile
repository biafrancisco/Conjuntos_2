CC = gcc
CFLAGS = -Wall
ARGS = auxiliar.c conjunto.c main.c

all: 
	$(CC) $(ARGS) $(CFLAGS) -o teste

clean:
	rm -f *.o *.a

purge: clean
	rm -f teste