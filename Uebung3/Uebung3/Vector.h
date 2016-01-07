#pragma once

#include "Operator.cpp"
#include <iostream>

template <typename Left, typename Op, typename Right, typename T> struct Expr {
	Left m_left;
	Right m_right;
	Expr(Left t1, Right t2) : m_left(t1), m_right(t2) { }
	T operator[](int i) { return Op::apply(m_left[i], m_right[i]); }
};

template<typename Op, typename Right, typename T> struct Expr <double, Op, Right, T> {
	double m_left;
	Right m_right;
	Expr(double t1, Right t2) : m_left(t1), m_right(t2) { }
	T operator[](int i) { return Op::apply(m_left, m_right[i]); }
};

template<typename Left, typename Op, typename T> struct Expr <Left, Op, double, T> {
	Left m_left;
	double m_right;
	Expr(Left t1, double t2) : m_left(t1), m_right(t2) { }
	T operator[](int i) { return Op::apply(m_left[i], m_right); }
};

template <typename T>
struct Array {
	T *m_data;
	int m_N;
	// constructor
	Array(T *data, int N) : m_data(data), m_N(N) { }
	~Array() {
		//delete[] m_data; throws exception for some reason
	}
	// assign an expression to the array
	template <typename Left, typename Op, typename Right> void operator=(Expr<Left, Op, Right, T> expr) {
		for (int i = 0; i < m_N; ++i) {
			m_data[i] = expr[i];
		}
	}

	/*template <typename Left, typename Op, typename Right> void operator=(Expr<Left, Mul<T>, Right, T> expr) {
	m_N = 1;
	delete[] m_data;
	m_data[m_N];
	for (int i = 0; i < b.m_N; i++) {
	m_data[0] += expr[i];
	}
	}*/

	T operator[](int i) {
		return m_data[i];
	}

	void print() const {
		int l = 0;
		std::cout << "[";
		if (m_N > 0) std::cout << m_data[l++];
		while (l < m_N) std::cout << ", " << m_data[l++];
		std::cout << "]" << std::endl;
	}
};


template <typename Left, typename T> Expr<Left, Plus<T>, Array<T>, T> operator+(Left a, Array<T> b) {
	return Expr<Left, Plus<T>, Array<T>, T>(a, b);
}

template <typename Left, typename T, typename ELeft, typename EOp, typename ERight> Expr<Left, Plus<T>, Expr<ELeft, EOp, ERight, T>, T> operator+(Left a, Expr<ELeft, EOp, ERight, T> b) {
	return Expr<Left, Plus<T>, Expr<ELeft, EOp, ERight, T>, T>(a, b);
}

template <typename Left, typename T> Expr<Left, Minus<T>, Array<T>, T> operator-(Left a, Array<T> b) {
	return Expr<Left, Minus<T>, Array<T>, T>(a, b);
}

template <typename Left, typename T, typename ELeft, typename EOp, typename ERight> Expr<Left, Minus<T>, Expr<ELeft, EOp, ERight, T>, T> operator-(Left a, Expr<ELeft, EOp, ERight, T> b) {
	return Expr<Left, Minus<T>, Expr<ELeft, EOp, ERight, T>, T>(a, b);
}

template <typename T> Expr<double, MulSkalar<T>, Array<T>, T> operator*(double a, Array<T> b) {
	return Expr<double, MulSkalar<T>, Array<T>, T>(a, b);
}

template <typename T, typename ELeft, typename EOp, typename ERight> Expr<double, MulSkalar<T>, Expr<ELeft, EOp, ERight, T>, T> operator*(double a, Expr<ELeft, EOp, ERight, T> b) {
	return Expr<double, MulSkalar<T>, Expr<ELeft, EOp, ERight, T>, T>(a, b);
}

template <typename T> Expr<Array<T>, MulSkalar<T>, double, T> operator*(Array<T> a, double b) {
	return Expr<Array<T>, MulSkalar<T>, double, T>(a, b);
}

template <typename T, typename ELeft, typename EOp, typename ERight> Expr<Expr<ELeft, EOp, ERight, T>, MulSkalar<T>, double, T> operator*(Expr<ELeft, EOp, ERight, T> a, double b) {
	return Expr<Expr<ELeft, EOp, ERight, T>, MulSkalar<T>, double, T >(a, b);
}

template <typename Left, typename T> T operator^(Left a, Array<T> b) {
	T sum = a[0] * b[0];
	for (int i = 1; i < b.m_N; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}
