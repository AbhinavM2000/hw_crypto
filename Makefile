CC=gcc
FLAGS=-Wall
DEBUG=-g

all: gcd inverse power_modulo rsa

rsa: utils rsa-core
	$(CC) $(FLAGS) ./rsa/rsa.c ./rsa/rsa-core.o ./utils/utils.o -o rsa-bin

rsa-core:
	$(CC) $(FLAGS) -c ./rsa/rsa-core.c -o ./rsa/rsa-core.o

rsa_debug: utils-debug rsa-core_debug
	$(CC) $(FLAGS) $(DEBUG) ./rsa/rsa.c ./rsa/rsa-core.o ./utils/utils.o -o rsa-bin

rsa-core_debug:
	$(CC) $(FLAGS) $(DEBUG) -c ./rsa/rsa-core.c -o ./rsa/rsa-core.o

gcd: utils
	$(CC) $(FLAGS) ./utils/gcd.c ./utils/utils.o -o gcd

gcd-debug: utils_debug
	$(CC) $(FLAGS) $(DEBUG) ./utils/gcd.c ./utils/utils.o -o gcd

inverse: utils
	$(CC) $(FLAGS) ./utils/inverse.c ./utils/utils.o -o inverse

inverse-debug: utils-debug
	$(CC) $(FLAGS) $(DEBUG) ./utils/inverse.c ./utils/utils.o -o inverse

power_modulo: utils
	$(CC) $(FLAGS) ./utils/power_modulo.c ./utils/utils.o -o power_modulo

power_modulo-debug: utils-debug
	$(CC) $(FLAGS) $(DEBUG) ./utils/power_modulo.c ./utils/utils.o -o power_modulo

utils: ./utils/utils.c
	$(CC) $(FLAGS) -c ./utils/utils.c -o ./utils/utils.o

utils-debug:
	$(CC) $(FLAGS) $(DEBUG) -c ./utils/utils.c -o ./utils/utils.o

clean:
	rm -rf ./utils/utils.o gcd inverse power_modulo ./rsa/rsa-core.o rsa-bin

.PHONY: all utils rsa clean
