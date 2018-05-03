#include "nano_ecc.h"
#include <stdlib.h>
#include <string.h>
#include "../inc/ecc.h"

JNIEXPORT jint JNICALL Java_nano_1ecc_api_1ecc_1make_1key
    (JNIEnv * env, jclass clazz, jbyteArray p_publicKey_x , 
    jbyteArray p_publicKey_y , jbyteArray p_privateKey , jbyteArray p_random)
{
    EccPoint p = {0};
    uint8_t privKey [32] = {0};
    uint8_t rnd [32] = {0};

    jboolean isCopy;
    jbyte* b = (*env)->GetByteArrayElements(env, p_random, &isCopy);
    memcpy( rnd, b, 32 );

    int result = ecc_make_key(&p, privKey, rnd);

    (*env)->ReleaseByteArrayElements(env, p_random, b, 0);
    (*env)->SetByteArrayRegion(env, p_publicKey_x, 0, 32, (signed char*)p.x);
    (*env)->SetByteArrayRegion(env, p_publicKey_y, 0, 32, (signed char*)p.y);
    (*env)->SetByteArrayRegion(env, p_privateKey, 0, 32, (signed char*)privKey);
    

    return result;
}
