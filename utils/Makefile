CC=gcc
FLAGS=-Wall
DEBUG=-g

all: gcd inverse power_modulo

gcd: utils
	$(CC) $(FLAGS) gcd.c utils.o -o gcd

gcd-debug: utils_debug
	$(CC) $(FLAGS) $(DEBUG) gcd.c utils.o -o gcd

inverse: utils
	$(CC) $(FLAGS) inverse.c utils.o -o inverse

inverse-debug: utils-debug
	$(CC) $(FLAGS) $(DEBUG) inverse.c utils.o -o inverse

power_modulo: utils
	$(CC) $(FLAGS) power_modulo.c utils.o -o power_modulo

power_modulo-debug: utils-debug
	$(CC) $(FLAGS) $(DEBUG) power_modulo.c utils.o -o power_modulo

utils:
	$(CC) $(FLAGS) -c utils.c -o utils.o

utils-debug:
	$(CC) $(FLAGS) $(DEBUG) -c utils.c -o utils.o

clean:
	rm -rf utils.o gcd inverse power_modulo
