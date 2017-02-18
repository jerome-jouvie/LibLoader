/**
 * LibLoader
 * Copyright © 2007-2017 Jérôme Jouvie
 *
 * Created on 25 mar. 2007
 * @version file v1.0.0
 *
 * To contact me:
 * jerome.jouvie@gmail.com
 * http://jerome.jouvie.free.fr/
 *
 * INTRODUCTION
 * This project enhance the Java's System.loadLibrary and allows:
 * - library loading without loading dependencies
 * - search libraries from "java.library.path", "sun.jnlp.applet.launcher", "org.lwjgl.librarypath"
 * - library loading from applet
 *
 *
 * GNU LESSER GENERAL PUBLIC LICENSE
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 */

#include <stdio.h>
#include <dlfcn.h>

#include "org_jouvieje_libloader_LibLoaderJNI.h"

#define POINTER_TYPE unsigned long
#define N2J_CAST_PTR(X,Y) (*(Y*)&(X))

const char * NULL_HANDLE = "";
void ThrowNullPointerException(JNIEnv *jenv, const char *message) {
	jclass exception = jenv->FindClass("java/lang/NullPointerException");

	if(exception) {
		jenv->ThrowNew(exception, message);
		jenv->DeleteLocalRef(exception);
	}
}

bool CheckAllocation(JNIEnv *jenv, void *memAllocated) {
	if(memAllocated == NULL) {
		ThrowNullPointerException(jenv, "");
		return false;
	}
	else {
		return true;
	}
}

char *getByteArrayElements(JNIEnv *jenv, jbyteArray array) {
	if(array) {
		const jsize length = jenv->GetArrayLength(array);
		const jbyte *chars = jenv->GetByteArrayElements(array, 0);
		char *copy = new char[length+1];		//Allocate memory
		if(!CheckAllocation(jenv, copy)) {
			return 0;
		}

		for(int i = 0; i < length; i++) {
			copy[i] = (char)chars[i];
		}
		copy[length] = 0;		//End of the string
		jenv->ReleaseByteArrayElements(array, (jbyte *)chars, 0);

		return copy;
	}
	return 0;
}

void releaseByteArrayElements(JNIEnv *jenv, jbyteArray array, const char *chars) {
	if(chars) {
		delete [] chars; //Deallocate memory
		chars = NULL;
	}
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlopen(JNIEnv *jenv, jclass jcls, jbyteArray jfilename, jint jflag) {
	char *filename = getByteArrayElements(jenv, jfilename);
	int flag = (int)jflag;

	void *handle = dlopen(filename, flag);

	if(!handle) {
		printf("dlopen error: %s\n", dlerror());
	}

	releaseByteArrayElements(jenv, jfilename, (const char *)filename);

	POINTER_TYPE jresult/* = 0*/;
	N2J_CAST_PTR(jresult, void *) = handle;
	return (jlong)jresult;
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlerror(JNIEnv *jenv, jclass jcls) {
	char *result = dlerror();
	if (!result) {
		return NULL;
	}
	return jenv->NewStringUTF(result);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlsym(JNIEnv *jenv, jclass jcls, jlong jhandle, jbyteArray jsymbol) {
	if(!jhandle) {
		ThrowNullPointerException(jenv, NULL_HANDLE);
		return 0;
	}
	void *handle = *(void **)&jhandle;
	char *symbol = getByteArrayElements(jenv, jsymbol);

	void *result = dlsym(handle, symbol);

	releaseByteArrayElements(jenv, jsymbol, (const char *)symbol);

	POINTER_TYPE jresult/* = 0*/;
	N2J_CAST_PTR(jresult, void *) = result;
	return (jlong)jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_libloader_LibLoaderJNI_dlclose(JNIEnv *jenv, jclass jcls, jlong jhandle) {
	if(!jhandle) {
		ThrowNullPointerException(jenv, NULL_HANDLE);
		return 0;
	}
	void *handle = *(void **)&jhandle;

	int result = dlclose(handle);
	return (jint)result;
}

