#include <stdio.h>
#include "utils.h"


int
main (int argc, char **argv)
{
    if (argc < 3)
    {
        printf("usage: gcd a b\n");
        exit (1);
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    //printf("%d\n", gcd(a, b));
    GCD_coeff coeff;
    gcd_coeff(a, b, &coeff);
    print_gcd_coeff(&coeff);

    return 0;
}

