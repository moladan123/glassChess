CC=g++
CFLAGS=-O3
DEPS = main.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

glassChess: main.o
	$(CC) -o glassChess main.o

clean:
	rm *.o