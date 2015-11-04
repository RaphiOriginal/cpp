#include "Matrix.h"

JNIEXPORT void JNICALL Java_Matrix_multiplyC
(JNIEnv *env, jobject, jdoubleArray a, jdoubleArray b, jdoubleArray r, jint ii, jint jj, jint k) {
	jboolean isCopyB;
	jdouble *m = env->GetDoubleArrayElements(r, &isCopyB);
	jboolean isCopyA;
	jdouble *thi = env->GetDoubleArrayElements(r, &isCopyA);
	jboolean isCopyR;
	jdouble *result = env->GetDoubleArrayElements(r, &isCopyR);

	for (jint i = 0; i < k; i++) {
		for (jint j = 0; j < ii; j++) {
			result[i] = result[i] + thi[j*ii + (i % ii)] * m[i%jj + j];
		}
	}

	env->ReleaseDoubleArrayElements(r, result, JNI_ABORT);
	env->ReleaseDoubleArrayElements(a, thi, JNI_ABORT);
	env->ReleaseDoubleArrayElements(b, m, JNI_ABORT);
}