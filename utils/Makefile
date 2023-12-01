CC=gcc
FLAGS=-Wall
DEBUG=-g

all: utils
	$(CC) $(FLAGS) gcd.c utils.o -o gcd

debug: utils_debug
	$(CC) $(FLAGS) $(DEBUG) gcd.c utils.o -o gcd

utils:
	$(CC) $(FLAGS) -c utils.c -o utils.o

utils_debug:
	$(CC) $(FLAGS) $(DEBUG) -c utils.c -o utils.o

clean:
	rm -rf utils.o gcd
