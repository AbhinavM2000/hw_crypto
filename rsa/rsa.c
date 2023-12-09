#include "rsa-core.h"
#include <string.h>

int
main(int argc, char ** argv)
{
    if (argc==1)
    {
        printf("usage: ./rsa <option>\n");
        printf("optinons are:\
                \n\tg: generate key pair\
                \n\te: encrypt\
                \n\td: decrypt\n");
        exit(1);
    }
    char option = *argv[1];
    switch (option)
    {
        case 'g':
            printf("generating key pair...\n");
            int pub_priv[2];
            if (gen_key_pair(pub_priv))
            {
                printf("pub_key\t%d\n", pub_priv[0]);
                printf("N\t%d\n", N);
                printf("priv_key (secret)\t%d\n", pub_priv[1]);
            }
            else
            {
                printf("key generation failed!! Try again.\n");
                exit(1);
            }
            break;
        case 'e':
            printf("enter message to encrypt (number < %d)\n>> ", N);
            int message=0;
            int pub_key=1;
            scanf("%d", &message);
            printf("enter encryption key (pub key)\n>> ");
            scanf("%d", &pub_key);
            printf("%d\n", encrypt(message, pub_key));
            break;
        case 'd':
            printf("enter cipher to decrypt (number < %d)\n>> ", N);
            int cipher=0;
            int priv_key=1;
            scanf("%d", &cipher);
            printf("enter decription key (priv key)\n>> ");
            scanf("%d", &priv_key);
            printf("%d\n", decrypt(cipher, priv_key));
            break;
        default:
            fprintf(stderr, "invalid option %c\n!!", option);
            exit(1);
    }

    return 0;
}
