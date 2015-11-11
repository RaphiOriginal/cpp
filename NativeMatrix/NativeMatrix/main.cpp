#include "Matrix.h"
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

void copy(jdouble* target, jdouble* source, jint size) {
	for (jint i = 0; i < size; i++) {
		target[i] = source[i];
	}
}
void swap(jdouble* target, jdouble* source){
	jdouble *temp = target;
	target = source;
	source = temp;
	delete[] temp;
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

JNIEXPORT void JNICALL Java_Matrix_powerC
(JNIEnv *env, jobject, jdoubleArray a, jdoubleArray r, jint pow, jint dimension) {
	jdouble *thi = env->GetDoubleArrayElements(a, 0);
	jint size = dimension*dimension;
	jdouble *temp = new jdouble[size];
	jdouble *result = env->GetDoubleArrayElements(r, 0);

	copy(temp, thi, size);

	while (pow > 1) {
		multiplyCal(thi, temp, result, dimension, dimension, dimension);
		swap(temp, result);
		pow--;
	}
	
	delete[] temp;
	env->ReleaseDoubleArrayElements(r, result, 0);
	env->ReleaseDoubleArrayElements(a, thi, JNI_ABORT);
}

