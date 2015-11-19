#include <iostream>

//Aufgabe 1
template<typename T> T max(T a, T b) {
	return (a < b) ? b : a;
}

//Aufgabe 2
template<int n> struct Fibonacci {
	enum { Result = Fibonacci<n - 2>::Result + Fibonacci<n - 1>::Result };
};

template<> struct Fibonacci<0> {
	enum { Result = 1 };
};

template<> struct Fibonacci<1> {
	enum { Result = 1 };
};

//Aufgabe 3
template<bool, class A, class B> struct IF {
	typedef A RET;
};

template<class A, class B> struct IF<false, A, B> {
	typedef B RET;
};

int main() {
	int i = 3;
	double d = 3.14;

	std::cout << max(2, i) << std::endl;
	std::cout << max<double>(i, d) << std::endl;
	std::cout << Fibonacci<5>::Result << std::endl;

	IF < sizeof(int) < sizeof(long), long, int > ::RET k = 137;

	std::cout << sizeof(i) << std::endl;

	return 0;
}