#ifndef GCD_UTILS
#define GCD_UTILS
#include <stdio.h>
#include <stdlib.h>


/*-----Basic Math-------*/
int min (int a, int b);

int max (int a, int b);

int remainder_get (int , int , int *);

int divisible (int a, int b);

int std_rep (int a, int b);

int pow_modulo (int p, int a, int b);

/*-------GCD related funcs----*/
int gcd (int a, int b);

int inverse_modulo (int a, int b);

struct gcd_coeff
/** Structure that stores
 *      axc_a + bxc_b
 * a and b are treated as symbols.
 * */
{
    int a;
    int b;
    int c_a;
    int c_b;
};
typedef struct gcd_coeff GCD_coeff;

/* operations on GCD_coeff */
int evaluate_gcd_coeff (GCD_coeff *);

void copy_gcd_coeff(GCD_coeff *, GCD_coeff *);

void mult_gcd_coeff(int, GCD_coeff *);

void add_gcd_coeff(GCD_coeff *, GCD_coeff *);

void gcd_coeff (int, int, GCD_coeff *);

/* finding the euclid's algo representation of gcd*/
void print_gcd_coeff (GCD_coeff *coeff);

void gcd_coeff_rec (GCD_coeff *, GCD_coeff *);
#endif
