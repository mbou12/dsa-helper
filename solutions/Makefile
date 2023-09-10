CC=gcc
CFLAGS=-g -std=c99 -Wall -Wextra -pedantic

k-subsets: k-subsets.c
	$(CC) $(CFLAGS) -c k-subsets.c
	$(CC) $(CFLAGS) -o k-subsets k-subsets.o

clean:
	rm *.o; rm k-subsets;

