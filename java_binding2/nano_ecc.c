#include "nano_ecc.h"
#include <stdlib.h>
#include <string.h>
#include "../inc/ecc.h"

/*
 * Class:     nano_ecc
 * Method:    api_ecc_make_key
 * Signature: ([B[B[B[B)I
 */
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

/*
 * Class:     nano_ecc
 * Method:    ecc_valid_public_key
 * Signature: ([B[B)I
 */
JNIEXPORT jint JNICALL Java_nano_1ecc_ecc_1valid_1public_1key
  (JNIEnv * env, jclass clazz, jbyteArray p_publicKey_x, jbyteArray p_publicKey_y)
  {
    EccPoint p = {0};
    jboolean isCopy;
    jbyte* x = (*env)->GetByteArrayElements(env, p_publicKey_x, &isCopy);
    jbyte* y = (*env)->GetByteArrayElements(env, p_publicKey_y, &isCopy);
    memcpy( p.x, x, 32 );
    memcpy( p.y, y, 32 );
    
    int result = ecc_valid_public_key( &p );

    (*env)->ReleaseByteArrayElements(env, p_publicKey_x, x, 0);
    (*env)->ReleaseByteArrayElements(env, p_publicKey_y, y, 0);

    return result;
  }

/*
 * Class:     nano_ecc
 * Method:    ecdh_shared_secret
 * Signature: ([B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_nano_1ecc_ecdh_1shared_1secret
  (JNIEnv * env, jclass clazz, jbyteArray p_secret, jbyteArray p_publicKey_x, jbyteArray p_publicKey_y, jbyteArray p_privateKey, jbyteArray p_random)
  {
      int result = 0;
      return result;
  }

/*
 * Class:     nano_ecc
 * Method:    ecdsa_sign
 * Signature: ([B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_nano_1ecc_ecdsa_1sign
  (JNIEnv * env, jclass clazz, jbyteArray r, jbyteArray s, jbyteArray p_privateKey, jbyteArray p_random, jbyteArray p_hash)
  {
    uint8_t random_number [32] = {0};
    uint8_t msg_hash [32] = {0};
    uint8_t r_local [32] = {0};
    uint8_t s_local [32] = {0};
    uint8_t privKey [32] = {0};

    jboolean isCopy;
    jbyte* priv = (*env)->GetByteArrayElements(env, p_privateKey, &isCopy);
    jbyte* rnd = (*env)->GetByteArrayElements(env, p_random, &isCopy);
    jbyte* hash = (*env)->GetByteArrayElements(env, p_hash, &isCopy);
    memcpy( privKey, priv, 32 );
    memcpy( random_number, rnd, 32 );
    memcpy( msg_hash, hash, 32 );

    int result = ecdsa_sign( r_local, s_local, privKey, random_number, msg_hash );

    (*env)->SetByteArrayRegion(env, r, 0, 32, (signed char*)r_local);
    (*env)->SetByteArrayRegion(env, s, 0, 32, (signed char*)s_local);
    (*env)->ReleaseByteArrayElements(env, p_privateKey, priv, 0);
    (*env)->ReleaseByteArrayElements(env, p_random, rnd, 0);
    (*env)->ReleaseByteArrayElements(env, p_hash, hash, 0);

    return result;
  }


/*
 * Class:     nano_ecc
 * Method:    ecdsa_verify
 * Signature: ([B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_nano_1ecc_ecdsa_1verify
  (JNIEnv * env, jclass clazz, jbyteArray p_publicKey_x, jbyteArray p_publicKey_y, jbyteArray p_hash, jbyteArray r, jbyteArray s)
  {
    EccPoint p = {0};
    uint8_t msg_hash [32] = {0};
    uint8_t r_local [32] = {0};
    uint8_t s_local [32] = {0};


    jboolean isCopy;
    jbyte* x = (*env)->GetByteArrayElements(env, p_publicKey_x, &isCopy);
    jbyte* y = (*env)->GetByteArrayElements(env, p_publicKey_y, &isCopy);
    jbyte* r_ = (*env)->GetByteArrayElements(env, r, &isCopy);
    jbyte* s_ = (*env)->GetByteArrayElements(env, s, &isCopy);
    jbyte* hash = (*env)->GetByteArrayElements(env, p_hash, &isCopy);
    memcpy( r_local, r_, 32 );
    memcpy( s_local, s_, 32 );
    memcpy( msg_hash, hash, 32 );
    memcpy( p.x, x, 32 );
    memcpy( p.y, y, 32 );
    
    int result = ecdsa_verify( &p, msg_hash, r_local, s_local);

    (*env)->ReleaseByteArrayElements(env, p_publicKey_x, x, 0);
    (*env)->ReleaseByteArrayElements(env, p_publicKey_y, y, 0);
    (*env)->ReleaseByteArrayElements(env, p_hash, hash, 0);
    (*env)->ReleaseByteArrayElements(env, r, r_, 0);
    (*env)->ReleaseByteArrayElements(env, s, s_, 0);

    return result;
  }

