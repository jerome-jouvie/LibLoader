/* DO NOT EDIT THIS FILE - it is machine generated */
#include "jni.h"
/* Header for class org_jouvieje_libloader_LibLoaderJNI */

#ifndef _Included_org_jouvieje_libloader_LibLoaderJNI
#define _Included_org_jouvieje_libloader_LibLoaderJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_jouvieje_libloader_LibLoaderJNI
 * Method:    dlopen
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlopen
  (JNIEnv *, jclass, jbyteArray, jint);

/*
 * Class:     org_jouvieje_libloader_LibLoaderJNI
 * Method:    dlerror
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlerror
  (JNIEnv *, jclass);

/*
 * Class:     org_jouvieje_libloader_LibLoaderJNI
 * Method:    dlsym
 * Signature: (J[B)J
 */
JNIEXPORT jlong JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlsym
  (JNIEnv *, jclass, jlong, jbyteArray);

/*
 * Class:     org_jouvieje_libloader_LibLoaderJNI
 * Method:    dlclose
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlclose
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif