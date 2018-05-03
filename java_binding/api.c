#include "api.h"

#include <string.h>
#include <stdio.h>

void printArray( char* name, uint8_t* array)
{
    printf("%s :", name );
    for(int i = 0 ; i < 32; i++)
        printf("%x", array[i]);
    printf("\n");
    for(int i = 0 ; i < 32; i++)
        printf("%u", array[i]);
    printf("\n");
}

int api_ecc_make_key( char pk_x[32], char pk_y[32], char p_privateKey[32], char p_random[32])
{
    EccPoint p = {0};
    printf("randomness: %s\n", (char*)p_random );
    printf("y-value: %s\n", (char*)p.y );
    printf("x-value: %s\n", (char*)p.x );
    uint8_t priv[33] = {0};
    uint8_t rnd[33] = {0};

    memcpy( rnd, p_random, 32);
    printArray("priv", priv);
    printArray("rnd", rnd );

    int result = ecc_make_key( &p, priv/*(uint8_t*) p_privateKey*/, rnd /*(uint8_t*) p_random*/);
    memcpy( pk_x, p.x, 32);
    memcpy( pk_y, p.y, 32);
    
    printArray("x", p.x);
    printArray("y", p.y );

    printArray("priv", priv);
    printArray("rnd", rnd );

    return result;
}