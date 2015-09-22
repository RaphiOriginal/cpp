#include <iostream>
#define MAX(a, b) ((a) < (b)? (b) : (a))
#define MAX_NUMBER 100
#define A char
#define B short

using namespace std;

int main() {
	//a)
	//erwartetes Resultat 11
	int x = 5, y = 10;
	int z = MAX(x++, y++);
	cout << z << endl;

	//b)
	//erwarteter datentyp float
	float data[MAX_NUMBER];
	auto v3 = data[0];
	cout << typeid(v3).name() << endl;

	//c)
	cout << typeid(A).name() << "\t" << sizeof(A) << ((sizeof(A) > 1) ? " Bytes" : " Byte") << "\n" << typeid(B).name() << "\t" << sizeof(B) << ((sizeof(B) > 1) ? " Bytes" : " Byte") << endl;

	//d)
	char s[] = "Hello World";
	int uppercase = 0;
	int len = sizeof(s);
	for (auto l : s) {
		if (isupper(l)) ++uppercase;
	}
	cout << uppercase << " uppercase letters in: " << s << endl;
}