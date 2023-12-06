CC=gcc
FLAGS=-Wall
DEBUG=-g

all: gcd inverse

gcd: utils
	$(CC) $(FLAGS) gcd.c utils.o -o gcd

gcd-debug: utils_debug
	$(CC) $(FLAGS) $(DEBUG) gcd.c utils.o -o gcd

inverse: utils
	$(CC) $(FLAGS) inverse.c utils.o -o inverse

inverse-debug: utils-debug
	$(CC) $(FLAGS) $(DEBUG) inverse.c utils.o -o inverse

utils:
	$(CC) $(FLAGS) -c utils.c -o utils.o

utils-debug:
	$(CC) $(FLAGS) $(DEBUG) -c utils.c -o utils.o

clean:
	rm -rf utils.o gcd inverse
