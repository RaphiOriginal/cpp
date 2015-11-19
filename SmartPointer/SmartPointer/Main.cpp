#include <iostream>
#include "SmartPointer.h"

struct Test {
	int a;
	int b;
	Test(int _a, int _b) {
		a = _a;
		b = _b;
	}
};

int main() {
	char *p = new char('t');
	SmartPointer<char> test(p);

	SmartPointer<char> test2(test);

	char *p2 = new char('a');
	SmartPointer<char> other(p2);

	test = other;

	std::cout << *test << std::endl;
	std::cout << *test2 << std::endl;
}