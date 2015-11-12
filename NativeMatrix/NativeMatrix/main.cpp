#include "Matrix.h"
#include <algorithm>

void multiplyCal(jdouble *m, jdouble *thi, jdouble *result, jint mcolumn, jint thisrow, jint thiscolumn) {
	int indexer1 = 0;
	int indexer3 = 0;
	for (int i = 0; i < thisrow; i++) {
		//each column from m
		for (int j = 0; j < mcolumn; j++) {
			//next column in this
			int indexer2 = 0;
			jdouble val = 0;
			for (int k = 0; k < thiscolumn; k++) {
				val += thi[indexer1 + k] * m[indexer2 + j];
				indexer2 += mcolumn;
			}
			result[indexer3++] = val;
		}
		indexer1 += thisrow;
	}
}

void copy(jdouble* target, jdouble* source, jint size) {
	for (jint i = 0; i < size; i++) {
		target[i] = source[i];
	}
}
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

void swap(jdouble* target, jdouble* source) {
	jdouble *temp = target;
	target = source;
	source = temp;
}

JNIEXPORT void JNICALL Java_Matrix_powerC
(JNIEnv *env, jobject, jdoubleArray a, jdoubleArray r, jint pow, jint dimension) {
	jdouble *thi = env->GetDoubleArrayElements(a, 0);
	jint size = dimension*dimension;
	jdouble *temp = new jdouble[size];
	jdouble *result = env->GetDoubleArrayElements(r, 0);

	copy(temp, thi, size);

	while (pow > 1) {
		swap(temp, result);
		multiplyCal(thi, temp, result, dimension, dimension, dimension);
		pow--;
	}

	delete[] temp;
	env->ReleaseDoubleArrayElements(r, result, 0);
	env->ReleaseDoubleArrayElements(a, thi, JNI_ABORT);
}

