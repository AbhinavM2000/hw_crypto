#include <stdio.h>
#include "utils.h"


int
main (int argc, char **argv)
{
    if (argc < 4)
    {
        printf("usage: inverse p a b\n");
        exit (1);
    }
    int p = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    printf("%d\n", pow_modulo(p, a, b));

    return 0;
}

