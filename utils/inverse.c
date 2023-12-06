#include <stdio.h>
#include "utils.h"


int
main (int argc, char **argv)
{
    if (argc < 3)
    {
        printf("usage: inverse a b\n");
        exit (1);
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d\n", inverse_modulo(a, b));

    return 0;
}

