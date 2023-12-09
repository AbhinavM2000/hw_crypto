#ifndef RSA_CORE
#define RSA_CORE
#include "../utils/utils.h"
#include <time.h>

//TODO: create prime number generator
// use different P Q for each enc.
#define P 11
#define Q 13
#define N P*Q
#define MAX_TRIAL 100

int encrypt(int message, int pub_key);

int decrypt(int cipher, int priv_key);

int gen_key_pair(int *);

#endif
