#include "Matrix.h"

JNIEXPORT void JNICALL Java_Matrix_multiplyC
(JNIEnv *env, jobject, jdoubleArray a, jdoubleArray b, jdoubleArray r, jint mcolumn, jint thisrow, jint thiscolumn) {
	jdouble *m = env->GetDoubleArrayElements(b, 0);
	jdouble *thi = env->GetDoubleArrayElements(a, 0);
	jdouble *result = env->GetDoubleArrayElements(r, 0);

	multiplyCal(m, thi, result, mcolumn, thisrow, thiscolumn);

	env->ReleaseDoubleArrayElements(r, result, 0);
	env->ReleaseDoubleArrayElements(a, thi, JNI_ABORT);
	env->ReleaseDoubleArrayElements(b, m, JNI_ABORT);
}

void multiplyCal(jdouble *m, jdouble *thi, jdouble *result, jint mcolumn, jint thisrow, jint thiscolumn) {
	for (int i = 0; i < thisrow; i++) {
		//each column from m
		for (int j = 0; j < mcolumn; j++) {
			//next column in this
			jdouble val = 0;
			for (int k = 0; k < thiscolumn; k++) {
				val += thi[i*thisrow + k] * m[k* mcolumn + j];
			}
			result[i* mcolumn + j] = val;
		}
	}
}