#ifndef _JAVA_BINDING_API_
#define _JAVA_BINDING_API_
#endif
#define ECC_CURVE 32
#include "../inc/ecc.h"


/* ecc_make_key() function.
Create a public/private key pair.

You must use a new nonpredictable random number to generate each new key pair.

Outputs:
    p_publicKey  - Will be filled in with the point representing the public key.
    p_privateKey - Will be filled in with the private key.

Inputs:
    p_random - The random number to use to generate the key pair.

Returns 1 if the key pair was generated successfully, 0 if an error occurred. If 0 is returned,
try again with a different random number.
*/
int api_ecc_make_key(char* pk_x, char* pk_y, char* p_privateKey, char* p_random);