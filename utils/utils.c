#include "utils.h"

int
min (int a, int b)
{
    return (a<b) ? a : b;
}


int
max (int a, int b)
{
    return (b<a) ? a : b;
}


int
remainder_get (int a, int b, int* q)
/** Recursive function to find the remainder
 * when b is divided by a. The third argument
 * is a pointer to an intger which will
 * point to quotient + initial value of *q
 */
{
    if (a==0)
    {
        fprintf(stderr, "division by zero encountered!\n");
        exit(1);
    }
    if (b==0)
        return 0;
    else if (a>b)
        return b;
    else
    {
        if (q!=NULL) *q = *q+1;
        return remainder_get(a, b-a, q);
    }
}


int
divisible (int a, int b)
/** Check if b is divisible by a*/
{
    int q = 0;
    return remainder_get(a,b, &q)==0 ? 1 : 0;
}



int
gcd(int a, int b)
/** Recursive function to compute
 * gcd of a and b.
 */
{
    int aa, bb, q;
    q = 0;
    aa = min(a, b);
    bb = max(a, b);
    if (divisible(aa, bb))
        return aa;
    else
        return gcd(remainder_get(aa, bb, &q), aa);
}


void
gcd_coeff(int a, int b, GCD_coeff *coeff)
/** Finds the representation of gcd as
 * gcd(a,b) = axk_1 + bxk_2, where k1, k2\in
 * \mathbb{Z}. The coefficient k1 and k2 are
 * stored in the GCD_coeff object pointed by
 * coeff.*/
{
    if (coeff==NULL)
    {
        coeff = (GCD_coeff *)malloc(sizeof(GCD_coeff *));
    }
    int aa, bb;
    aa = min(a, b);
    bb = max(a, b);
    int q = 0;
    int r;
    r = remainder_get(aa, bb, &q);
    /* representation of a = k1xa + k2xb*/
    coeff->a = aa;
    coeff->b = bb;
    coeff->c_a = 1;
    coeff->c_b = 0;
    if (r==0) // aa is the gcd
        return;
    GCD_coeff prev_coeff;
    copy_gcd_coeff(&prev_coeff, coeff);
    coeff->c_a = -q;
    coeff->c_b = 1;
    gcd_coeff_rec(coeff, &prev_coeff);
}


void gcd_coeff_rec(GCD_coeff *coeff, GCD_coeff *prev_coeff)
/** recursive function called by gcd_coeff function*/
{
    int a, b, r;
    int q = 0;
    a = evaluate_gcd_coeff(coeff);
    b = evaluate_gcd_coeff(prev_coeff);
    r = remainder_get(a, b, &q);
    if (r==0) // a is the gcd
        return;
    GCD_coeff temp_prev_coeff;
    copy_gcd_coeff(&temp_prev_coeff, prev_coeff);
    copy_gcd_coeff(prev_coeff, coeff);
    mult_gcd_coeff(-q, coeff);
    add_gcd_coeff(coeff, &temp_prev_coeff);
    gcd_coeff_rec(coeff, prev_coeff);
}


int
inverse_modulo(int a, int b)
/**
 * Finds inverse of a modulo b
 * Returns 0 if inverse does not exist
 */
{
    // get the representation of a modulo b
    a = remainder_get(b, a, (int *)NULL);
    GCD_coeff coeff;
    gcd_coeff(a, b, &coeff);
    if (evaluate_gcd_coeff(&coeff)!=1)
        return 0;
    return coeff.c_a;
}


int
pow_modulo(int p, int a, int b)
/**
 * Computes a^p mod b in the representation
 * that lies between 0 and b-1
 **/
{
    if (p==0) return 1;
    int q=0;
    int rem = remainder_get(2, p, &q);
    int ans = pow_modulo(q, a, b);
    ans *= ans;
    ans = remainder_get(b, ans, NULL);
    if (rem)
    {
        ans *=a;
        ans = remainder_get(b, ans, NULL);
    }
    return ans;
}


void
print_gcd_coeff(GCD_coeff *coeff)
/** Function to print the gcd_coeff representation. */
{
    if (coeff == NULL)
    {
        fprintf(stderr, "NULL pointer!\n");
        return;
    }
    int r = coeff->a * coeff->c_a;
    r += coeff->b * coeff->c_b;
    printf("(%d)x%d + (%d)x%d = %d\n",
            coeff->c_a, coeff->a,
            coeff->c_b, coeff->b, r);
}


int
evaluate_gcd_coeff (GCD_coeff * coeff)
/** evaluate the expression represented by
 * GCD_coeff object pointed to by coeff */
{
    return coeff->a*coeff->c_a + coeff->b*coeff->c_b;
}


void
copy_gcd_coeff(GCD_coeff *new, GCD_coeff *old)
/** copy old to new */
{
    new->a = old->a;
    new->b = old->b;
    new->c_a = old->c_a;
    new->c_b = old->c_b;
}


void
mult_gcd_coeff (int factor, GCD_coeff *coeff)
/** multiply coefficients by scalar*/
{
    coeff->c_a *= factor;
    coeff->c_b *= factor;
}


void
add_gcd_coeff (GCD_coeff *coeff, GCD_coeff *delta)
/** add two delta to coeff */
{
    if (coeff->a!=delta->a || coeff->b!=delta->b)
    {
        fprintf(stderr, "invalid gcd coeffs sum!\n");
        exit (1);
    }
    coeff->c_a += delta->c_a;
    coeff->c_b += delta->c_b;
}
