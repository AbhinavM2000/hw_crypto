#include "rsa-core.h"

int
encrypt(int message, int pub_key)
{
    return pow_modulo(pub_key, message, N);
}


int
decrypt(int cipher, int priv_key)
{
    return pow_modulo(priv_key, cipher, N);
}


int
gen_key_pair(int * pub_priv)
{
    int z = (P-1)*(Q-1);
    srand(time(0));
    for (int i=0; i<MAX_TRIAL; ++i)
    {
        //int trial = remainder_get(z, rand(), NULL) ;
        int trial = rand()%z; //recursive function remainder_get causing stack overflow
        if (gcd(trial, z)==1)
        {
            *pub_priv = trial;
            *(pub_priv+1) = inverse_modulo(trial, z);
            return 1; //success
        }
    }
    return 0; //failure
}
